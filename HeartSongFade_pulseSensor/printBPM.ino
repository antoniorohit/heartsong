void printBPM() {
  
  if (iterationCounter % 900 == 0){ 
    matrix.setRotation(3);
    matrix.clear();
    if(BPM < 40){    // while calibrating print this
      /* //blink "*" off and on
       long time = millis();
       if ((time % 2000) < 1000){
       matrix.setCursor(0,0);
       matrix.print("*");
       matrix.writeDisplay();
       }
       else if ((time % 2000) >= 1000){
       matrix.setCursor(5,0);
       matrix.print("*");
       matrix.writeDisplay();
       }
       */
      // Run Calibration animation
      long time = millis();

      if ((time % 1000) < 125){
        matrix.clear();
        matrix.drawBitmap(0, 0, calib_1_left, 8, 8, LED_ON);
        matrix.drawBitmap(8, 0 , calib_1_right, 8, 8, LED_ON);
        matrix.writeDisplay();
      }
      else if (((time % 1000) >= 125) && ((time % 1000) < 250)){
        matrix.clear();
        matrix.drawBitmap(0, 0, calib_2_left, 8, 8, LED_ON);
        matrix.drawBitmap(8, 0, calib_2_right, 8, 8, LED_ON);
        matrix.writeDisplay();
      }
      else if (((time % 1000) >= 250) && ((time % 1000) < 375)){
        matrix.clear();
        matrix.drawBitmap(0, 0, calib_3_left, 8, 8, LED_ON);
        matrix.drawBitmap(8, 0, calib_3_right, 8, 8, LED_ON);
        matrix.writeDisplay();
      }
      else if (((time % 1000) >= 375) && ((time % 1000) < 500)){
        matrix.clear();
        matrix.drawBitmap(0, 0, calib_4_left, 8, 8, LED_ON);
        matrix.drawBitmap(8, 0, calib_4_right, 8, 8, LED_ON);
        matrix.writeDisplay();
      }
      else if (((time % 1000) >= 500) && ((time % 1000) < 625)){
        matrix.clear();
        matrix.drawBitmap(0, 0, calib_5_left, 8, 8, LED_ON);
        matrix.drawBitmap(8, 0, calib_5_right, 8, 8, LED_ON);
        matrix.writeDisplay();
      }
      else if (((time % 1000) >= 625) && ((time % 1000) < 750)){
        matrix.clear();
        matrix.drawBitmap(0, 0, calib_6_left, 8, 8, LED_ON);
        matrix.drawBitmap(8, 0, calib_6_right, 8, 8, LED_ON);
        matrix.writeDisplay();
      }
      else if (((time % 1000) >= 750) && ((time % 1000) < 875)){
        matrix.clear();
        matrix.drawBitmap(0, 0, calib_7_left, 8, 8, LED_ON);
        matrix.drawBitmap(8, 0, calib_7_right, 8, 8, LED_ON);
        matrix.writeDisplay();
      }
      else if (((time % 1000) >= 875) && ((time % 1000) < 999)){
        matrix.clear();
        matrix.drawBitmap(0, 0, calib_8_left, 8, 8, LED_ON);
        matrix.drawBitmap(8, 0, calib_8_right, 8, 8, LED_ON);
        matrix.writeDisplay();
        
      }
    }
    else if((BPM >= 35) && (BPM <100)){  // else print BPM
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
}




