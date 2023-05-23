int led1 = 8;
void setup() {

  pinMode(led1, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(led1, 1);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(led1, LOW);    // turn the LED off by making the voltage LOW
  delay(10000);                       // wait for a second
}
