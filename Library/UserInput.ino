
boolean handleInput() {
  boolean buttonPressed = false;
  
  if (checkPress(modePin)) {
    mode++;
    if (mode > MODE_OFF) mode = 0;
    
    //Wait for release
    while(digitalRead(modePin) == LOW) { allOn(); }
    
    delay(100);
    buttonPressed = true;
  }
  if (checkPress(brightnessPin)) {
    if (brightness < 45) brightness += 5;
    else brightness += 15;
    if (brightness > 255) brightness = 0;
    buttonPressed = true;
  }
  
  return buttonPressed;
}

//Checks if a button is pressed
boolean checkPress(int pin) {
  return digitalRead(pin) == LOW && debounce(pin, LOW, 20, 6);
}

//Software Debounce of a swtich
boolean debounce(int pin, int v, int timeDelay, int bounceCount) {
  int toCheck = bounceCount;
  while (toCheck > 0) {
    delay(timeDelay);
    if (digitalRead(pin) != v) return false;
    toCheck --;
  }
  return true;
}
