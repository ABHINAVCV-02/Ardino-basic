
const int ir = 2;     // the number of the ir sensor
const int motor =  8;      // the number of the motor

// variables will change:
int irState = 0;         // variable for reading the ir status

void setup() {
  // initialize the motor pin as an output:
  pinMode(motor, OUTPUT);
  // initialize the ir pin as an input:
  pinMode(ir, INPUT);
}

void loop() {
  // read the state of the ir value:
  irState = digitalRead(ir);

  // check if the ir is pressed. If it is, the ir is HIGH:
  if (ir == HIGH) {
    // turn motor on:
    digitalWrite(motor, HIGH);
  } else {
    // turn motor off:
    digitalWrite(motor, LOW);
  }
}
