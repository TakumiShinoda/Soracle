#include <DigiUSB.h>

#define DECISION 6.10
#define SHUTTERPIN 0

double analogValue;
int digitalValue;
boolean finalShutter = false;
double volt;
double voltRatio = 5 / 1024;

double preVolt = 3.15;

void setup() {
  pinMode(1, OUTPUT);
  pinMode(SHUTTERPIN, INPUT);
  digitalWrite(1, LOW);

  DigiUSB.begin();
}

void loop() {
  analogValue = analogRead(1);
  digitalValue = digitalRead(SHUTTERPIN);
  volt = analogValue * 2 * 5 / 1024;

//  DigiUSB.println(digitalRead(SHUTTERPIN)); //for debug
//  DigiUSB.println(volt); //for debug
  
  if(volt < float(DECISION) || digitalValue || finalShutter){
    if(digitalValue){
      finalShutter = true;
    }
    digitalWrite(1, HIGH);
  }else{
    digitalWrite(1, LOW);
  }
  DigiUSB.delay(1000);
}
