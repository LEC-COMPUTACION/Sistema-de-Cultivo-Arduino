#ifndef _LUZ_H
#define _LUZ_H

#include <Arduino.h>

class Luz{
  public:
    Luz(int PIN_RGB, int NUM_LEDS):_pixels(NUM_LEDS, PIN_RGB, NEO_GRB + NEO_KHZ800);
    void Espectro(int R, int G, int B, int DELAY);
  private:
    Adafruit_NeoPixel _pixels;
    int _NUM_LEDS;
};

#endif