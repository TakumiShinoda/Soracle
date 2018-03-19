// you can know operating time by (SUPPLYER_RESULT_FREQ * SUPPLYER_GET_FREQ) ms
#define SUPPLYER_RESULT_FREQ 1000
#define SUPPLYER_GET_FREQ 1 //ms

float volt;
float voltRatio = 3.28 / 1024;
float sumVolt;

float preVolt = 3.15;

float getVolt(){
  int c = 0;
  while(c < SUPPLYER_RESULT_FREQ){
    sumVolt += analogRead(7) * voltRatio;
    c++;
    delay(SUPPLYER_GET_FREQ);
  }
  volt = sumVolt / SUPPLYER_RESULT_FREQ * 2;
  sumVolt = 0;

  return volt;
}

