void textScroll1() {
  int r = random(0,9); // int to choose string from array
  String l = BPM1[r]; // write string to variable l (for length)
  int length = (l.length()); // calculate length of string and store it in int length
  // scroll each text for length of string + 33 (length of matrix + a little space to breath)
  for (int16_t x=16; x>=-(length*5+33); x=x-2) { 
    matrix.clear();
    matrix.setCursor(x,0);
    //matrix.print("Unpredictable   Might Be Lying   Unsafe   RUN RUN");
    matrix.print(BPM1[r]);
    matrix.writeDisplay();
    delay(100);

    //break if button pressed
    buttonState = digitalRead(6);
    if((buttonState != lastButtonState) && (buttonState == 0)){ //have to make it so that if button state goes from 1 to 0...
      break;
    }
    lastButtonState = buttonState;
  } 
}

void textScroll2() {
  int r = random(0,9); // int to choose string from array
  String l = BPM2[r]; // write string to variable l (for length)
  int length = (l.length()); // calculate length of string and store it in int length
  // scroll each text for length of string + 33 (length of matrix + a little space to breath)
  for (int16_t x=16; x>=-(length*5+33); x=x-2) { 
    matrix.clear();
    matrix.setCursor(x,0);
    //matrix.print("Unpredictable   Might Be Lying   Unsafe   RUN RUN");
    matrix.print(BPM2[r]);
    matrix.writeDisplay();
    delay(100);

    //break if button pressed
    buttonState = digitalRead(6);
    if((buttonState != lastButtonState) && (buttonState == 0)){ //have to make it so that if button state goes from 1 to 0...
      break;
    }
    lastButtonState = buttonState;
  } 
}

/*
void textScroll3() {
  int r = random(0,9); // int to choose string from array
  String l = BPM3[r]; // write string to variable l (for length)
  int length = (l.length()); // calculate length of string and store it in int length
  // scroll each text for length of string + 33 (length of matrix + a little space to breath)
  for (int16_t x=16; x>=-(length*5+33); x=x-2) { 
    matrix.clear();
    matrix.setCursor(x,0);
    //matrix.print("Unpredictable   Might Be Lying   Unsafe   RUN RUN");
    matrix.print(BPM3[r]);
    matrix.writeDisplay();
    delay(100);

    //break if button pressed
    buttonState = digitalRead(6);
    if((buttonState != lastButtonState) && (buttonState == 0)){ //have to make it so that if button state goes from 1 to 0...
      break;
    }
    lastButtonState = buttonState;
  } 
}


void textScroll4() {
  int r = random(0,9); // int to choose string from array
  String l = BPM4[r]; // write string to variable l (for length)
  int length = (l.length()); // calculate length of string and store it in int length
  // scroll each text for length of string + 33 (length of matrix + a little space to breath)
  for (int16_t x=16; x>=-(length*5+33); x=x-2) { 
    matrix.clear();
    matrix.setCursor(x,0);
    //matrix.print("Unpredictable   Might Be Lying   Unsafe   RUN RUN");
    matrix.print(BPM4[r]);
    matrix.writeDisplay();
    delay(100);

    //break if button pressed
    buttonState = digitalRead(6);
    if((buttonState != lastButtonState) && (buttonState == 0)){ //have to make it so that if button state goes from 1 to 0...
      break;
    }
    lastButtonState = buttonState;
  } 
}

*/



