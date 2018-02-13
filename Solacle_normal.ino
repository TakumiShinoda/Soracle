void modeNormal (){
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
  }

  if(wifi.run() == WL_CONNECTED){
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
  }
  
  Serial.println("Web Server opened");
}

