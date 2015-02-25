
// Write animation for gem_Beat
void gem_Beat (){
  Serial.println("gem_beat");
  //unsigned long currentMillis = millis();
  matrix.setRotation(3);
  //buttonState = digitalRead(6);

  matrix.setRotation(3);
  matrix.clear();
  matrix.drawBitmap(0, 0, gem_1_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0 , gem_1_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(40);

  //break if button pressed
  //    if((buttonState == 0)){ //have to make it so that if button state goes from 1 to 0...
  //      break;
  //    }
  matrix.clear();
  matrix.drawBitmap(0, 0, gem_2_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, gem_2_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(40);


  matrix.clear();
  matrix.drawBitmap(0, 0, gem_3_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, gem_3_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(40);

  matrix.clear();
  matrix.drawBitmap(0, 0, gem_4_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, gem_4_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(40);

  matrix.clear();
  matrix.drawBitmap(0, 0, gem_5_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, gem_5_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(40);

  matrix.clear();
  matrix.drawBitmap(0, 0, gem_6_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, gem_6_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(40);

  matrix.clear();
  matrix.drawBitmap(0, 0, gem_7_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, gem_7_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(40);

  matrix.clear();
  matrix.drawBitmap(0, 0, gem_8_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, gem_8_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(40);

  matrix.clear();
  matrix.drawBitmap(0, 0, gem_9_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0, gem_9_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(40);

  matrix.clear();
  matrix.drawBitmap(0, 0, gem_10_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0 , gem_10_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(40);

  matrix.clear();
  matrix.drawBitmap(0, 0, gem_11_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0 , gem_11_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(40);

  matrix.clear();
  matrix.drawBitmap(0, 0, gem_12_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0 , gem_12_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(40);

  matrix.clear();
  matrix.drawBitmap(0, 0, gem_13_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0 , gem_13_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(40);

  matrix.clear();
  matrix.drawBitmap(0, 0, gem_14_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0 , gem_14_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(40);

  matrix.clear();
  matrix.drawBitmap(0, 0, gem_1_left, 8, 8, LED_ON);
  matrix.drawBitmap(8, 0 , gem_1_right, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(40);
}
//*/


/* 
 if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, gem_1_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0 , gem_1_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 
 else if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, gem_2_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, gem_2_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, gem_3_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, gem_3_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, gem_4_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, gem_4_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, gem_5_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, gem_5_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, gem_6_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, gem_6_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, gem_7_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, gem_7_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, gem_8_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, gem_8_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, gem_9_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, gem_9_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, gem_10_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0 , gem_10_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, gem_11_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0 , gem_11_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, gem_12_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0 , gem_12_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, gem_13_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0 , gem_13_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else if(currentMillis - previousMillis > interval1) { //if interval1 passed, animate!
 previousMillis = currentMillis;  // save the last time animation changed
 matrix.clear();
 matrix.drawBitmap(0, 0, gem_14_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0 , gem_14_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else{
 matrix.clear();
 matrix.drawBitmap(0, 0, gem_1_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0 , gem_1_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 previousMillis = currentMillis;  // save the last time animation changed
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









