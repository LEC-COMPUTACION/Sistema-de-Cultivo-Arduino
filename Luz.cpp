#include "Luz.h"
#include <Adafruit_NeoPixel.h>

Luz::Luz(int PIN_RGB, int NUM_LEDS):_pixels(NUM_LEDS, PIN_RGB, NEO_GRB + NEO_KHZ800){
    this->_NUM_LEDS=NUM_LEDS;
    _pixels.begin();
    _pixels.clear();
}

Luz::void Espectro(int R, int G, int B, int DELAY){
    for(int i=0; i<_NUM_LEDS;i++){
    _pixels.setPixelColor(i, _pixels.Color(R, G, B));
    _pixels.show();
    delay(DELAY);
    }
}
