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

  if (HRVUp == true){ 
     cFloat += 0.05;
    if(cFloat > 383){
      cFloat = 383;
    }
  }
  else 
  {
     cFloat -= 0.05;
     if(cFloat < 256){
      cFloat = 256;
    }
  }
    for (i=0; i < pixels.numPixels(); i++) {
      pixels.setPixelColor(i, Wheel(((int)cFloat) % 384));
    }
    pixels.show();   // write all the pixels out  
}














