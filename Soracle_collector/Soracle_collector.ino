// GETFREQ can tell us real-time delay to send POST by (GETFREQ * (LOOPFREQ + {function getVolt's operating time})) ms
#define LOOPFREQ 10
#define GETFREQ 60

double lowBattV = 6.15;
int lowBattCnt = 0;
#define LOWBATTLIMMIT 5

String serialStr = "";
double battV = 0;
int cnt = 0;

void setup(){
  Serial.begin(4800); // arduino pro mini's bug (it means 9600bps)

  pinMode(9, OUTPUT);
  digitalWrite(9, LOW);
}

void loop(){
  serialStr = Serial.readStringUntil('\r');
  battV = getVolt();
  
  if(serialStr != ""){
    if(serialStr.indexOf("shutdown") == 0){
      digitalWrite(9, HIGH);
    }
  }

  if(battV < LOWBATTLIMMIT){
    digitalWrite(9, HIGH);
  }

  if(cnt < GETFREQ){
    cnt += 1;
  }else{
    Serial.println("powerV " + String(battV));
    cnt = 0;
  }

  delay(LOOPFREQ);
}
