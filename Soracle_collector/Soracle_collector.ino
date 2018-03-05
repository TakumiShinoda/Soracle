void setup(){
  Serial.begin(9600);

  pinMode(9, OUTPUT);
  digitalWrite(9, LOW);
}

void loop(){
  String serialStr = "";

  serialStr = Serial.readStringUntil('\r');
  if(serialStr != ""){
    if(serialStr.indexOf("shutdown") == 0){
      digitalWrite(9, HIGH);
    }
  }

  Serial.println(getVolt());

  delay(100);
}
