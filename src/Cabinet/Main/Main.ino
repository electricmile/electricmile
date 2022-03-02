#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <GPRS_Shield_Arduino.h>
#include <SoftwareSerial.h>
#include <Wire.h>

#define PIN_TX    8    /* rx of Arduino (connect tx of gprs to this pin) */
#define PIN_RX    7   /* tx of Arduino (connect rx of gprs to this pin) */
#define BAUDRATE  9600
#define PHONE_NUMBER "7024966746"
#define MESSAGE_LENGTH 160

char message[MESSAGE_LENGTH]; /* buffer for storing message */
char phone[16];         /* buffer for storing phone number */
char datetime[24];        /* buffer for storing phone number */
int8_t messageIndex = 0;

SoftwareSerial GPS_SoftSerial(4, 3);/* (Rx, Tx) */
TinyGPSPlus gps;
volatile float minutes, seconds;
volatile int degree, secs, mins;

GPRS Sim900_test(PIN_TX, PIN_RX, BAUDRATE);
const int8_t lm35_pin = A1;

void setup() {
  Serial.begin(9600); /* Define baud rate for serial communication */
  GPS_SoftSerial.begin(9600); /* Define baud rate for software serial communication */
  Serial.begin(9600); /* Define baud rate for serial communication */
  pinMode(4, OUTPUT);
  while (!Sim900_test.init()) /* Sim card and signal check, also check if module connected */
  {
    delay(1000);
    Serial.println("SIM900 initialization error");
  }
  Serial.println("SIM900 initialization success");
  memset(message, 0, 160);
}

void loop() {
  GPS();
  delay(100);
  GSM_1();
  delay(100);
}
  
