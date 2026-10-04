#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int trigPin = 9;
const int echoPin = 10;
const int buzzerPin = 11;
const int relayPin = 12;
const int ledPin = 13;
long duration;
int distance;
int threshold = 20; 
void setup() {
   // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.backlight();
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  lcd.print("Distance:");
  
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin,HIGH);
distance = duration * 0.034 / 2;

lcd.setCursor(0,1);
lcd.print(distance);
lcd.print("cm   ");

if (distance < threshold){
  digitalWrite(buzzerPin, HIGH);
  digitalWrite(relayPin, HIGH);
  digitalWrite(ledPin, HIGH);
  lcd.setCursor(0,0);
  lcd.print("WARNING !");
} else{
  digitalWrite(buzzerPin, LOW);
  digitalWrite(relayPin, LOW);
  digitalWrite(ledPin, LOW);
  lcd.setCursor(0,0);
  lcd.print("Distance:          ");
  
}
delay(500);
}
