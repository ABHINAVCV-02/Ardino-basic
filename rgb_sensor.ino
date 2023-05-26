#include <Wire.h>

#define S0 4
#define S1 5
#define S2 6
#define S3 7

#define sensorOut 8
int redfrequency = 0;
int greenfrequency = 0;
int bluefrequency = 0;

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  // Setting frequency-scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  Serial.begin(9600);
}

void loop() {
  // Setting red filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // Reading the output frequency
  redfrequency = pulseIn(sensorOut, LOW);
  delay(100);

  // Setting Green filtered photodiodes to be read
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  greenfrequency = pulseIn(sensorOut, LOW);
  delay(100);

  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  bluefrequency = pulseIn(sensorOut, LOW);
  delay(100);

  if (redfrequency > 25 && redfrequency < 281) {
    Serial.println("RED COLOUR");
  }
  else if (bluefrequency > 25 && bluefrequency < 220) {
    Serial.println("BLUE COLOUR");
  }
  else if (greenfrequency > 25 && greenfrequency < 340) {
    Serial.println("GREEN COLOUR");
  }
  else {
    Serial.println("NO COLOUR DETECTION");
  }
}
