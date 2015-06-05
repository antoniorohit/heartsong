#include <Wire.h>
#include "Adafruit_DRV2605.h"
Adafruit_DRV2605 drv;


int buttonState = 0;  //current state of the button
int lastButtonState = 1; //previous state
long interval = 200;
long interval2 = 1000; 
long interval3 = 6000;
long interval4 = 7000;
long previousMillis = 0; 
boolean buzzflag = false;
uint8_t effect = 1;


void setup() {
    Serial.begin(19200);
    pinMode(2, INPUT_PULLUP);
     drv.begin();
     drv.selectLibrary(1);
    drv.setMode(DRV2605_MODE_INTTRIG); 
}

void loop() {
    buttonState = digitalRead(2);
    unsigned long currentMillis = millis();
    if (buttonState != lastButtonState) { 
       Serial.println("START");
      Serial.println(buttonState);
      if (buttonState == LOW) {
        Serial.println("START TIMER");
        buzzflag = true;
        previousMillis = millis();
        Serial.println("button state");
        Serial.println(buttonState);
        Serial.println(previousMillis);
        
      }
      lastButtonState = buttonState;
    }
  if((currentMillis - previousMillis) > interval && (currentMillis - previousMillis) < interval2){
    if(buzzflag) {
       drv.setWaveform(1, 86);  // play effect 
       drv.setWaveform(2, 0);       // end waveform
       drv.go();  //
    }
  }
  if((currentMillis - previousMillis) > interval3) {
    if(buzzflag) {
      Serial.println("BAM");
      if( (currentMillis - previousMillis) < interval4){
       Serial.println((currentMillis - previousMillis));
       drv.setWaveform(1, 86);  // play effect 
       drv.setWaveform(2, 0);       // end waveform
       drv.go();  // 
        }
    }
     buzzflag = false;
  }
}


// a function to be executed periodically
void buzzMe() {
    Serial.println( "in here");
   // for (int i = 0; i < 10; i++)  {
       drv.setWaveform(1, 86);  // play effect 
       drv.setWaveform(2, 0);       // end waveform
       drv.go();  // play the effect!
   // }
}





 

