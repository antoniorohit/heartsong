
// Write animation for Heart_Beat
void Heart_Beat (){
  Serial.println("Heart_beat");
  // unsigned long currentMillis = millis();
  matrix.setRotation(3);

  Serial.println("Heart_beat");
  matrix.setRotation(3);
  matrix.clear();
  matrix.drawBitmap(0, 0, Heart_1_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0 , Heart_1_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);


  matrix.clear();
  matrix.drawBitmap(0, 0, Heart_2_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, Heart_2_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);

  matrix.clear();
  matrix.drawBitmap(0, 0, Heart_3_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, Heart_3_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);

  matrix.clear();
  matrix.drawBitmap(0, 0, Heart_4_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, Heart_4_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);

  matrix.clear();
  matrix.drawBitmap(0, 0, Heart_5_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, Heart_5_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);

  matrix.clear();
  matrix.drawBitmap(0, 0, Heart_6_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, Heart_6_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);

  matrix.clear();
  matrix.drawBitmap(0, 0, Heart_7_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, Heart_7_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);

  matrix.clear();
  matrix.drawBitmap(0, 0, Heart_8_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, Heart_8_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);

  matrix.clear();
  matrix.drawBitmap(0, 0, Heart_9_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, Heart_9_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);

  matrix.clear();
  matrix.drawBitmap(0, 0, Heart_10_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0 , Heart_10_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);

  matrix.clear();
  matrix.drawBitmap(0, 0, Heart_11_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0 , Heart_11_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);
}

/* 
 if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, Heart_1_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0 , Heart_1_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 
 else if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, Heart_2_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, Heart_2_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, Heart_3_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, Heart_3_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, Heart_4_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, Heart_4_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, Heart_5_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, Heart_5_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, Heart_6_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, Heart_6_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, Heart_7_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, Heart_7_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, Heart_8_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, Heart_8_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, Heart_9_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, Heart_9_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, Heart_10_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0 , Heart_10_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, Heart_11_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0 , Heart_11_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, Heart_12_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0 , Heart_12_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, Heart_13_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0 , Heart_13_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, Heart_14_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0 , Heart_14_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else{
 matrix.clear();
 matrix.drawBitmap(0, 0, Heart_1_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0 , Heart_1_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 previousMillis = currentMillis;  // save the last time animation changed
 }
 */

/*
 // Run Heartration animation
 long time = millis();
 
 if ((time % 1000) < 60){
 matrix.clear();
 matrix.drawBitmap(0, 0, Heart_1_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0 , Heart_1_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else if (((time % 1000) >= 60) && ((time % 1000) < 120)){
 matrix.clear();
 matrix.drawBitmap(0, 0, Heart_2_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, Heart_2_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 else if (((time % 1000) >= 120) && ((time % 1000) < 180)){
 matrix.clear();
 matrix.drawBitmap(0, 0, Heart_3_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, Heart_3_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 else if (((time % 1000) >= 180) && ((time % 1000) < 240)){
 matrix.clear();
 matrix.drawBitmap(0, 0, Heart_4_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, Heart_4_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 else if (((time % 1000) >= 300) && ((time % 1000) < 360)){
 matrix.clear();
 matrix.drawBitmap(0, 0, Heart_5_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, Heart_5_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 else if (((time % 1000) >= 360) && ((time % 1000) < 420)){
 matrix.clear();
 matrix.drawBitmap(0, 0, Heart_6_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, Heart_6_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 else if (((time % 1000) >= 480) && ((time % 1000) < 540)){
 matrix.clear();
 matrix.drawBitmap(0, 0, Heart_7_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, Heart_7_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 else if (((time % 1000) >= 600) && ((time % 1000) < 660)){
 matrix.clear();
 matrix.drawBitmap(0, 0, Heart_8_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, Heart_8_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 else if (((time % 1000) >= 720) && ((time % 1000) < 800)){
 matrix.clear();
 matrix.drawBitmap(0, 0, Heart_2_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, Heart_2_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 else if (((time % 1000) >= 860) && ((time % 1000) < 920)){
 matrix.clear();
 matrix.drawBitmap(0, 0, Heart_3_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, Heart_3_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 //stopped here
 else if (((time % 1000) >= 180) && ((time % 1000) < 240)){
 matrix.clear();
 matrix.drawBitmap(0, 0, Heart_4_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, Heart_4_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 else if (((time % 1000) >= 300) && ((time % 1000) < 360)){
 matrix.clear();
 matrix.drawBitmap(0, 0, Heart_5_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, Heart_5_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 else if (((time % 1000) >= 360) && ((time % 1000) < 420)){
 matrix.clear();
 matrix.drawBitmap(0, 0, Heart_6_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, Heart_6_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 else if (((time % 1000) >= 480) && ((time % 1000) < 540)){
 matrix.clear();
 matrix.drawBitmap(0, 0, Heart_7_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, Heart_7_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 else if (((time % 1000) >= 600) && ((time % 1000) < 660)){
 matrix.clear();
 matrix.drawBitmap(0, 0, Heart_8_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, Heart_8_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 */









