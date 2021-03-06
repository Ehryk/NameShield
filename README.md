NameShield
==========

This is an Arduino based project that flashes text or a name on a shield, with various modes and brightnesses selectable via tact switches. It uses PWM output pins (six on an Arduino Uno/Duemilanove) to control brightness levels when necessary. I designed the circuit boards in Fritzing, then ordered them from their fabrication plant, and soldered the LEDs on.

![Eric LEDs On](https://raw2.github.com/Ehryk/NameShield/master/Documentation/Pictures/6%20-%20Eric%20LEDs%20On.jpg)

See the assembled ones on YouTube in various modes:
 - Eric [View on YouTube](https://www.youtube.com/watch?v=vqsRCEPevEo)
 - Bill [View on YouTube](https://www.youtube.com/watch?v=BqNwpaYB2X8)
 - Matt [View on YouTube](https://www.youtube.com/watch?v=KLYUQCO8-6A)

**Code**

These are the code files that drive the Name shields with LEDs.

Current Modes (you can easily write your own, be sure to customize them in the Modes.ino file):

 1. All On
 1. Blink All (at once)
 1. Blink All (at once) - Fast
 1. Sequential
 1. Sequential - Fast
 1. Wave
 1. Wave - Fast
 1. Blink Dot of i (if applicable)
 1. Blink First Letter
 1. Blink Second Letter
 1. Blink Third Letter
 1. Blink Fourth Letter (if applicable)
 1. Fade All
 1. Fade All - Fast
 1. Fade All - Slow
 1. All Bright
 1. All Off

**Schematics**

These are Fritzing .fzz files that define PCB schematics that can be ordered as Arduino shields. Visit [Fritzing](http://www.fritzing.org) for more information.

**Implementations**

Currently, I have built `Eric`, `Matt`, `Bill`, and `RDI`. If you'd like me to make one for you, [Email Me](mailto:ehryk42@gmail.com) or download fritzing and the Arduino IDE and build your own!

Here are some of the other variants:

![Bill LEDs On](https://raw2.github.com/Ehryk/NameShield/master/Documentation/Pictures/7%20-%20Bill%20LEDs%20On.jpg)
![Matt LEDs On](https://raw2.github.com/Ehryk/NameShield/master/Documentation/Pictures/8%20-%20Matt%20LEDs%20On.jpg)
![RDI LEDs On](https://raw2.github.com/Ehryk/NameShield/master/Documentation/Pictures/RDI%206%20-%20Angled.jpg)