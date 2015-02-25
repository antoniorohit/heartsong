void HRV() {
  // This is code for just arrows
  /* 
   if (HRVUp == true){ //set
   matrix.clear();
   matrix.drawBitmap(0, 0, up_left, 8, 8, LED_ON);
   matrix.drawBitmap(8, 0 , up_right, 8, 8, LED_ON);
   matrix.writeDisplay();
   }
   
   else if (HRVUp == false){
   matrix.clear();
   matrix.drawBitmap(0, 0, up_left, 8, 8, LED_ON);
   matrix.drawBitmap(8, 0 , up_right, 8, 8, LED_ON);
   matrix.writeDisplay();
   }
   //Serial.println(HRVUp);
   Serial.println(c);
   lastBPM = BPM;
   }
   */
  //  This is code with HRV and Fade linked, prints arrows
  int i;
  if ((BPM != lastBPM) && (BPM > lastBPM)){
    // if (BPM > lastBPM){ //set
    HRVUp = true;
    //    matrix.clear();
    //    matrix.drawBitmap(0, 0, up_left, 8, 8, LED_ON);
    //    matrix.drawBitmap(8, 0 , up_right, 8, 8, LED_ON);
    //    matrix.writeDisplay();
  }
  else if ((BPM != lastBPM) && (BPM < lastBPM)){
    //else if (BPM < lastBPM){
    HRVUp = false;
    //    matrix.clear();
    //    matrix.drawBitmap(0, 0, down_left, 8, 8, LED_ON);
    //    matrix.drawBitmap(8, 0, down_right, 8, 8, LED_ON);
    //    matrix.writeDisplay();
  }

  if (iterationCounter % 900 == 0){ 
    matrix.setRotation(3);
    matrix.clear();
    if(BPM <100){  // else print BPM
      matrix.setCursor(0,0);
      matrix.print(BPM);
      matrix.writeDisplay();
      //delay(100);
      //animationPosition--;
    }   
    else if(BPM >= 100){  // else print BPM
      matrix.setCursor(-1,0);
      matrix.print(BPM);
      matrix.writeDisplay();
      //delay(100);
      //animationPosition--;
    }     
  }

  if (HRVUp == true){ //set
    for (i=0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(c % 384));
    }
     cFloat = cFloat - .05;
    if(cFloat < 250){
      cFloat = 250;
    }
    //constrain(cFloat, 250, 383);
    c = (int) cFloat;
    strip.show();   // write all the pixels out  
    //delay(50); 
  }
  else if (HRVUp == false){
    for (i=0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(c % 384));
    }
     cFloat = cFloat + .05;
     if(cFloat > 383){
      cFloat = 383;
    }
    //constrain(cFloat, 250, 383);
    c = (int) cFloat;
    strip.show();   // write all the pixels out
    //delay(50);
  }
  //Serial.println(HRVUp);
  Serial.println(c);
  lastBPM = BPM;
}


/*
 //  This is code with HRV and Fade linked, prints arrows
 int i;
 if ((BPM != lastBPM) && (BPM > lastBPM)){
 // if (BPM > lastBPM){ //set
 HRVUp = true;
 matrix.clear();
 matrix.drawBitmap(0, 0, up_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0 , up_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 else if ((BPM != lastBPM) && (BPM < lastBPM)){
 //else if (BPM < lastBPM){
 HRVUp = false;
 matrix.clear();
 matrix.drawBitmap(0, 0, down_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, down_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 //if ((BPM != lastBPM) && (BPM > lastBPM)){
 if (HRVUp == true){ //set
 for (i=0; i < strip.numPixels(); i++) {
 strip.setPixelColor(i, Wheel(c % 384));
 }
 cFloat = cFloat + .1;
 c = (int) cFloat;
 strip.show();   // write all the pixels out  
 //delay(50); 
 }
 // else if ((BPM != lastBPM) && (BPM < lastBPM)){
 else if (HRVUp == false){
 for (i=0; i < strip.numPixels(); i++) {
 strip.setPixelColor(i, Wheel(c % 384));
 }
 cFloat = cFloat - .1;
 c = (int) cFloat;
 strip.show();   // write all the pixels out
 //delay(50);
 }
 //Serial.println(HRVUp);
 Serial.println(c);
 lastBPM = BPM;
 }
 */

/*
int i;
 //if ((BPM != lastBPM) && (BPM > lastBPM)){
 if (BPM > lastBPM){ //set
 HRVUp = true;
 matrix.clear();
 matrix.drawBitmap(0, 0, up_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0 , up_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 for (i=0; i < strip.numPixels(); i++) {
 strip.setPixelColor(i, Wheel(c % 384));
 }
 c = c + 20;
 strip.show();   // write all the pixels out   
 }
 // else if ((BPM != lastBPM) && (BPM < lastBPM)){
 else if (BPM < lastBPM){
 HRVUp = false;
 matrix.clear();
 matrix.drawBitmap(0, 0, down_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, down_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 for (i=0; i < strip.numPixels(); i++) {
 strip.setPixelColor(i, Wheel(c % 384));
 }
 c = c- 20;
 strip.show();   // write all the pixels out
 }
 lastBPM = BPM;
 }
 
 */

/*
 if(HRVUp == true){
 long time = millis();
 if (((time % 480) >= 0) && ((time % 480) < 60)){
 matrix.clear();
 matrix.drawBitmap(0, 0, HRV_sparkle_1_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0 , HRV_sparkle_1_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else if (((time % 480) >= 60) && ((time % 480) < 120)){
 matrix.clear();
 matrix.drawBitmap(0, 0, HRV_sparkle_2_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, HRV_sparkle_2_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 else if (((time % 480) >= 120) && ((time % 480) < 180)){
 matrix.clear();
 matrix.drawBitmap(0, 0, HRV_sparkle_3_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, HRV_sparkle_3_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 else if (((time % 480) >= 180) && ((time % 480) < 240)){
 matrix.clear();
 matrix.drawBitmap(0, 0, HRV_sparkle_4_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, HRV_sparkle_4_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 else if (((time % 480) >= 240) && ((time % 480) < 300)){
 matrix.clear();
 matrix.drawBitmap(0, 0, HRV_sparkle_5_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, HRV_sparkle_5_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 else if (((time % 480) >= 300) && ((time % 480) < 360)){
 matrix.clear();
 matrix.drawBitmap(0, 0, HRV_sparkle_6_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, HRV_sparkle_6_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 else if (((time % 360) >= 700) && ((time % 480) < 420)){
 matrix.clear();
 matrix.drawBitmap(0, 0, HRV_sparkle_7_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, HRV_sparkle_7_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 else if (((time % 500) >= 420) && ((time % 480) <= 480)){
 matrix.clear();
 matrix.drawBitmap(0, 0, HRV_sparkle_8_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, HRV_sparkle_8_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 }
 else if (HRVUp == false){ 
 long time = millis();
 if (((time % 480) >= 0) && ((time % 480) < 60)){
 matrix.clear();
 matrix.drawBitmap(0, 0, HRV_fade_1_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0 , HRV_fade_1_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 
 else if (((time % 480) >= 60) && ((time % 480) < 120)){
 matrix.clear();
 matrix.drawBitmap(0, 0, HRV_fade_2_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, HRV_fade_2_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 else if (((time % 480) >= 120) && ((time % 480) < 180)){
 matrix.clear();
 matrix.drawBitmap(0, 0, HRV_fade_3_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, HRV_fade_3_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 else if (((time % 480) >= 180) && ((time % 480) < 240)){
 matrix.clear();
 matrix.drawBitmap(0, 0, HRV_fade_4_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, HRV_fade_4_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 else if (((time % 480) >= 240) && ((time % 480) < 300)){
 matrix.clear();
 matrix.drawBitmap(0, 0, HRV_fade_5_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, HRV_fade_5_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 else if (((time % 480) >= 300) && ((time % 480) < 360)){
 matrix.clear();
 matrix.drawBitmap(0, 0, HRV_fade_6_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, HRV_fade_6_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 else if (((time % 360) >= 700) && ((time % 480) < 420)){
 matrix.clear();
 matrix.drawBitmap(0, 0, HRV_fade_7_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, HRV_fade_7_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 else if (((time % 500) >= 420) && ((time % 480) <= 480)){
 matrix.clear();
 matrix.drawBitmap(0, 0, HRV_fade_8_left, 8, 8, LED_ON);
 matrix.drawBitmap(8, 0, HRV_fade_8_right, 8, 8, LED_ON);
 matrix.writeDisplay();
 }
 }
 
 lastBPM = BPM;
 }
 */













