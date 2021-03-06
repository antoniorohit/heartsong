/*
 Lark Buckingham
 //CODE FOR ARDUINO UNO with black stran
 Tried adding pulseSensor code -- get BPM to print but only from within interrupt....
 Adapted from PulseSensor code and Heart Badge by Becky Stern for Adafruit Industries
 Based on sample code from http://learn.parallax.com/KickStart/28048
 */
#include <SD.h>
#include <Wire.h>
#include "Adafruit_GFX.h"
#include "LPD8806.h"
#include "SPI.h" 
#include <Adafruit_NeoPixel.h>
#define BRIGHTNESS  128
#include "Adafruit_DRV2605.h"
Adafruit_DRV2605 drv;

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN            9

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      2

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


volatile int IBI = 600;   // For HRpulseArray: holds the time between beats, must be seeded! 
volatile int rate[10];     // For HRpulseArray: array to hold last ten IBI values
volatile unsigned long lastpulsetime = 0; // For HRpulseArray: used to find IBI
int BPM, lastBPM, BPMforDisplay;
int HRV_Value;
unsigned long iterationCounter;
int animationPosition = 0;
byte oldSample, sample;
long pulsetime;// , lastpulsetime;

//PULSE SENSOR CODE
//  VARIABLES
int pulsePin = 0;                 // Pulse Sensor purple wire connected to analog pin 0
int blinkPin = 7;                // pin to blink led at each beat
int fadePin = 5;                  // pin to do fancy classy fading blink at each beat
int fadeRate = 0;                 // used to fade LED on with PWM on fadePin


// these variables are volatile because they are used during the interrupt service routine!
//volatile int BPM;                   // used to hold the pulse rate
volatile int Signal;                // holds the incoming raw data
//volatile int IBI = 600;             // holds the time between beats, must be seeded! 
volatile boolean Pulse = false;     // true when pulse wave is high, false when it's low
volatile boolean lastPulse = false;     // true when pulse wave is high, false when it's low
volatile boolean QS = false;        // becomes true when Arduoino finds a beat.

//button variables
int buttonPushCounter = 0; // counter for number of button presses
int buttonState = 0;  //current state of the button
int lastButtonState = 1; //previous state
int buttonPushCounter2 = 0; // counter for number of button presses
int buttonState2 = 0;  //current state of the button
int lastButtonState2 = 0; //previous state
long interval = 200;
long interval2 = 1000; 
long interval3 = 60000;
long previousMillis = 0; 
boolean buzzflag = false;

//This is for HRV fade
boolean HRVUp = false;
float cFloat = 316.0;  // make float   NEED TO CONSTRAIN SO c DOESN;t DROP BELOW 0
int c= 316; //color wheel seed


//Animation
//long currentMillis // assigned this in loop... 
//long previousMillis = 0;
//long interval1 = 60;



// THIS IS CODE FOR NEOPIX STRAND
// Number of RGB LEDs in strand:
int nLEDs = 7;
// Chose 2 pins for output; can be any valid output pins:
int dataPin  = 9; //green
int clockPin = 10; //orange
//on flora, power goes to vBatt

//LPD8806 strip = LPD8806(nLEDs, dataPin, clockPin);

// Parameter 1 = number of pixels in strip,  neopixel stick has 8
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_RGB     Pixels are wired for RGB bitstream
//   NEO_GRB     Pixels are wired for GRB bitstream, correct for neopixel stick
//   NEO_KHZ400  400 KHz bitstream (e.g. FLORA pixels)
//   NEO_KHZ800  800 KHz bitstream (e.g. High Density LED strip), correct for neopixel stick
//Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

//Stuff for sd logging
const int chipSelect = 10;
long lastReadTime = 0;        // the last time you read the sensor, in ms
const int record_interval = 1*1000; // the interval between sensor reads, in ms--> every 3 seconds-> will get 300 readings in 3 minutes
String todaysdate = "Jul142014"; //just forcing this, we need an extra chip or be able to sync to a computer or over wifi to get the real time.
int lastbpmcopy;

void setup() {
  pinMode(2, INPUT_PULLUP);        //for heptatic
  pinMode(blinkPin,OUTPUT);         // Pulse Sensor pin that will blink to your heartbeat!
  pinMode(fadePin,OUTPUT);          // Pulse Sensor pin that will fade to your heartbeat!
  Serial.begin(19200);
  interruptSetup();                 // sets up to read Pulse Sensor signal every 2mS 
  pixels.begin(); // This initializes the NeoPixel library for neopix not strand or trinket
  drv.begin();
  drv.selectLibrary(1);
  drv.setMode(DRV2605_MODE_INTTRIG); 
    Serial.print("Initializing SD card...");
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    return;
  }
  Serial.println("card initialized.");
}


void loop() {
    HRV(); //as soon as this is enabled (this is LED fade to BPM up/down), stops printing BPM to serial
    buttonState = digitalRead(2);
    lastBPM = BPM;
    ///lastbpmcopy = lastBPM;
    long currentTimeFile = millis();
    long elapsedFile = record_interval +  lastReadTime;
    if (currentTimeFile > elapsedFile) {
     String dataString = todaysdate+"," + String(currentTimeFile)+","+ String(lastBPM);
     //files don't overwrite; just appends data.
     File dataFile = SD.open("datalog7.txt", FILE_WRITE);
     if (dataFile) {
      dataFile.println(dataString);
      dataFile.close();
      Serial.println(dataString);
      lastReadTime =  millis();
     }
     // if the file isn't open, pop up an error:
      else {
        Serial.println("error opening datalog.txt");
      }
    }
    //Serial.println(BPM);
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
        // Serial.println("In here");
         drv.setWaveform(1, 86);  // play effect 
         drv.setWaveform(2, 0);       // end waveform
         drv.go();  //
      } 
    }
   if( (currentMillis - previousMillis) >= interval3)  {
      if(buzzflag) {
      Serial.println("BAM");
       Serial.println((currentMillis - previousMillis));
       drv.setWaveform(1, 86);  // play effect 
       drv.setWaveform(2, 0);       // end waveform
       drv.go();  //
    }
     buzzflag = false;
    }
   
   
  
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
    r = BRIGHTNESS - 1 - WheelPos % BRIGHTNESS;   //Red down
    g = WheelPos % BRIGHTNESS;      // Green up
    b = 0;                  //blue off
    break; 
  case 1:
    g = BRIGHTNESS - 1 - WheelPos % BRIGHTNESS;  //green down
    b = WheelPos % BRIGHTNESS;      //blue up
    r = 0;                  //red off
    break; 
  case 2:
    b = BRIGHTNESS - 1 - WheelPos % BRIGHTNESS;  //blue down 
    r = WheelPos % BRIGHTNESS;      //red up
    g = 0;                  //green off
    break; 
  }
  return(pixels.Color(r,g,b));
}














