void HRV() {
  
  //  This is code with HRV and Fade linked, prints arrows
  int i;
  if (BPM != lastBPM){ 
     if(BPM > lastBPM){
    HRVUp = true;
    }
    else{
    HRVUp = false;
    }
  }

  if (HRVUp == true){ //set
    for (i=0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(c % 384));
    }
     cFloat = cFloat - 1;
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
     cFloat = cFloat + 1;
     if(cFloat > 383){
      cFloat = 383;
    }
    //constrain(cFloat, 250, 383);
    c = (int) cFloat;
    strip.show();   // write all the pixels out
    //delay(50);
  }
  Serial.println(HRVUp);
  Serial.println(c);
  lastBPM = BPM;
}














