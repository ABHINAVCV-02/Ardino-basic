int ledPin = 8;
int touchpin = 3;
// pin for the LED

void setup()

{

Serial.begin(9600);

pinMode(ledPin, OUTPUT);

pinMode(touchpin, INPUT);

}

void loop()

{

int ctsValue = digitalRead(touchpin);

if (ctsValue == HIGH)

{

digitalWrite(ledPin, HIGH);
//delay(10000) ;
Serial.println("TOUCHED");

}

else{

digitalWrite(ledPin,LOW);

Serial.println("not touched");

}
}
