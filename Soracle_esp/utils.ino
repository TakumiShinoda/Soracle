String split(String data, char separator, int index){
  int maxIndex = data.length() - 1;
  int j = 0;
  String chunkVal = "";

  for (int i = 0; i <= maxIndex && j <= index; i++){
    chunkVal.concat(data[i]);

    if (data[i] == separator){
        j++;

        if (j > index){
            chunkVal.trim();
            return chunkVal;
        }
        chunkVal = "";
    }
    
    else if ((i == maxIndex) && (j < index)){
        chunkVal = "";
        return chunkVal;
    }
  }   
}

String postData(String url){
  HTTPClient http;

  http.begin(url);
  int httpCode = http.GET();
  String result = "";

  if (httpCode < 0){
    result = http.errorToString(httpCode);
  }else if (http.getSize() < 0){
    result = "over length";
  }else{
    result = http.getString();
  }
  http.end();

  return result;
}

void wait4reboot(int s){
  int cnt = 0;
  
  while(cnt < s){
    Serial.print("・");
    delay(1000);
    cnt += 1;
  }

  ESP.restart();
}



