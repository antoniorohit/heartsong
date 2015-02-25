void buttonCounter() {
   //increment button counter
  buttonState = digitalRead(6); //read button1 input
  //Serial.println(buttonState);
  if (buttonState != lastButtonState) { //compare to previous
    if (buttonState == LOW) { //it is 0 when clicked
      buttonPushCounter++; //increment
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    }
    else { //if it went from high to low then do nothing
    }
  }
  lastButtonState = buttonState;
}
