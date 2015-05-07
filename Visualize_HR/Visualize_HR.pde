// Graphing sketch for Processing
 
 
// This program takes ASCII-encoded strings containing floating point numbers
// from the serial port at 9600 baud and graphs them. It expects values in the
// range -1.0 to 1.0, followed by a newline, or newline and carriage return
 
// Created 20 Apr 2005
// Updated 18 Jan 2008 by Tom Igoe
// Adapted 16 Sep 2014 by Bjoern Hartmann for mbed
// This example code is in the public domain.
 
import processing.serial.*;
 
Serial myPort;        // The serial port
int xPos = 1;         // horizontal position of the graph
 
float minVal=50.0;
float maxVal=1100;
 
void setup () {
  // set the window size:
  size(1000, 600);        
 
  // List all the available serial ports
  println(Serial.list());
  // Open whatever port is the one you're using.
  myPort = new Serial(this, Serial.list()[3]", 19200);
  // don't generate a serialEvent() unless you get a newline character:
  myPort.bufferUntil('\n');
  // set inital background:
  background(0);
}
void draw () {
  // everything happens in the serialEvent()
}
 
void serialEvent (Serial myPort) {
  // get the ASCII string:
  String inString = myPort.readStringUntil('\n');
 
  if (inString != null) {
    // trim off any whitespace:
    inString = trim(inString);
    // convert to an int and map to the screen height:
    float inFloat = float(inString); 
    float screenY = map(inFloat, minVal, maxVal, 0, height);
 
    // draw the line from bottom of screen to desired height
    stroke(127, 34, 255);
    line(xPos, height, xPos, height - screenY);
 
    // at the edge of the screen, go back to the beginning:
    if (xPos >= width) {
      xPos = 0;
      background(0);
    } else {
      // increment the horizontal position:
      xPos++;
    }
  }
}

 
            
