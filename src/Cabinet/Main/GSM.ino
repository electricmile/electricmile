void GSM_1() {
  int16_t temp_adc_val;
  float temp_val;
  temp_adc_val = analogRead(lm35_pin);  /* Read temperature from LM35 */
  temp_val = (temp_adc_val * 4.88);
  temp_val = (temp_val / 10);
  Serial.print("Temperature = ");
  Serial.print(temp_val);
  Serial.print(" Degree Celsius\n");
  if (temp_val > 35)
  {
    Serial.println("Need to cool down");
    Serial.println("Calling to inform");
    Sim900_test.callUp(PHONE_NUMBER); /* Call */
    delay(25000);
    Sim900_test.hangup(); /* Hang up the call */
    int8_t count = 0;
    messageIndex = Sim900_test.isSMSunread(); /* Check if new message available */
    while ( (messageIndex < 1) && !strstr( message, "Cool down") )  /* No new unread message */
    {
      if (count == 5)
      {
        messageIndex = Sim900_test.isSMSunread();
        break;
      }
      count++;
      delay(5000);
      messageIndex = Sim900_test.isSMSunread();
    }
    while (messageIndex > 0 ) /* New unread message available */
    {
      Sim900_test.readSMS(messageIndex, message, MESSAGE_LENGTH, phone, datetime);  /* Read message */
      if (strstr( message, "Cool down"))
      {
        Serial.println("Turning fan ON");
        digitalWrite(4, HIGH);
        memset(message, 0, 160);
      }
      messageIndex = Sim900_test.isSMSunread();
    }
    delay(10000);
  }
  else
  {
    Serial.println("Everything is fine");
    digitalWrite(4, LOW);
  }
  delay(3000);
}
