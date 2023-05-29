int motor= 8;
int ir = 10;
int irstate = LOW;  // LOW MEANS NO OBSTACLE

void setup() {
  pinMode(motor, OUTPUT);
  pinMode(ir, INPUT);
  Serial.begin(9600);
}

void loop() {
  irstate = digitalRead(ir);

  if (irstate == HIGH) {
    Serial.println("Stop something is ahead!!");
    digitalWrite(motor, 0);
  }
  else {
    Serial.println("Path is clear");
    digitalWrite(motor, 1);
  }
  delay(200);
}
