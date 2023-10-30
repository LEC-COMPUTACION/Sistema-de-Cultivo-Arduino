#ifndef _RIEGO_H
#define _RIEGO_H

#include <Arduino.h>

class Riego{
  public:
    Riego(int PIN_BOMBA, int PIN_NIVELAGUA, int PIN_HUMEDAD, int PIN_LED, int RIEGO, int HUMEDAD);

    void ControlHumedad();

    void RiegoPlanta();

  private:
    int _PIN_BOMBA, _PIN_NIVELAGUA, _PIN_HUMEDAD, _PIN_LED ,_RIEGO, _HUMEDAD;
    int raw;

    int ReadSensor(int PIN_SENSOR);
    
    boolean NivelAgua();
   
    void Parpadeo();
    
    int Porcentaje();
};