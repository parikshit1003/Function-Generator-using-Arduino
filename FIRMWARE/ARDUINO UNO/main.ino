#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,7,6,5,4);

int F;
float ts = 0.0; 
float T = 0.0;
int sine;
int trig;
float t,k;
int D; 

void setup(){
pinMode(10, OUTPUT); 
pinMode(3, OUTPUT);
pinMode(8, OUTPUT);
pinMode(2, INPUT_PULLUP);
attachInterrupt(digitalPinToInterrupt(2),func,RISING);
lcd.begin(16,4);
lcd.setCursor(0,0);
lcd.print("FREQUENCY:");
lcd.setCursor(0,2);    
lcd.print("FREQ Square:"); 
lcd.setCursor(0,3);
lcd.print("AMPLITUDE: ");

}          


void func(){ 
   D = analogRead(A1);
   lcd.setCursor(12,2);
   lcd.print(145000.0/(2*D));
   while(1){
      digitalWrite(8, HIGH);
      delay(D);
      digitalWrite(8, LOW);
      delay(D);
   }
} 

void loop(){ 
F = analogRead(A0)/100;
lcd.setCursor(11,0); 
lcd.print(F);
k = analogRead(A2)/204.0;
lcd.setCursor(12,3);
lcd.print(k);
T = 1.0/F;
ts = T/500.0;
for(int i=0; i<500; i++){
   t = i*ts;
   sine = (int)(127.0*(sin(2*3.14*F*t)+1.0));
   if(i<250){
      trig = i;
   }
   else{
      trig = 500 - i;
   }
   analogWrite(10, sine);
   analogWrite(3, trig);   
   delayMicroseconds(ts*700000); 
}
      
}