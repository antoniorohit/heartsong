void diamond_Beat (){
  Serial.println("diamond_beat");
  //unsigned long currentMillis = millis();
  matrix.setRotation(3);

  ///*
  Serial.println("diamond_beat");
  matrix.setRotation(3);
  matrix.clear();
  matrix.drawBitmap(0, 0, diamond_1_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0 , diamond_1_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);


  matrix.clear();
  matrix.drawBitmap(0, 0, diamond_2_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, diamond_2_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);

  matrix.clear();
  matrix.drawBitmap(0, 0, diamond_3_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, diamond_3_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);

  matrix.clear();
  matrix.drawBitmap(0, 0, diamond_4_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, diamond_4_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);

  matrix.clear();
  matrix.drawBitmap(0, 0, diamond_5_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, diamond_5_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);

  matrix.clear();
  matrix.drawBitmap(0, 0, diamond_6_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, diamond_6_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);

  matrix.clear();
  matrix.drawBitmap(0, 0, diamond_7_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, diamond_7_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);

  matrix.clear();
  matrix.drawBitmap(0, 0, diamond_8_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, diamond_8_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);

  matrix.clear();
  matrix.drawBitmap(0, 0, diamond_9_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, diamond_9_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);

  matrix.clear();
  matrix.drawBitmap(0, 0, diamond_1_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0 , diamond_1_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(30);
}

