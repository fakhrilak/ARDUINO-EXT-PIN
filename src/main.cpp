#include <Arduino.h>
#include "pinControll.h"
void setup()
{
  Serial.begin(9600);
}
  

void loop()
{
  controll_OUTPUT(7);
  int sensorA  = controll_Input(6);
  Serial.println(sensorA);
  if(sensorA < 4){
    controll_OUTPUT(5);
  }
}

