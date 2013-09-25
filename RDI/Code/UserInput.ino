
const float e = 2.71828;

boolean handleInput() {
  boolean buttonPressed = false;
  
  if (checkPress(modePin)) {
    mode++;
    if (mode > MODE_OFF) mode = 0;
    
    //Wait for release
    while(digitalRead(modePin) == LOW) { allOff(); }
    
    delay(100);
    buttonPressed = true;
  }
  
  return buttonPressed;
}

//This now uses a Logistic Function (S-Curve): https://en.wikipedia.org/wiki/Logistic_function
//This is to map the linear curve from the potentiometer to the apparent brightness from the PWMed LEDs to the human eye
//At the low end, small changes in input map to large changes in apparent brightness
//At the high end, small changes in PWM are better to avoid spikey apparent brightness
//Standard Logistic Function: f(x) = 1/(1+pow(e, -x));
//I stretch, shift, and flip it about the Y axis (so that the potentiometer rotates clockwise for 'up')
//More reading: http://electronics.stackexchange.com/questions/1983/correcting-for-non-linear-brightness-in-leds-when-using-pwm
int getBrightness(int pin) {
  float curveStretch = 100; //Lower values = faster ramp up, higher values = slower ramp up
  float curveShift = 400; //511 would center the curve, 400 favors more variance in the low end
  int linear = analogRead(pin); //Linear variance, 0-1023
  //return round(pow(2,((linear/4+1)/32))-1); //Close, but chunky (lost resolution)
  //return (((1<<(linear/4/32))-1) + ((1<<(linear/4/32))*(((linear/4)%32)+1)+15)/32); //Better... (lost resolution)
  float logistic = 1/(1+pow(e, (linear-curveShift)/curveStretch));
  return logistic * 255;
}

int getLoudness(int pin) {
  return analogRead(pin)/4;
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
