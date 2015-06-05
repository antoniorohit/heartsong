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
    for (i=0; i < pixels.numPixels(); i++) {
      pixels.setPixelColor(i, Wheel(c % 384));
    }
     cFloat = cFloat + .05;
    if(cFloat > 383){
      cFloat = 383;
    }
    //constrain(cFloat, 250, 383);
    c = (int) cFloat;
    pixels.show();   // write all the pixels out  
  }
  else if (HRVUp == false){
    for (i=0; i < pixels.numPixels(); i++) {
      pixels.setPixelColor(i, Wheel(c % 384));
    }
     cFloat = cFloat - .05;
     if(cFloat < 250){
      cFloat = 250;
    }
    //constrain(cFloat, 250, 383);
    c = (int) cFloat;
    pixels.show();   // write all the pixels out
  }
  //Serial.println(HRVUp);
  //Serial.println(c);
  lastBPM = BPM;
}



