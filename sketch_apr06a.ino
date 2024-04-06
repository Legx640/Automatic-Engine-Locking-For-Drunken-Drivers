#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);//RS,EN,D4,D5,D6,D7
#define gas 7
#define buzzer 8
#define relay 6
int alc=1;
void setup() 
{
  Serial.begin(9600);       // initialize serial communications at 9600 bps:
  pinMode(gas,INPUT);
  pinMode(relay,OUTPUT);
  pinMode(buzzer,OUTPUT); 
  digitalWrite(relay,HIGH);
  digitalWrite(buzzer,LOW);
  lcd.begin(16, 2);//initializing LCD
  lcd.setCursor(0,0);
  lcd.print("Alcohol");
  lcd.setCursor(0,1);
  lcd.print("Detection");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Press");
  lcd.setCursor(7,0);
  lcd.print("key....");
  delay(1000);  
}
void loop() 
{
 alc=digitalRead(gas);
 if(alc==HIGH)
 { 
  digitalWrite(buzzer,LOW);
    lcd.clear(); 
    digitalWrite(relay,LOW);
    lcd.setCursor(0,0);
    lcd.print(" Safe ");
    lcd.setCursor(0,1);
    lcd.print("Drive... ");
    delay(2000);   
    lcd.clear();  
    digitalWrite(buzzer,LOW);                      
 }
 else
 {
  digitalWrite(relay,HIGH);
  digitalWrite(buzzer,HIGH);
  lcd.setCursor(0,0);
  lcd.print("ALCOHOL");
  lcd.setCursor(0,1);
  lcd.print("DETECTED");
  delay(5000);
  lcd.clear(); 
   lcd.setCursor(0,0);
    lcd.print(" Press");
    lcd.setCursor(0,1);
    lcd.print("key..."); 
 }
}
