/*
 Lark Buckingham
 //THIS CODE FOR FLORA
 changes to pulseSensor code for flora: http://pulsesensor.com/pages/pulse-sensor-amped-arduino-v1dot1
 Tried adding pulseSensor code -- get BPM to print but only from within interrupt....
 
 */
#include <Wire.h>
#include "Adafruit_GFX.h"
#include "LPD8806.h"
#include "SPI.h" 
#include <Adafruit_NeoPixel.h>

#define BRIGHTNESS  255

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
int pulsePin = 6;                 // Pulse Sensor purple wire connected to analog pin 0
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

//This is for HRV fade
boolean HRVUp = false;
//int c= 316; //color wheel seed
float cFloat = 316.0;


//Animation
//long currentMillis // assigned this in loop... 
long previousMillis = 0;
long interval1 = 60;

void setup() {
  pinMode(blinkPin,OUTPUT);         // Pulse Sensor pin that will blink to your heartbeat!
  pinMode(fadePin,OUTPUT);          // Pulse Sensor pin that will fade to your heartbeat!
  Serial.begin(19200);
  interruptSetup();                 // sets up to read Pulse Sensor signal every 2mS 
  pixels.begin(); // This initializes the NeoPixel library for neopix not strand or trinket
}


void loop() {
    HRV(); //as soon as this is enabled (this is LED fade to BPM up/down), stops printing BPM to serial
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














