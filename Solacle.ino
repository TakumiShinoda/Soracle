#include <stdio.h>
#include <string.h>
#include "FS.h"
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WebServer.h>

#define WIFI_ID_MAX 5
#define WIFI_TRYTIME 15

#define MODE_PIN 12
#define SHUTTER_PIN 16

ESP8266WiFiMulti wifi;
ESP8266WebServer server(80);

void getRequest() {
  Serial.println("recieve request");
  server.send(200, "text/html", index_html());
}

void setup() {
  Serial.begin(9600);
  delay(2000);
  bool res = SPIFFS.begin();
  if (!res) {
    Serial.println("\nSPIFFS Fail");
    Serial.print("rebooting");
    wait4reboot(5);
  }
  Dir dir = SPIFFS.openDir("/");
  Serial.println("\nSPIFFS setup success!");

  WiFi.disconnect();
  WiFi.mode(WIFI_OFF);
  Serial.println("initialized WiFi");

  server.on("/", getRequest);
  server.begin();
  Serial.print("Start ");

  pinMode(MODE_PIN, INPUT);

  if (digitalRead(MODE_PIN) == HIGH) {
    Serial.println("Admin mode");
    modeAdmin();
  } else if (digitalRead(MODE_PIN) == LOW) {
    Serial.println("Normal mode");
    modeNormal();
  }
}

void loop() {
  String serialStr = "";

  serialStr = Serial.readStringUntil('\r');
  server.handleClient();

  if (serialStr != "") {
    if(serialStr.indexOf("restart") == 0){
      Serial.println("rebooting");
      wait4reboot(2);
    }
  }
}
