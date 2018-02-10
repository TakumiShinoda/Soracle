#include <stdio.h>
#include <string.h>
#include "FS.h"
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WebServer.h>

#define PIC_ADDRESS 0x10
#define PIC_MEMORY_ADDRESS 0x02
#define WIFI_ID_MAX 5
#define WIFI_TRYTIME 15

ESP8266WiFiMulti wifi;
ESP8266WebServer server(80);
String serialStr = "";

void getRequest(){
  Serial.println("recieve request");
  server.send(200, "text/html", index_html());
}

void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.println("start");
  
  bool res = SPIFFS.begin();
  if(!res){
    Serial.println("SPIFFS Fail");
    return;
  }
  Dir dir = SPIFFS.openDir("/");
  Serial.println("SPIFFS setup success!");

  server.on("/", getRequest);
  server.begin();
  
  while(true){
    Serial.println("->");
    while(serialStr == ""){
     serialStr = Serial.readStringUntil('\r'); 
    }

    if(serialStr.indexOf("list") == 0){
      for(int i = 0; i < 5; i++){
        String setting = readSetting(i + 1);
        Serial.println(String(i + 1) + ": <SSID>" + split(setting, ' ', 0) + " <PASS>" + split(setting, ' ', 1));
      }
    }else if(serialStr.indexOf("wifi") == 0){
      String id = split(serialStr, ' ', 1);
      String ssid = split(serialStr, ' ', 2);
      String pass = split(serialStr, ' ', 3);
  
      if(id != "" && ssid != "" && pass != "" && id.toInt() >= 1 && id.toInt() <= 5){
        writeSetting(id.toInt(), ssid +" "+ pass);
        Serial.println("write complete");
      }else{
        Serial.println("wifi <number> <ssid> <pass>"); 
      }
    }else if(serialStr.indexOf("connect") == 0){
      WiFi.mode(WIFI_STA);

      for(int i = 0; i < 5; i++){
        String setting = readSetting(i + 1);
        char ssid[128];
        char pass[128];
        split(setting, ' ', 0).toCharArray(ssid, 128);
        split(split(setting, ' ', 1), '\n', 0).toCharArray(pass, 128);

        Serial.println("ssid: " + String(ssid));
        Serial.println("pass: " + String(pass));
        
        wifi.addAP(ssid, pass);
      }

      int tryCnt = 0;
      while(wifi.run() != WL_CONNECTED && tryCnt < WIFI_TRYTIME){
        Serial.print("・");
        tryCnt += 1;
        delay(1000);
      }
      Serial.println("/n");

      if(tryCnt >= WIFI_TRYTIME){
        Serial.println("connect fail. reboot & connect again.");
        Serial.println("five seconds after reboot");
        wait4reboot(5);
        
        return;
      }

      if(wifi.run() == WL_CONNECTED){
        //WiFi.printDiag(Serial);
        Serial.println("IP address: ");
        Serial.println(WiFi.localIP());
      }
    }else if(serialStr.indexOf("server") == 0){
      Serial.println("Web Server opened");
      break;
    }else{
      Serial.println("no command");
    }

    serialStr = "";
  }
}

void loop() {
  server.handleClient();
}


