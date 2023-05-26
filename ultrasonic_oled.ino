#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
 
#define trigPin 9
#define echoPin 8
 
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
 
void setup() {
Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //initialize with the I2C addr 0x3C (128x64)
display.clearDisplay();
 
}
 
void loop() {
float duration;
float distance_cm;
float distance_in;
 
digitalWrite(trigPin, LOW); 
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
 
duration = pulseIn(echoPin, HIGH);
 
distance_cm = (duration/2) / 29.1;
distance_in = (duration/2) / 73.914;
 
display.setCursor(30,0); //oled display
display.setTextSize(1);
display.setTextColor(WHITE);
display.println("Range Finder");
 
display.setCursor(10,20); //oled display
display.setTextSize(2);
display.setTextColor(WHITE);
display.println(distance_cm);
display.setCursor(90,20);
display.setTextSize(2);
display.println("cm");
 
display.setCursor(10,45); //oled display
display.setTextSize(2);
display.setTextColor(WHITE);
display.println(distance_in);
display.setCursor(90,45);
display.setTextSize(2);
display.println("in");
display.display();
 
delay(500);
display.clearDisplay();
 
Serial.println(distance_cm);
Serial.println(distance_in);
}
