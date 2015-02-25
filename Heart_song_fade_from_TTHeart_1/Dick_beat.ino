// Write animation for Dick1_Beat
void dick_beat (){
  Serial.println("dick_beat");
  // unsigned long currentMillis = millis();
  matrix.setRotation(3);

  Serial.println("dick_beat");
  matrix.setRotation(3);
  matrix.clear();
  matrix.drawBitmap(0, 0, dick_1_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0 , dick_1_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(120);


  matrix.clear();
  matrix.drawBitmap(0, 0, dick_2_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, dick_2_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(120);

  matrix.clear();
  matrix.drawBitmap(0, 0, dick_3_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, dick_3_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(120);

  matrix.clear();
  matrix.drawBitmap(0, 0, dick_4_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, dick_4_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);

  matrix.clear();
  matrix.drawBitmap(0, 0, dick_5_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, dick_5_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);

  matrix.clear();
  matrix.drawBitmap(0, 0, dick_6_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, dick_6_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);

  matrix.clear();
  matrix.drawBitmap(0, 0, dick_1_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0 , dick_1_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);
}
