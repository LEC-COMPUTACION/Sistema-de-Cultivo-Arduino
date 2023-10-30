#include "Riego.h"

Riego(int PIN_BOMBA, int PIN_NIVELAGUA, int PIN_HUMEDAD, int PIN_LED, int RIEGO, int HUMEDAD){
    this->_PIN_BOMBA=PIN_BOMBA;
    this->_PIN_NIVELAGUA=PIN_NIVELAGUA;
    this->_PIN_HUMEDAD=PIN_HUMEDAD;
    this->_PIN_LED=PIN_LED;
    this->_RIEGO=RIEGO;
    this->_HUMEDAD=HUMEDAD;
    pinMode(_PIN_BOMBA, OUTPUT);
    pinMode(_PIN_LED, OUTPUT);
    digitalWrite(_PIN_BOMBA,LOW);
    digitalWrite(_PIN_LED,LOW);
}

void ControlHumedad(){
    int SueloHumedo=ReadSensor(_PIN_HUMEDAD);
    if(SueloHumedo<Porcentaje())
    {
    RiegoPlanta();
    }
}

void RiegoPlanta(){
    if(NivelAgua()){
    digitalWrite(_PIN_BOMBA, HIGH);
    delay(_RIEGO);
    digitalWrite(_PIN_BOMBA,LOW);
    delay(100);
    }else{
    Parpadeo();
    }
}

int ReadSensor(int PIN_SENSOR){
    raw=analogRead(PIN_SENSOR);
    return raw;
}

boolean NivelAgua(){
    if(ReadSensor(_PIN_NIVELAGUA)>200){
    return true;
    }else{
    return false;
    }
}

void Parpadeo(){
    for(int i=0; i<10;i++){
    digitalWrite(_PIN_LED, HIGH);
    delay(200);
    digitalWrite(_PIN_LED,LOW);
    delay(200);
    }
}

int Porcentaje(){
    int valor = (_HUMEDAD / 100.0) * 1024;
    return valor;
}
