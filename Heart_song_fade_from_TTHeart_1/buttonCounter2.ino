void buttonCounter2() 
{ //increment button counter
  buttonState2 = digitalRead(12); //read button1 input
  if (buttonState2 != lastButtonState2) { //compare to previous
    if (buttonState2 == LOW) { //if it is high then it was clicked.. increment
      buttonPushCounter2++;
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter2);
    }
    else { //if it went from high to low then do nothing
    }
  }
  lastButtonState2 = buttonState2;
}
