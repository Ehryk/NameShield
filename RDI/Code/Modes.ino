
#define MODE_ON 0
#define MODE_BLINK_ALL 1
#define MODE_BLINK_ALL_FAST 2
#define MODE_SEQUENTIAL 3
#define MODE_SEQUENTIAL_FAST 4
#define MODE_WAVE 5
#define MODE_WAVE_FAST 6
#define MODE_BLINK_R 7
#define MODE_BLINK_D 8
#define MODE_BLINK_I 9
#define MODE_FADE_ALL 10
#define MODE_FADE_ALL_FAST 11
#define MODE_FADE_ALL_SLOW 12
#define MODE_BRIGHT 13
#define MODE_OFF 14

//Returns how long the mode took in milliseconds
unsigned long doMode(int m) {
  unsigned long modeStart = millis();
  switch(m) {
    case MODE_ON: modeOn(); break;
    case MODE_BLINK_ALL: modeBlink(1000); break;
    case MODE_BLINK_ALL_FAST: modeBlink(100); break;
    case MODE_SEQUENTIAL: modeSequential(1000); break;
    case MODE_SEQUENTIAL_FAST: modeSequential(100); break;
    case MODE_WAVE: modeWave(1000); break;
    case MODE_WAVE_FAST: modeWave(100); break;
    case MODE_BLINK_R: modeBlinkLetter(0, 1000); break;
    case MODE_BLINK_D: modeBlinkLetter(1, 1000); break;
    case MODE_BLINK_I: modeBlinkLetter(2, 1000); break;
    case MODE_FADE_ALL: modeFade(1000, 100); break;
    case MODE_FADE_ALL_FAST: modeFade(200, 50); break;
    case MODE_FADE_ALL_SLOW: modeFade(10000, 100); break;
    case MODE_BRIGHT: allOn(); break;
    case MODE_OFF: allOff(); break;
  }
  return millis() - modeStart;
}

void modeOn() {
  allPWM(brightness);
}

void modeBlink(int targetTime) {
  allPWM(brightness);
  delay(targetTime / 2);
  allOff();
  delay(targetTime / 2);
}

void modeSequential(int targetTime) {
  for (int l = 0; l < letters; l++) {
    indexPWM(l, brightness);
    delay(targetTime / letters / 2);
    indexOff(l);
    delay(targetTime / letters / 2);
  }
}

void modeWave(int targetTime) {
  for (int l = 0; l < letters; l++) {
    indexPWM(l, brightness);
    delay(targetTime / letters / 2);
  }
  for (int l = 0; l < letters; l++) {
    indexOff(l);
    delay(targetTime / letters / 2);
  }
}

void modeBlinkPin(int pin, int targetTime) {
  allPWM(brightness);
  if (pin < 0) return;
  
  pinOff(pin);
  delay(targetTime / 2);
  pinPWM(pin, brightness);
  delay(targetTime / 2);
}

void modeBlinkLetter(int index, int targetTime) {
  allPWM(brightness);
  indexOff(index);
  delay(targetTime / 2);
  indexPWM(index, brightness);
  delay(targetTime / 2);
}

void modeFade(int targetTime, int steps) {
  int s = brightness / steps;
  if (s < 1) s = 1;
  for (int i = 0; i < brightness; i += s) {
    allPWM(i);
    delay(targetTime / steps / 2);
  }
  for (int i = brightness; i > 0; i -= s) {
    allPWM(i);
    delay(targetTime / steps / 2);
  }
}
