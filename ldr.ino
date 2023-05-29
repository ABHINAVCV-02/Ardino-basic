

int ldr = 7;
int x;
int led =8 ;

void setup() 
{
  Serial.begin(9600);
  pinMode(7, INPUT);
  pinMode(8, OUTPUT);
}

void loop()
{
  x = digitalRead(7);
  Serial.println(x);

  if(x == HIGH)
  {
    digitalWrite(8, HIGH);
  }
  if(x == LOW)
  {
    digitalWrite(8, LOW);
  }

}
