
#ifndef NameShield_h
#define NameShield_h

#include "Arduino.h"

class NameShield
{
	public:
		void allOn();
		void allOff();
		void allPWM(int brightness);

		void indexOn(int index);
		void indexOff(int index);
		void indexPWM(int index, int brightness);

		boolean charOn(char* c);
		boolean charOff(char* c);
		boolean charPWM(char* c, int brightness);

		void pinOn(int pin);
		void pinOff(int pin);
		void pinPWM(int pin, int brightness);

		int indexOf(char* c);
		boolean hasLetter(char* c);
		int strcmp(const char *s1, const char *s2);

		boolean checkPress(int pin);

		boolean debounce(int pin, int v, int timeDelay, int bounceCount);
	
	private:
};

#endif