void heartMove_Beat (){
  Serial.println("heartMove_beat");
  //unsigned long currentMillis = millis();
  matrix.setRotation(3);

  ///*
  Serial.println("heartMove_beat");
  matrix.setRotation(3);
  matrix.clear();
  matrix.drawBitmap(0, 0, heartMove_1_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0 , heartMove_1_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);


  matrix.clear();
  matrix.drawBitmap(0, 0, heartMove_2_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, heartMove_2_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);

  matrix.clear();
  matrix.drawBitmap(0, 0, heartMove_3_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, heartMove_3_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);

  matrix.clear();
  matrix.drawBitmap(0, 0, heartMove_4_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, heartMove_4_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);

  matrix.clear();
  matrix.drawBitmap(0, 0, heartMove_5_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, heartMove_5_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);

  matrix.clear();
  matrix.drawBitmap(0, 0, heartMove_6_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, heartMove_6_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);

  matrix.clear();
  matrix.drawBitmap(0, 0, heartMove_7_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, heartMove_7_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);

  matrix.clear();
  matrix.drawBitmap(0, 0, heartMove_8_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, heartMove_8_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);

  matrix.clear();
  matrix.drawBitmap(0, 0, heartMove_9_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, heartMove_9_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);

  matrix.clear();
  matrix.drawBitmap(0, 0, heartMove_10_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0 , heartMove_10_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);

  matrix.clear();
  matrix.drawBitmap(0, 0, indicator_11_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0 , indicator_11_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);
}
