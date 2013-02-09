
void allOn() {
  for(int l = 0; l < letters; l++) {
    indexOn(l);
  }
}

void allOff() {
  for(int l = 0; l < letters; l++) {
    indexOff(l);
  }
}

void allPWM(int brightness) {
  for(int l = 0; l < letters; l++) {
    indexPWM(l, brightness);
  }
}

/* Handle Indexes */

void indexOn(int index) {
  for(int p = 0; p < pinCount[index]; p++) {
    pinOn(letterPin[index][p]);
  }
}

void indexOff(int index) {
  for(int p = 0; p < pinCount[index]; p++) {
    pinOff(letterPin[index][p]);
  }
}

void indexPWM(int index, int brightness) {
  for(int p = 0; p < pinCount[index]; p++) {
    pinPWM(letterPin[index][p], brightness);
  }
}

/* Handle Chars */

boolean charOn(char* c) {
  if (!hasLetter(c)) return false;
  int index = indexOf(c);
  for(int p = 0; p < pinCount[index]; p++) {
    pinOn(letterPin[index][p]);
  }
}

boolean charOff(char* c) {
  if (!hasLetter(c)) return false;
  int index = indexOf(c);
  for(int p = 0; p < pinCount[index]; p++) {
    pinOff(letterPin[index][p]);
  }
}

boolean charPWM(char* c, int brightness) {
  if (!hasLetter(c)) return false;
  int index = indexOf(c);
  for(int p = 0; p < pinCount[index]; p++) {
    pinPWM(letterPin[index][p], brightness);
  }
}

/* Handle Pins */

void pinOn(int pin) {
  digitalWrite(pin, HIGH);
}

void pinOff(int pin) {
  digitalWrite(pin, LOW);
}

void pinPWM(int pin, int brightness) {
  analogWrite(pin, brightness);
}

/* Search Letter Array */

int indexOf(char* c) {
  int index = -1;
  for(int l = 0; l < letters; l++) {
    if (strcmp(letter[l], c) == 0) index = l;
  }
  return index;
}

boolean hasLetter(char* c) {
  int index = indexOf(c);
  return index != -1;
}

int strcmp(const char *s1, const char *s2)
{
  while (*s1==*s2)
  {
    if(*s1=='\0')
    return(0);
    s1++;
    s2++;
  }
  return(*s1-*s2);
}
