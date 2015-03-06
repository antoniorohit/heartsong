/*
 Lark Buckingham
 Adapted from PulseSensor code and Heart Badge by Becky Stern for Adafruit Industries
 Based on sample code from http://learn.parallax.com/KickStart/28048
 */
#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
#include "LPD8806.h"
#include "SPI.h" 
#ifdef __AVR_ATtiny85__
#include <avr/power.h>
#include <Adafruit_NeoPixel.h>
#endif
//Definitions  
// Calc BPM
//volatile int diff1 = 0;
//volatile int diff2 = 0;
//volatile int diff3 = 0;
//volatile int diff4 = 0;
//volatile int diff5 = 0;
//volatile int diff6 = 0;
//volatile int diff7 = 0;
//volatile int diff8 = 0;
//volatile int diff9 = 0;
//volatile int diff10 = 0;
volatile int IBI = 600;   // For HRpulseArray: holds the time between beats, must be seeded! 
volatile int rate[10];     // For HRpulseArray: array to hold last ten IBI values
volatile unsigned long lastpulsetime = 0; // For HRpulseArray: used to find IBI
int BPM, lastBPM, BPMforDisplay;
int HRV_Value;
unsigned long iterationCounter;
int animationPosition = 0;
byte oldSample, sample;
long pulsetime;// , lastpulsetime;
//button variables
int buttonPushCounter = 0; // counter for number of button presses
int buttonState = 0;  //current state of the button
int lastButtonState = 0; //previous state
int buttonPushCounter2 = 0; // counter for number of button presses
int buttonState2 = 0;  //current state of the button
int lastButtonState2 = 0; //previous state

boolean HRVUp = false;
float cFloat = 316.0;  // make float   NEED TO CONSTRAIN SO c DOESN;t DROP BELOW 0
int c= 316; //color wheel seed


//Animation
//long currentMillis // assigned this in loop... 
long previousMillis = 0;
long interval1 = 60;

//Text
String BPM1[]={
  "Stressball!", "Harshing Mellows", "Freakout!", "Ready", "Be Still My Heart","Too Cute", "Chill OUT", "XXXTremely Sensitive", "Spazz", "Cutie",
  //"Brittle", "Hyper", "Smitten", "Abrasive", "Aspiring", "Cynical", "Power Hungry", "In Love", "Dieting", "Low Cholesterol", 
  //"Scornful", "Enchanted", "Enthralled", "Eager", "Amazed", "Innocent", "Contagious", "Horrified", "In Love", "Smitten", 
  //"In denial", "Skeptical", "Chraming" 
};

String BPM2[]={
  "Romantic", "Shy", "Mellow", "Too Cute", "Open Heart", "Love Horizon", "Unpredicable", "Good Times", "Easy - Breezy", "Loves LOVE",
  //"Exhausted", "Jealous", "Lying", "Asocial", "Down", "Poor nutrition", "Apathetic", "Reactionary", "Self-Conscious", "Devious", 
  //"Insincere", "Mechanical", "High Blood Pressure", "Rigid", "Nervous", "Secretive", "Romantic", "Selfish", "Irate", "Jaded",
  //"Tough", "Unambitious", "Stubborn" 
};


// Number of RGB LEDs in strand:
int nLEDs = 4;

// Chose 2 pins for output; can be any valid output pins:
int dataPin  = 9;
int clockPin = 10;

//LPD8806 strip = LPD8806(nLEDs, dataPin, clockPin);
Adafruit_8x16matrix matrix = Adafruit_8x16matrix();

#define PIXEL_PIN    10    // Digital IO pin connected to the NeoPixels.
#define PIXEL_COUNT 7

// Parameter 1 = number of pixels in strip,  neopixel stick has 8
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_RGB     Pixels are wired for RGB bitstream
//   NEO_GRB     Pixels are wired for GRB bitstream, correct for neopixel stick
//   NEO_KHZ400  400 KHz bitstream (e.g. FLORA pixels)
//   NEO_KHZ800  800 KHz bitstream (e.g. High Density LED strip), correct for neopixel stick
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);


void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
  clock_prescale_set(clock_div_1); // Enable 16 MHz on Trinket
#endif
  Serial.begin(9600);
  pinMode (6, INPUT_PULLUP); //Button 1
  pinMode (12, INPUT_PULLUP); //Button 2
  pinMode (0, INPUT);  //Signal pin to input  

  while (!digitalRead(0)) { // Wait until a beat is detected
  }; 

  matrix.begin(0x70);  // pass in the address
  matrix.setTextSize(1);
  matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  matrix.setTextColor(LED_ON);
  matrix.setBrightness(15); //15 is max
  matrix.setRotation(3);

  strip.begin();  // Start up the LED strip 
  strip.show(); // Update the strip, to start they are all 'off'
}

void fade() {

  int i;
  if ((BPM != lastBPM) && (BPM > lastBPM)){
    // if (BPM > lastBPM){ 
    HRVUp = true;   
  }
  else if ((BPM != lastBPM) && (BPM < lastBPM)){
    //else if (BPM < lastBPM){
    HRVUp = false;
  }
  //if ((BPM != lastBPM) && (BPM > lastBPM)){
  if (HRVUp == true){ 
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

void loop() {
  sample = digitalRead(00);  //Store HR signal output --- put millis() time % 25
  // if sample detected, calculate BPM ------>>>  Got to do this in interrupt!!!!
  if (sample && (oldSample != sample)) {
    Serial.print("Beat: ");
    HRPulseArray();
    Serial.println(BPM);
    //HRpulse();
  }
  //fade();
  
  //keep track of button presses ---- maybe should write interrupt to button!  that way it won't stammer in gem animation
  buttonCounter();
  //buttonCounter2();
  //state=0  print BPM - Button1 == 0, 
  //state=1  Anim 1  Button1 == 1, Button 2 == 0
  //state=2  Anim 1  Button1 == 1, Button 2 == 1
  //state=3  Anim 1  Button1 == 1, Button 2 == 2
  //state=4  Anim 1  Button1 == 1, Button 2 == 3
  //state=5  Text 1  Button1 == 2, Button 2 == 0 - Health 
  //state=7  Text 1  Button1 == 2, Button 2 == 1 - Stress
  //state=8  Text 1  Button1 == 2, Button 2 == 2 - Personality
  //state=9  Text 1  Button1 == 2, Button 2 == 2 - Romance
  //state=10 HRV  Button1 == 3 
  //
  //this would be code for indicator light:
  //    matrix.drawPixel(0, 0, LED_ON);
  //    matrix.writeDisplay();
  // toggle different button states:
  if (buttonPushCounter % 4 == 0){
    //Gem beat animation
    printBPM();
  }
  else if (buttonPushCounter % 4 == 1){
    HRV();
    
    /*
    buttonCounter2();
    //Serial.println(buttonPushCounter2);
    if (buttonPushCounter2 % 6 == 0){
      if (sample && (oldSample != sample)) { //if there's a change, then show gem_Beat
        Serial.println("Beat");
        Heart_Beat();
      }
    }
    if (buttonPushCounter2 % 6 == 1){
      if (sample && (oldSample != sample)) { //if there's a change, then show gem_Beat
        Serial.println("Beat");
        indicator_Beat();
      }
    }
    if (buttonPushCounter2 % 6 == 2){
      if (sample && (oldSample != sample)) { //if there's a change, then show gem_Beat
        Serial.println("Beat");
        gem_Beat();
      }
    }
    if (buttonPushCounter2 % 6 == 3){
      if (sample && (oldSample != sample)) { //if there's a change, then show gem_Beat
        Serial.println("Beat");
        heartMove_Beat();
      }
    }
    if (buttonPushCounter2 % 6 == 4){
      if (sample && (oldSample != sample)) { //if there's a change, then show gem_Beat
        Serial.println("Beat");
        diamond_Beat();
      }
    }
    if (buttonPushCounter2 % 6 == 5){
      if (sample && (oldSample != sample)) { //if there's a change, then show gem_Beat
        Serial.println("Beat");
        dick_beat();
      }
    } 
   */ 
  }
  /*
  else if ((buttonPushCounter % 4 == 1) && (buttonPushCounter2 % 4 == 0)){
   if (sample && (oldSample != sample)) { //if there's a change, then show gem_Beat
   Serial.println("Beat");
   Heart_Beat();
   }
   }
   else if ((buttonPushCounter % 4 == 1) && (buttonPushCounter2 % 4 == 1)){
   if (sample && (oldSample != sample)) { //if there's a change, then show gem_Beat
   Serial.println("Beat");
   indicator_Beat();
   }
   }
   else if ((buttonPushCounter % 4 == 1) && (buttonPushCounter2 % 4 == 2)){
   if (sample && (oldSample != sample)) { //if there's a change, then show gem_Beat
   Serial.println("Beat");
   gem_Beat();
   }
   }
   else if ((buttonPushCounter % 4 == 1) && (buttonPushCounter2 % 4 == 3)){
   if (sample && (oldSample != sample)) { //if there's a change, then show gem_Beat
   Serial.println("Beat");
   void heartMove_Beat ();
   }
   } 
   */
  else if (buttonPushCounter % 4 ==2){
    if((BPM % 2) == 0){
      textScroll1(); 
    }
    else if((BPM % 2) == 1){
      textScroll2();
    }   
    /*
    else if((BPM % 4) == 2){
     textScroll3();
     }
     else if((BPM % 4) == 3){
     textScroll4();
     }
     */
  }

  else if (buttonPushCounter % 4 ==3){
    HRV(); 
  }
  oldSample = sample;           //Store last signal received 
  iterationCounter++;          //iterationCounter 
}


/* Helper functions */

//Input a value 0 to 384 to get a color value.
//The colours are a transition r - g -b - back to r

uint32_t Wheel(uint16_t WheelPos)
{
  byte r, g, b;
  switch(WheelPos / 128)
  {
  case 0:
    r = 127 - WheelPos % 128;   //Red down
    g = WheelPos % 128;      // Green up
    b = 0;                  //blue off
    break; 
  case 1:
    g = 127 - WheelPos % 128;  //green down
    b = WheelPos % 128;      //blue up
    r = 0;                  //red off
    break; 
  case 2:
    b = 127 - WheelPos % 128;  //blue down 
    r = WheelPos % 128;      //red up
    g = 0;                  //green off
    break; 
  }
  return(strip.Color(r,g,b));
}




// write bitmaps to PROGMEM
static const uint8_t PROGMEM
calib_1_left[] = {
  B00000000,
  B00000000,
  B00000001,
  B00000010,
  B00000010,
  B00000001,
  B00000000,
  B00000000}
,
calib_1_right[] = {
  B00000000,
  B00000000,
  B10000000,
  B00000000,
  B01000000,
  B10000000,
  B00000000,
  B00000000}
,calib_2_left[] = {
  B00000000,
  B00000000,
  B00000001,
  B00000010,
  B00000010,
  B00000001,
  B00000000,
  B00000000}
,
calib_2_right[] = {
  B00000000,
  B00000000,
  B10000000,
  B01000000,
  B00000000,
  B10000000,
  B00000000,
  B00000000}
,calib_3_left[] = {
  B00000000,
  B00000000,
  B00000001,
  B00000010,
  B00000010,
  B00000001,
  B00000000,
  B00000000}
,
calib_3_right[] = {
  B00000000,
  B00000000,
  B10000000,
  B01000000,
  B01000000,
  B00000000,
  B00000000,
  B00000000}
,calib_4_left[] = {
  B00000000,
  B00000000,
  B00000001,
  B00000010,
  B00000010,
  B00000000,
  B00000000,
  B00000000}
,
calib_4_right[] = {
  B00000000,
  B00000000,
  B10000000,
  B01000000,
  B01000000,
  B10000000,
  B00000000,
  B00000000}
,calib_5_left[] = {
  B00000000,
  B00000000,
  B00000001,
  B00000010,
  B00000000,
  B00000001,
  B00000000,
  B00000000}
,
calib_5_right[] = {
  B00000000,
  B00000000,
  B10000000,
  B01000000,
  B01000000,
  B10000000,
  B00000000,
  B00000000}
,calib_6_left[] = {
  B00000000,
  B00000000,
  B00000001,
  B00000000,
  B00000010,
  B00000001,
  B00000000,
  B00000000}
,
calib_6_right[] = {
  B00000000,
  B00000000,
  B10000000,
  B01000000,
  B01000000,
  B10000000,
  B00000000,
  B00000000}
,calib_7_left[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000010,
  B00000010,
  B00000001,
  B00000000,
  B00000000}
,
calib_7_right[] = {
  B00000000,
  B00000000,
  B10000000,
  B01000000,
  B01000000,
  B10000000,
  B00000000,
  B00000000}
,calib_8_left[] = {
  B00000000,
  B00000000,
  B00000001,
  B00000010,
  B00000010,
  B00000001,
  B00000000,
  B00000000}
,
calib_8_right[] = {
  B00000000,
  B00000000,
  B00000000,
  B01000000,
  B01000000,
  B10000000,
  B00000000,
  B00000000}
,

gem_1_left[] = {
  B00000000,
  B00000111,
  B00001111,
  B00001111,
  B00000111,
  B00000011,
  B00000001,
  B00000000}
,

//this one like a blip
indicator_1_left[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B10000000,
  B00000000,
  B00000000,
  B00000000}
,
indicator_1_right[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000}
,indicator_2_left[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B01110000,
  B00000000,
  B00000000,
  B00000000}
,
indicator_2_right[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000}
,indicator_3_left[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000100,
  B00011000,
  B00000000,
  B00000000,
  B00000000}
,
indicator_3_right[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000}
,indicator_4_left[] = {
  B00000000,
  B00000000,
  B00000010,
  B00000100,
  B00001000,
  B00000000,
  B00000000,
  B00000000}
,
indicator_4_right[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000}
,indicator_5_left[] = {
  B00000000,
  B00000001,
  B00000010,
  B00000100,
  B00000000,
  B00000000,
  B00000000,
  B00000000}
,
indicator_5_right[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000}
,indicator_6_left[] = {
  B00000000,
  B00000001,
  B00000010,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000}
,
indicator_6_right[] = {
  B00000000,
  B00000000,
  B10000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000}
,indicator_7_left[] = {
  B00000000,
  B00000001,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000}
,
indicator_7_right[] = {
  B00000000,
  B00000000,
  B10000000,
  B01000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000}
,indicator_8_left[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000}
,
indicator_8_right[] = {
  B00000000,
  B00000000,
  B00000000,
  B01000000,
  B00110000,
  B00000000,
  B00000000,
  B00000000}
,indicator_9_left[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000}
,
indicator_9_right[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00011100,
  B00000000,
  B00000000,
  B00000000}
,indicator_10_left[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000}
,
indicator_10_right[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000001,
  B00000000,
  B00000000,
  B00000000}
,
indicator_11_left[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000}
,
indicator_11_right[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000}
,

//beating heart

Heart_1_left[] = 
{
  B00000000,
  B00000010,
  B00000111,
  B00000111,
  B00000111,
  B00000011,
  B00000001,
  B00000000}
,

Heart_1_right[] = {
  B00000000,
  B00100000,
  B01110000,
  B11110000,
  B11110000,
  B11100000,
  B11000000,
  B10000000}
,

Heart_2_left[] = {
  B00000000,
  B00000110,
  B00001111,
  B00001111,
  B00000111,
  B00000011,
  B00000001,
  B00000000}
,

Heart_2_right[] = {
  B00000000,
  B00100000,
  B01110000,
  B11110000,
  B11110000,
  B11100000,
  B11000000,
  B10000000}
,

Heart_3_left[] = {
  B00000010,
  B00000111,
  B00001111,
  B00001111,
  B00000111,
  B00000011,
  B00000001,
  B00000000}
,
Heart_3_right[] = {
  B00000000,
  B00100000,
  B01110000,
  B11110000,
  B11110000,
  B11100000,
  B11000000,
  B10000000}
,

Heart_4_left[] = {
  B00000110,
  B00001111,
  B00001111,
  B00001111,
  B00000111,
  B00000011,
  B00000001,
  B00000000}
,

Heart_4_right[] = {
  B00000000,
  B00110000,
  B01111000,
  B11111000,
  B11110000,
  B11100000,
  B11000000,
  B10000000}
,

Heart_5_left[] = {
  B00000110,
  B00001111,
  B00001111,
  B00001111,
  B00000111,
  B00000011,
  B00000001,
  B00000000}
,

Heart_5_right[] = {
  B00100000,
  B01110000,
  B11111000,
  B11111000,
  B11110000,
  B11100000,
  B11000000,
  B10000000}
,

Heart_6_left[] = {
  B00000110,
  B00001111,
  B00001111,
  B00001111,
  B00000111,
  B00000011,
  B00000001,
  B00000000}
,

Heart_6_right[] = {
  B00110000,
  B01111000,
  B11111000,
  B11111000,
  B11110000,
  B11100000,
  B11000000,
  B10000000}
,

Heart_7_left[] = {
  B00000010,
  B00000111,
  B00001111,
  B00001111,
  B00000111,
  B00000011,
  B00000001,
  B00000000}
,

Heart_7_right[] = {
  B00110000,
  B01111000,
  B11111000,
  B11111000,
  B11110000,
  B11100000,
  B11000000,
  B10000000}
,

Heart_8_left[] = {
  B00000000,
  B00000110,
  B00001111,
  B00001111,
  B00000111,
  B00000011,
  B00000001,
  B00000000}
,

Heart_8_right[] = {
  B00110000,
  B01111000,
  B01111000,
  B11111000,
  B11110000,
  B11100000,
  B11000000,
  B10000000}
,

Heart_9_left[] = {
  B00000000,
  B00000010,
  B00000111,
  B00000111,
  B00000111,
  B00000011,
  B00000001,
  B00000000}
,

Heart_9_right[] = {
  B00100000,
  B01110000,
  B01111000,
  B11111000,
  B11110000,
  B11100000,
  B11000000,
  B10000000}
,

Heart_10_left[] = {
  B00000000,
  B00000010,
  B00000111,
  B00000111,
  B00000111,
  B00000011,
  B00000001,
  B00000000}
,

Heart_10_right[] = {
  B00000000,
  B00110000,
  B01111000,
  B11111000,
  B11110000,
  B11100000,
  B11000000,
  B10000000}
,

Heart_11_left[] = {
  B00000000,
  B00000010,
  B00000111,
  B00000111,
  B00000111,
  B00000011,
  B00000001,
  B00000000}
,

Heart_11_right[] = {
  B00000000,
  B00100000,
  B01110000,
  B11110000,
  B11110000,
  B11100000,
  B11000000,
  B10000000}
,
//this one is moving heart

heartMove_1_left[] = {
  B00000000,
  B00000000,
  B00000000,
  B10000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000}
,
heartMove_1_right[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000}
,heartMove_2_left[] = {
  B00000000,
  B00000000,
  B00000000,
  B00101000,
  B00010000,
  B00000000,
  B00000000,
  B00000000}
,
heartMove_2_right[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000}
,heartMove_3_left[] = {
  B00000000,
  B00000000,
  B00000000,
  B00001010,
  B00000100,
  B00000000,
  B00000000,
  B00000000}
,
heartMove_3_right[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000}
,heartMove_4_left[] = {
  B00000000,
  B00000000,
  B00000101,
  B00000111,
  B00000010,
  B00000000,
  B00000000,
  B00000000}
,
heartMove_4_right[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000}
,heartMove_5_left[] = {
  B00000000,
  B00000100,
  B00001110,
  B00001111,
  B00000111,
  B00000011,
  B00000001,
  B00000000}
,
heartMove_5_right[] = {
  B00000000,
  B01000000,
  B11100000,
  B11100000,
  B11000000,
  B10000000,
  B00000000,
  B00000000}
,heartMove_6_left[] = {
  B00000000,
  B00000010,
  B00000111,
  B00000111,
  B00000011,
  B00000001,
  B00000000,
  B00000000}
,
heartMove_6_right[] = {
  B00000000,
  B00100000,
  B01110000,
  B11110000,
  B11100000,
  B11000000,
  B10000000,
  B00000000}
,heartMove_7_left[] = {
  B00000000,
  B00000000,
  B00000001,
  B00000001,
  B00000000,
  B00000000,
  B00000000,
  B00000000}
,
heartMove_7_right[] = {
  B00000000,
  B00000000,
  B10110000,
  B11110000,
  B11100000,
  B01000000,
  B00000000,
  B00000000}
,heartMove_8_left[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000}
,
heartMove_8_right[] = {
  B00000000,
  B00000000,
  B00000000,
  B00101000,
  B00111000,
  B00010000,
  B00000000,
  B00000000}
,heartMove_9_left[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000}
,
heartMove_9_right[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00001010,
  B00000100,
  B00000000,
  B00000000}
,heartMove_10_left[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000}
,
heartMove_10_right[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000001,
  B00000000,
  B00000000,
  B00000000}
,

gem_1_right[] = {
  B00000000,
  B11110000,
  B11101000,
  B11011000,
  B11110000,
  B11100000,
  B11000000,
  B10000000}
,gem_2_left[] = {
  B00000000,
  B00000111,
  B00001111,
  B00001111,
  B00000111,
  B00000011,
  B00000001,
  B00000000}
,
gem_2_right[] = {
  B00000000,
  B11110000,
  B11101000,
  B11011000,
  B11110000,
  B11100000,
  B11000000,
  B10000000}
,gem_3_left[] = {
  B00000000,
  B00000111,
  B00001111,
  B00001111,
  B00000111,
  B00000011,
  B00000001,
  B00000000}
,
gem_3_right[] = {
  B00000000,
  B11110000,
  B11101000,
  B11011000,
  B11110000,
  B11100000,
  B11000000,
  B10000000}
,gem_4_left[] = {
  B00000000,
  B00000000,
  B00000011,
  B00000111,
  B00000011,
  B00000001,
  B00000000,
  B00000000}
,
gem_4_right[] = {
  B00000000,
  B00000000,
  B11100000,
  B11010000,
  B11100000,
  B11000000,
  B10000000,
  B00000000}
,gem_5_left[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000001,
  B00000001,
  B00000000,
  B00000000,
  B00000000}
,
gem_5_right[] = {
  B00000000,
  B00000000,
  B00000000,
  B11000000,
  B11000000,
  B10000000,
  B00000000,
  B00000000}
,gem_6_left[] = {
  B00000000,
  B00000111,
  B00001111,
  B00001111,
  B00000111,
  B00000011,
  B00000001,
  B00000000}
,
gem_6_right[] = {
  B00000000,
  B11110000,
  B11111000,
  B11111000,
  B11110000,
  B11100000,
  B11000000,
  B10000000}
,gem_7_left[] = {
  B00000111,
  B00001111,
  B00011111,
  B00011111,
  B00001111,
  B00000111,
  B00000011,
  B00000001}
,
gem_7_right[] = {
  B11110000,
  B11111000,
  B11111100,
  B11111100,
  B11111000,
  B11110000,
  B11100000,
  B11000000}
,gem_8_left[] = {
  B00001000,
  B00010111,
  B00101111,
  B00101111,
  B00010111,
  B00001011,
  B00000101,
  B00000010}
,
gem_8_right[] = {
  B00001000,
  B11110100,
  B11101010,
  B11011010,
  B11110100,
  B11101000,
  B11010000,
  B10100000}
,gem_9_left[] = {
  B00100000,
  B00000111,
  B10001111,
  B10001111,
  B01000111,
  B01100011,
  B00000001,
  B00001000}
,
gem_9_right[] = {
  B00000010,
  B11110001,
  B11111000,
  B11101000,
  B11010001,
  B11100011,
  B11000000,
  B10001000}
,gem_10_left[] = {
  B10000000,
  B00000111,
  B00001111,
  B00001111,
  B00000111,
  B00000011,
  B00000001,
  B11000000}
,
gem_10_right[] = {
  B00000001,
  B11110000,
  B11111000,
  B11111000,
  B11010000,
  B10100000,
  B11000001,
  B10000010}
,gem_11_left[] = {
  B00000000,
  B00000111,
  B00001111,
  B00001111,
  B00000111,
  B00000011,
  B00000001,
  B00000000}
,
gem_11_right[] = {
  B00000000,
  B11110000,
  B11111000,
  B11111000,
  B11110000,
  B10100000,
  B01000000,
  B10000000}
,gem_12_left[] = {
  B00000000,
  B00000111,
  B00001111,
  B00001111,
  B00000111,
  B00000011,
  B00000001,
  B00000000}
,
gem_12_right[] = {
  B00000000,
  B11110000,
  B11111000,
  B11111000,
  B11110000,
  B11100000,
  B01000000,
  B10000000}
,gem_13_left[] = {
  B00000000,
  B00000111,
  B00001111,
  B00001111,
  B00000111,
  B00000011,
  B00000001,
  B00000000}
,
gem_13_right[] = {
  B00000000,
  B11110000,
  B11111000,
  B11111000,
  B11110000,
  B11100000,
  B11000000,
  B10000000}
,gem_14_left[] = {
  B00000000,
  B00000111,
  B00001111,
  B00001111,
  B00000111,
  B00000011,
  B00000001,
  B00000000}
,
gem_14_right[] = {
  B00000000,
  B11110000,
  B11101000,
  B11111000,
  B11110000,
  B11100000,
  B11000000,
  B10000000}
,

diamond_1_left[] = {
  B00000000,
  B00000000,
  B00000001,
  B00000011,
  B00000111,
  B00000011,
  B00000001,
  B00000000}
,
diamond_1_right[] = {
  B00000000,
  B00000000,
  B00000000,
  B10000000,
  B11000000,
  B10000000,
  B00000000,
  B00000000}
,
diamond_2_left[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000001,
  B00000011,
  B00000001,
  B00000000,
  B00000000}
,
diamond_2_right[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B10000000,
  B00000000,
  B00000000,
  B00000000}
,
diamond_3_left[] = {
  B00000000,
  B00000001,
  B00000011,
  B00000111,
  B00001111,
  B00000111,
  B00000011,
  B00000001}
,
diamond_3_right[] = {
  B00000000,
  B00000000,
  B10000000,
  B11000000,
  B11100000,
  B11000000,
  B10000000,
  B00000000}
,
diamond_4_left[] = {
  B00000001,
  B00000010,
  B00000101,
  B00001011,
  B00010111,
  B00001011,
  B00000101,
  B00000010}
,
diamond_4_right[] = {
  B00000000,
  B10000000,
  B01000000,
  B10100000,
  B11010000,
  B10100000,
  B01000000,
  B10000000}
,
diamond_5_left[] = {
  B00000010,
  B00000100,
  B00001001,
  B00010011,
  B00100111,
  B00010011,
  B00001001,
  B00000100}
,
diamond_5_right[] = {
  B10000000,
  B01000000,
  B00100000,
  B10010000,
  B11001000,
  B10010000,
  B00100000,
  B01000000}
,
diamond_6_left[] = {
  B00000100,
  B00001000,
  B00010001,
  B00100011,
  B01000111,
  B00100011,
  B00010001,
  B00001000}
,
diamond_6_right[] = {
  B01000000,
  B00100000,
  B00010000,
  B10001000,
  B11000100,
  B10001000,
  B00010000,
  B00100000}
,
diamond_7_left[] = {
  B00010000,
  B00100000,
  B01000001,
  B10000011,
  B00000111,
  B10000011,
  B01000001,
  B00100000}
,
diamond_7_right[] = {
  B00010000,
  B00001000,
  B00000100,
  B10000010,
  B11000001,
  B10000010,
  B00000100,
  B00001000}
,
diamond_8_left[] = {
  B01000000,
  B10000000,
  B00000001,
  B00000011,
  B00000111,
  B00000011,
  B00000001,
  B10000000}
,
diamond_8_right[] = {
  B00000100,
  B00000010,
  B00000000,
  B10000000,
  B11000000,
  B10000000,
  B00000000,
  B00000010}
,
diamond_9_left[] = {
  B10000000,
  B00000000,
  B00000001,
  B00000011,
  B00000111,
  B00000011,
  B00000001,
  B10000000}
,
diamond_9_right[] = {
  B00000010,
  B00000000,
  B00000000,
  B10000000,
  B11000000,
  B10000000,
  B00000000,
  B00000010}
,

dick_1_left[] = {
  B00000000,
  B00001100,
  B00011100,
  B00111000,
  B01110000,
  B11100000,
  B11110000,
  B11110000}
,
dick_1_right[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000}
,dick_2_left[] = {
  B00000000,
  B00000000,
  B00001100,
  B00111100,
  B01111000,
  B11100000,
  B11110000,
  B11110000}
,
dick_2_right[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000}
,dick_3_left[] = {
  B00000000,
  B00000110,
  B00011110,
  B00111100,
  B01110000,
  B11100000,
  B11110000,
  B11110000}
,
dick_3_right[] = {
  B10000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000}
,dick_4_left[] = {
  B00000000,
  B00001100,
  B00011100,
  B00111000,
  B01110000,
  B11100000,
  B11110000,
  B11110000}
,
dick_4_right[] = {
  B00100000,
  B00010000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000}
,dick_5_left[] = {
  B00000000,
  B00001100,
  B00011100,
  B00111000,
  B01110000,
  B11100000,
  B11110000,
  B11110000}
,
dick_5_right[] = {
  B00000000,
  B00000000,
  B00001000,
  B00000100,
  B00000000,
  B00000000,
  B00000000,
  B00000000}
,dick_6_left[] = {
  B00000000,
  B00001100,
  B00011100,
  B00111000,
  B01110000,
  B11100000,
  B11110000,
  B11110000}
,
dick_6_right[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000001}
,

//sparkle for HRV up
HRV_sparkle_1_left[] = {
  B10000000,
  B00000100,
  B00000000,
  B01010001,
  B10000000,
  B00010000,
  B00000000,
  B00000110}
,
HRV_sparkle_1_right[] = {
  B01000000,
  B00010001,
  B00000001,
  B00000000,
  B00000100,
  B01000100,
  B00000000,
  B00000000}
,HRV_sparkle_2_left[] = {
  B00000000,
  B10000100,
  B00000100,
  B00000000,
  B10010000,
  B00001000,
  B00000100,
  B00000000}
,
HRV_sparkle_2_right[] = {
  B10000001,
  B00001010,
  B00000000,
  B01000010,
  B00000000,
  B01001000,
  B00000000,
  B00010001}
,HRV_sparkle_3_left[] = {
  B10000010,
  B01001000,
  B00000001,
  B00000000,
  B00010001,
  B10000000,
  B00000100,
  B00000000}
,
HRV_sparkle_3_right[] = {
  B00010011,
  B00000000,
  B00010000,
  B00000000,
  B10000001,
  B00000100,
  B00010000,
  B00000000}
,HRV_sparkle_4_left[] = {
  B00100000,
  B00000010,
  B00001000,
  B00100000,
  B00100010,
  B00000000,
  B01001000,
  B10000000}
,
HRV_sparkle_4_right[] = {
  B00000000,
  B10010010,
  B00001000,
  B00000000,
  B00100001,
  B00000000,
  B00001000,
  B10000000}
,HRV_sparkle_5_left[] = {
  B10000000,
  B00000001,
  B00001000,
  B00000000,
  B01000010,
  B00000000,
  B00100100,
  B00000000}
,
HRV_sparkle_5_right[] = {
  B10000010,
  B00100000,
  B00000010,
  B00000000,
  B00001000,
  B01000000,
  B01000000,
  B00000001}
,HRV_sparkle_6_left[] = {
  B00000010,
  B00000000,
  B11000000,
  B00001000,
  B00000000,
  B01000010,
  B00000100,
  B00001000}
,
HRV_sparkle_6_right[] = {
  B00000000,
  B01000010,
  B00001000,
  B00000000,
  B01000000,
  B00000010,
  B00010000,
  B00000000}
,HRV_sparkle_7_left[] = {
  B10000100,
  B00000000,
  B00010001,
  B00100000,
  B10000000,
  B10000010,
  B00010000,
  B00100000}
,
HRV_sparkle_7_right[] = {
  B00000100,
  B00100000,
  B00000000,
  B00010010,
  B00000000,
  B10000000,
  B00000010,
  B00000001}
,HRV_sparkle_8_left[] = {
  B00000100,
  B00000000,
  B00100000,
  B00001001,
  B00000000,
  B00100010,
  B00000000,
  B01000000}
,
HRV_sparkle_8_right[] = {
  B00000000,
  B00100001,
  B00100000,
  B00000010,
  B10010000,
  B01000000,
  B00000010,
  B00100000}
,HRV_sparkle_9_left[] = {
  B01000000,
  B00000000,
  B00000100,
  B00100000,
  B00000000,
  B00000001,
  B00001000,
  B00000000}
,
HRV_sparkle_9_right[] = {
  B10000000,
  B00001000,
  B00000000,
  B01000000,
  B01000001,
  B10000000,
  B00010000,
  B00000010}
,HRV_sparkle_10_left[] = {
  B00100000,
  B00000000,
  B00000010,
  B10100000,
  B00001000,
  B00000001,
  B01000000,
  B10000000}
,
HRV_sparkle_10_right[] = {
  B00010001,
  B00100000,
  B00000100,
  B00100000,
  B00000000,
  B00001000,
  B10000010,
  B00000000}
,HRV_sparkle_11_left[] = {
  B00000000,
  B00000100,
  B00100000,
  B01000000,
  B00000010,
  B00010000,
  B01000000,
  B00000010}
,
HRV_sparkle_11_right[] = {
  B01000100,
  B01000000,
  B00000100,
  B00000000,
  B00000000,
  B00100001,
  B00000100,
  B00001000}
,

//this is for HRV down

HRV_fade_1_left[] = {
  B00100010,
  B00100010,
  B00100000,
  B00000100,
  B10000100,
  B10000100,
  B10000000,
  B00000010}
,
HRV_fade_1_right[] = {
  B00001000,
  B00000010,
  B00000010,
  B00000010,
  B00100000,
  B00100000,
  B00101000,
  B00001000}
,HRV_fade_2_left[] = {
  B00000010,
  B00100010,
  B00100010,
  B00100000,
  B00000100,
  B10000100,
  B10000100,
  B10000000}
,
HRV_fade_2_right[] = {
  B00001000,
  B00001000,
  B00000010,
  B00000010,
  B00000010,
  B00100000,
  B00100000,
  B00101000}
,HRV_fade_3_left[] = {
  B10000000,
  B00000010,
  B00100010,
  B00100010,
  B00100000,
  B00000100,
  B10000100,
  B10000100}
,
HRV_fade_3_right[] = {
  B00101000,
  B00001000,
  B00001000,
  B00000010,
  B00000010,
  B00000010,
  B00100000,
  B00100000}
,HRV_fade_4_left[] = {
  B10000100,
  B10000000,
  B00000010,
  B00100010,
  B00100010,
  B00100000,
  B00000100,
  B10000100}
,
HRV_fade_4_right[] = {
  B00100000,
  B00101000,
  B00001000,
  B00001000,
  B00000010,
  B00000010,
  B00000010,
  B00100000}
,HRV_fade_5_left[] = {
  B10000100,
  B10000100,
  B10000000,
  B00000010,
  B00100010,
  B00100010,
  B00100000,
  B00000100}
,
HRV_fade_5_right[] = {
  B00100000,
  B00100000,
  B00101000,
  B00001000,
  B00001000,
  B00000010,
  B00000010,
  B00000010}
,HRV_fade_6_left[] = {
  B00000100,
  B10000100,
  B10000100,
  B10000000,
  B00000010,
  B00100010,
  B00100010,
  B00100000}
,
HRV_fade_6_right[] = {
  B00000010,
  B00100000,
  B00100000,
  B00101000,
  B00001000,
  B00001000,
  B00000010,
  B00000010}
,HRV_fade_7_left[] = {
  B00100000,
  B00000100,
  B10000100,
  B10000100,
  B10000000,
  B00000010,
  B00100010,
  B00100010}
,
HRV_fade_7_right[] = {
  B00000010,
  B00000010,
  B00100000,
  B00100000,
  B00101000,
  B00001000,
  B00001000,
  B00000010}
,HRV_fade_8_left[] = {
  B00100010,
  B00100000,
  B00000100,
  B10000100,
  B10000100,
  B10000000,
  B00000010,
  B00100010}
,
HRV_fade_8_right[] = {
  B00000010,
  B00000010,
  B00000010,
  B00100000,
  B00100000,
  B00101000,
  B00001000,
  B00001000}
,

up_left[] = {
  B00000000,
  B00000001,
  B00000010,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000}
,
up_right[] = {
  B10000000,
  B11000000,
  B10100000,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000}
,down_left[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000010,
  B00000001,
  B00000000}
,
down_right[] = {
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B10100000,
  B11000000,
  B10000000}
,equals_left[] = {
  B00000000,
  B00000000,
  B00000111,
  B00000000,
  B00000111,
  B00000000,
  B00000000,
  B00000000}
,
equals_right[] = {
  B00000000,
  B00000000,
  B11110000,
  B00000000,
  B11110000,
  B00000000,
  B00000000,
  B00000000}
;










