/*
NameShield LED Driver
Eric Menze
http://www.github.com/Ehryk
*/

//Configure Letters
/* Matt */
int letters = 4;
char* letter[4] = {"M", "a", "1t", "2t"};
int pinCount[4] = {1, 1, 1, 1};
int letterPin[4][2] = {{3}, {5}, {9}, {11}};
int dotPin = -1; //Not Used
int modePin = 4;
int brightnessPin = 12;


int mode = 0;
int brightness = 20;
unsigned long modeTime;

boolean debug = true;
unsigned long lastDebugOutput = 0;
unsigned long debugInterval = 900;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  //Initialize letter pins to outputs
  for(int l = 0; l < letters; l++) {
    for(int p = 0; p < pinCount[l]; p++) {
      pinMode(letterPin[l][p], OUTPUT);
    }
  }
  
  pinMode(modePin, INPUT); //Set to an input to read switch status
  digitalWrite(modePin, HIGH); //Use internal pull-up resistor
  pinMode(brightnessPin, INPUT); //Set to an input to read switch status
  digitalWrite(brightnessPin, HIGH); //Use internal pull-up resistor
}

void loop() {
  handleInput();
  
  modeTime = doMode(mode);
  
  if (debug && millis() - lastDebugOutput > debugInterval) debugWrite();
}

void debugWrite() {
  Serial.print("Mode: ");
  Serial.print(mode);
  Serial.print(" (");
  Serial.print(modeTime);
  Serial.println("ms)");
  
  Serial.print("Brightness: ");
  Serial.println(brightness);
  
  Serial.print("Vcc: ");
  Serial.print(readVcc());
  Serial.println("mV");
  
  Serial.println();
  
  lastDebugOutput = millis();
}

long readVcc() {
  long result;
  // Read 1.1V reference against AVcc
  ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
  delay(2); // Wait for Vref to settle
  ADCSRA |= _BV(ADSC); // Convert
  while (bit_is_set(ADCSRA,ADSC));
  result = ADCL;
  result |= ADCH<<8;
  result = 1108000L / result; // Back-calculate AVcc in mV
  return result;
}
