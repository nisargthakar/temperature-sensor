int fanpin = 6;
int fanspeed = 0;
int C = 0;
int temppin = A0;

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() 
{
  lcd.begin(16, 2);
  pinMode(fanpin,OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  int j=analogRead(temppin);
  //Serial.println(j);
  C = (5.0*j*100.0)/1024;
  Serial.print("Temperature in Celcius: ");
  Serial.println(C);

  fanspeed = map(C, 30, 70, 0, 255);
  Serial.print("fan speed = ");
  Serial.println(fanspeed);
  analogWrite(fanpin, fanspeed);
  int k = map(fanspeed, 0, 255, 0, 100);
  lcd.print("TEMP in C = ");
  lcd.print(C);
  lcd.setCursor(0,1);
  lcd.print("fan speed = ");
  lcd.print(k);
  lcd.print("%");
  delay(300);
}
