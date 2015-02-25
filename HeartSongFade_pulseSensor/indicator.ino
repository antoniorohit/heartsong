// Write animation for indicator_Beat
void indicator_Beat (){
  Serial.println("indicator_beat");
  //unsigned long currentMillis = millis();
  matrix.setRotation(3);

  Serial.println("indicator_beat");
  matrix.setRotation(3);
  matrix.clear();
  matrix.drawBitmap(0, 0, indicator_1_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0 , indicator_1_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);

  matrix.clear();
  matrix.drawBitmap(0, 0, indicator_2_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, indicator_2_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);

  matrix.clear();
  matrix.drawBitmap(0, 0, indicator_3_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, indicator_3_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);

  matrix.clear();
  matrix.drawBitmap(0, 0, indicator_4_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, indicator_4_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);

  matrix.clear();
  matrix.drawBitmap(0, 0, indicator_5_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, indicator_5_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);

  matrix.clear();
  matrix.drawBitmap(0, 0, indicator_6_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, indicator_6_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);

  matrix.clear();
  matrix.drawBitmap(0, 0, indicator_7_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, indicator_7_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);

  matrix.clear();
  matrix.drawBitmap(0, 0, indicator_8_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, indicator_8_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);

  matrix.clear();
  matrix.drawBitmap(0, 0, indicator_9_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, indicator_9_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);

  matrix.clear();
  matrix.drawBitmap(0, 0, indicator_10_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0 , indicator_10_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);

  matrix.clear();
  matrix.drawBitmap(0, 0, indicator_11_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0 , indicator_11_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(60);
}
//*/


/* 
 if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, indicator_1_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0 , indicator_1_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 
 else if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, indicator_2_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, indicator_2_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, indicator_3_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, indicator_3_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, indicator_4_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, indicator_4_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, indicator_5_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, indicator_5_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, indicator_6_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, indicator_6_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, indicator_7_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, indicator_7_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, indicator_8_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, indicator_8_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, indicator_9_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, indicator_9_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, indicator_10_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0 , indicator_10_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, indicator_11_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0 , indicator_11_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, indicator_12_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0 , indicator_12_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, indicator_13_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0 , indicator_13_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, indicator_14_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0 , indicator_14_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else{
 matrix.clear();
 matrix.drawBitmap(0, 0, indicator_1_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0 , indicator_1_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 previousMillis = currentMillis;  // save the last time animation changed
 }
 }
 */

/*
 // Run Calibration animation
 long time = millis();
 
 if ((time % 1000) < 60){
 matrix.clear();
 matrix.drawBitmap(0, 0, calib_1_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0 , calib_1_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else if (((time % 1000) >= 60) && ((time % 1000) < 120)){
 matrix.clear();
 matrix.drawBitmap(0, 0, calib_2_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, calib_2_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 else if (((time % 1000) >= 120) && ((time % 1000) < 180)){
 matrix.clear();
 matrix.drawBitmap(0, 0, calib_3_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, calib_3_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 else if (((time % 1000) >= 180) && ((time % 1000) < 240)){
 matrix.clear();
 matrix.drawBitmap(0, 0, calib_4_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, calib_4_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 else if (((time % 1000) >= 300) && ((time % 1000) < 360)){
 matrix.clear();
 matrix.drawBitmap(0, 0, calib_5_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, calib_5_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 else if (((time % 1000) >= 360) && ((time % 1000) < 420)){
 matrix.clear();
 matrix.drawBitmap(0, 0, calib_6_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, calib_6_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 else if (((time % 1000) >= 480) && ((time % 1000) < 540)){
 matrix.clear();
 matrix.drawBitmap(0, 0, calib_7_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, calib_7_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 else if (((time % 1000) >= 600) && ((time % 1000) < 660)){
 matrix.clear();
 matrix.drawBitmap(0, 0, calib_8_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, calib_8_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 else if (((time % 1000) >= 720) && ((time % 1000) < 800)){
 matrix.clear();
 matrix.drawBitmap(0, 0, calib_2_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, calib_2_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 else if (((time % 1000) >= 860) && ((time % 1000) < 920)){
 matrix.clear();
 matrix.drawBitmap(0, 0, calib_3_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, calib_3_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 //stopped here
 else if (((time % 1000) >= 180) && ((time % 1000) < 240)){
 matrix.clear();
 matrix.drawBitmap(0, 0, calib_4_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, calib_4_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 else if (((time % 1000) >= 300) && ((time % 1000) < 360)){
 matrix.clear();
 matrix.drawBitmap(0, 0, calib_5_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, calib_5_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 else if (((time % 1000) >= 360) && ((time % 1000) < 420)){
 matrix.clear();
 matrix.drawBitmap(0, 0, calib_6_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, calib_6_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 else if (((time % 1000) >= 480) && ((time % 1000) < 540)){
 matrix.clear();
 matrix.drawBitmap(0, 0, calib_7_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, calib_7_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 else if (((time % 1000) >= 600) && ((time % 1000) < 660)){
 matrix.clear();
 matrix.drawBitmap(0, 0, calib_8_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, calib_8_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 */









