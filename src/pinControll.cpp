#include "pinControll.h"
int mux0array[16];
void controll_OUTPUT(int i){
  pinMode(CONTROL0, OUTPUT);
  pinMode(CONTROL1, OUTPUT);
  pinMode(CONTROL2, OUTPUT);
  pinMode(CONTROL3, OUTPUT);
  pinMode(A0, OUTPUT);
  analogWrite(A0,255); 
  digitalWrite(CONTROL0, (i&15)>>3); 
  digitalWrite(CONTROL1, (i&7)>>2);  
  digitalWrite(CONTROL2, (i&3)>>1);  
  digitalWrite(CONTROL3, (i&1));
  delay(10);
}
int controll_Input(int i){
  pinMode(CONTROL0, OUTPUT);
  pinMode(CONTROL1, OUTPUT);
  pinMode(CONTROL2, OUTPUT);
  pinMode(CONTROL3, OUTPUT);
  pinMode(A0, OUTPUT);
  analogWrite(A0,HIGH); 
  digitalWrite(CONTROL0, (i&15)>>3); 
  digitalWrite(CONTROL1, (i&7)>>2);  
  digitalWrite(CONTROL2, (i&3)>>1);  
  digitalWrite(CONTROL3, (i&1));
  int k = 0;
  int array[9];
  while (k<10)
  {
    array[k] = analogRead(0);
    k = k+1;
  }
  int value=0;
  for(int j = 0; j<10;j++){
      value = value + array[j];
  }
  int result = value/11;
  mux0array[i] = result/100;
  return mux0array[i];
}