/*
 Lark Buckingham
 Tried adding pulseSensor code -- get BPM to print but only from within interrupt....
 Adapted from PulseSensor code and Heart Badge by Becky Stern for Adafruit Industries
 Based on sample code from http://learn.parallax.com/KickStart/28048
 */
#include <Wire.h>
#include "Adafruit_GFX.h"
#include "LPD8806.h"
#include "SPI.h" 
#include <Adafruit_NeoPixel.h>

#define BRIGHTNESS  128
#define PIXEL_PIN    6    // Digital IO pin connected to the NeoPixels.
#define PIXEL_COUNT 16

#ifdef __AVR_ATtiny85__
#include <avr/power.h>
#endif

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
int blinkPin = 13;                // pin to blink led at each beat
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
int lastButtonState = 0; //previous state
int buttonPushCounter2 = 0; // counter for number of button presses
int buttonState2 = 0;  //current state of the button
int lastButtonState2 = 0; //previous state

//This is for HRV fade
boolean HRVUp = false;
float cFloat = 316.0;  // make float   NEED TO CONSTRAIN SO c DOESN;t DROP BELOW 0
int c= 316; //color wheel seed


//Animation
//long currentMillis // assigned this in loop... 
long previousMillis = 0;
long interval1 = 60;



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
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  pinMode(blinkPin,OUTPUT);         // Pulse Sensor pin that will blink to your heartbeat!
  pinMode(fadePin,OUTPUT);          // Pulse Sensor pin that will fade to your heartbeat!
  Serial.begin(9600);
  interruptSetup();                 // sets up to read Pulse Sensor signal every 2mS 
  strip.begin();  // Start up the LED strip 
  strip.show(); // Update the strip, to start they are all 'off'
}


void loop() {
  if((Pulse == true)){
    Serial.print("BPM = ");
    Serial.println(BPM);
    HRV(); //as soon as this is enabled (this is LED fade to BPM up/down), stops printing BPM to serial
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
  return(strip.Color(r,g,b));
}














