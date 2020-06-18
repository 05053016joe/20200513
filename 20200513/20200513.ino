#include <Ultrasonic.h>
#include <LiquidCrystal.h>
#define TRIGGER_PIN 3
#define ECHO_PIN 4
const int usr_btn = 6;
const int rs = 17, en = 16, d4 = 15, d5 = 14, d6 = 13, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
void setup() {
Serial.begin(9600);
 digitalWrite(usr_btn, HIGH);
attachInterrupt(usr_btn, pin_change, RISING); 
 lcd.begin(16, 2);
}
void loop(){

delay(1000);
}

void pin_change(void) 
{ 
   lcd.clear();
float cmMsec, inMsec;
long microsec = ultrasonic.timing();
cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM); // 計算距離，單位: 公分
inMsec = ultrasonic.convert(microsec, Ultrasonic::IN); // 計算距離，單位: 英吋
Serial.print("MS: "); Serial.print(microsec);
Serial.print(", CM: "); Serial.print(cmMsec);
Serial.print(", IN: "); Serial.println(inMsec);
lcd.print(" CM: ");
lcd.print(cmMsec);
} 
 
