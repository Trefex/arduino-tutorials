/*
 Standalone Module for proof of concept of 74HC595 Shift Register controlling 4 LEDs (up to 8 possible)
 
 Blog: http://arduinodev.woofex.net/2013/01/26/74hc595_shiftregister/
 Code: https://github.com/Trefex/arduino-shiftregister/

 For Pin connections, please check the Blog or the github project page
 Authors: Christophe Trefois (Trefex)
 Changelog:
   2013-01-26: Initial Import of code

 This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License. 
 To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/3.0/ or send a letter 
 to Creative Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA. 
 */
 
int latchPin = 10;
int clockPin = 13;
int dataPin = 7;

void setup() {
   // Set output pins of the UNO
   pinMode(latchPin, OUTPUT);
   pinMode(clockPin, OUTPUT);
   pinMode(dataPin, OUTPUT);
}

void loop() {
   for (int i=0; i<16; i++) {
     digitalWrite(latchPin, LOW);
     delay(400);
     shiftOut(dataPin, clockPin, MSBFIRST, i);
     digitalWrite(latchPin, HIGH);
     delay(100);
   }
}
