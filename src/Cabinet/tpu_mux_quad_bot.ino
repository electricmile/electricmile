#define IN_1 11
#define IN_2 12
#define IN_3 13
#define OUTS_1 2
#define OUTS_2 3
#define OUTS_3 4
#define OUTS_4 5
#define OUTL_1 6
#define OUTL_2 7
#define OUTL_3 8
#define OUTL_4 9
// Set one is A4, Set two is A5

int sw1, sw2, sw3;

void setup()
{
    Serial.begin(9600);
    Serial.println("Starting TPU MUX version 1 //Two line switching");
    pinMode(IN_1, INPUT_PULLUP);
    pinMode(IN_2, INPUT_PULLUP);
    pinMode(IN_3, INPUT_PULLUP);

    pinMode(OUTS_1, OUTPUT);
    pinMode(OUTS_2, OUTPUT);
    pinMode(OUTS_3, OUTPUT);
    pinMode(OUTS_4, OUTPUT);

    pinMode(OUTL_1, OUTPUT);
    pinMode(OUTL_2, OUTPUT);
    pinMode(OUTL_3, OUTPUT);
    pinMode(OUTL_4, OUTPUT);

    // Flush the outputs. Defalut state off = low
    digitalWrite(OUTS_1, HIGH);
    digitalWrite(OUTS_2, HIGH);
    digitalWrite(OUTS_3, HIGH);
    digitalWrite(OUTS_4, HIGH);

    digitalWrite(OUTL_1, LOW);
    digitalWrite(OUTL_2, LOW);
    digitalWrite(OUTL_3, LOW);
    digitalWrite(OUTL_4, LOW);
}

void loop()
{
    reads();
    //  Serial.print("INPUT 1 state: ");
    //  Serial.println(sw1);
    //  Serial.print("INPUT 2 state: ");
    //  Serial.println(sw2);
    delay(10);
    CH0();
    delay(5);

    Serial.println("OUTPUT CH1 is ON");
    while (sw1 == 1 && sw2 == 1 && sw3 == 1) // Reset state. CH1 is ON
    {
        CH1();
        delay(5);
    }

    while (sw1 == 0 && sw2 == 1 && sw3 == 1) // First Switch is pressed. CH2 is ON
    {
        CH2();
        delay(5);
    }
    while (sw1 == 1 && sw2 == 0 && sw3 == 1) // Second Switch is pressed. CH3 is ON
    {
        CH3();
        delay(5);
    }
    while (sw1 == 1 && sw2 == 1 && sw3 == 0) // Third Switch is pressed. CH4 is ON
    {
        CH4();
        delay(5);
    }
}
void CH0()
{
    digitalWrite(OUTS_1, HIGH);
    digitalWrite(OUTS_2, HIGH);
    digitalWrite(OUTS_3, HIGH);
    digitalWrite(OUTS_4, HIGH);

    digitalWrite(OUTL_1, LOW);
    digitalWrite(OUTL_2, LOW);
    digitalWrite(OUTL_3, LOW);
    digitalWrite(OUTL_4, LOW);
    delay(5);
    reads();
}
void CH1()
{
    digitalWrite(OUTS_1, LOW);
    digitalWrite(OUTS_2, HIGH);
    digitalWrite(OUTS_3, HIGH);
    digitalWrite(OUTS_4, HIGH);

    digitalWrite(OUTL_1, HIGH);
    digitalWrite(OUTL_2, LOW);
    digitalWrite(OUTL_3, LOW);
    digitalWrite(OUTL_4, LOW);
    delay(5);
    reads();
}
void CH2()
{
    digitalWrite(OUTS_1, HIGH);
    digitalWrite(OUTS_2, LOW);
    digitalWrite(OUTS_3, HIGH);
    digitalWrite(OUTS_4, HIGH);

    digitalWrite(OUTL_1, LOW);
    digitalWrite(OUTL_2, HIGH);
    digitalWrite(OUTL_3, LOW);
    digitalWrite(OUTL_4, LOW);
    delay(5);
    reads();
}
void CH3()
{
    digitalWrite(OUTS_1, HIGH);
    digitalWrite(OUTS_2, HIGH);
    digitalWrite(OUTS_3, LOW);
    digitalWrite(OUTS_4, HIGH);

    digitalWrite(OUTL_1, LOW);
    digitalWrite(OUTL_2, LOW);
    digitalWrite(OUTL_3, HIGH);
    digitalWrite(OUTL_4, LOW);
    delay(5);
    reads();
}
void CH4()
{
    digitalWrite(OUTS_1, HIGH);
    digitalWrite(OUTS_2, HIGH);
    digitalWrite(OUTS_3, HIGH);
    digitalWrite(OUTS_4, LOW);

    digitalWrite(OUTL_1, LOW);
    digitalWrite(OUTL_2, LOW);
    digitalWrite(OUTL_3, LOW);
    digitalWrite(OUTL_4, HIGH);
    delay(5);
    reads();
}
void reads()
{
    sw1 = digitalRead(IN_1);
    sw2 = digitalRead(IN_2);
    sw3 = digitalRead(IN_3);
}
