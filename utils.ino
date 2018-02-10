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

void wait4reboot(int s){
  int cnt = 0;
  
  while(cnt < s){
    Serial.print("・");
    delay(1000);
    cnt += 1;
  }

  ESP.restart();
}



