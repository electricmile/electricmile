int in1, out1, in2, out2;

void setup() 
{
  Serial.begin(9600);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
}

void loop() 
{
  in1 = digitalRead(4);
  in2 = digitalRead(5);
  Serial.println("Reading");
  delay(200);
  if (in1 == 0)
  {
    digitalWrite(7, LOW);
    Serial.println("LED 1 ON");
    delay(200);
    do
    {
      out1 = 0;
      in1 = digitalRead(4);
      in2 = digitalRead(5);
      Serial.println("Waiting for switch");
      delay(200);
    }while(in1 == 1);
    digitalWrite(7, HIGH);
    Serial.println("LED 1 OFF");
  }
  if (in2 == 0)
  {
    digitalWrite(8, LOW);
    Serial.println("LED 2 ON");
    delay(200);
    do
    {
      out2 = 0;
      in2 = digitalRead(5);
      Serial.println("Waiting for switch");
      delay(200);
    }while(in2 == 1);
    digitalWrite(8, HIGH);
    Serial.println("LED 2 OFF");
  }
}
