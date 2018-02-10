void removeFile(String fn){
  bool fd = SPIFFS.remove(fn);
}

String readSetting(int num){
  File fd = SPIFFS.open("/setting"+ String(num) +".txt", "r");
  if(!fd){
    return "";
  }
  String line = fd.readStringUntil('\r');
  fd.close();

  return line;
}

void writeSetting(int num, String str){
  File fd = SPIFFS.open("/setting"+ String(num) +".txt", "w");
  if (!fd) {
    Serial.println("open error: /setting" + String(num) +".txt");
  }
  fd.print(str);  
  fd.close();
}


