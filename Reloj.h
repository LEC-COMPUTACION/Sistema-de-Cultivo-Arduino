#ifndef _RELOJ_H
#define _RELOJ_H

#include <Arduino.h>

const static char* WeekDays[] =
{
    "Domingo",
    "Lunes",
    "Martes",
    "Miercoles",
    "Jueves",
    "Viernes",
    "Sabado"
};

class Reloj{
  public:
    Reloj(int PIN_ENA, int PIN_CLK, int PIN_DAT):_rtc(PIN_ENA, PIN_CLK, PIN_DAT);

    int* getHora();

    int* getFecha();

    String getDia();

    String MostrarHora();

    String MostrarFecha();

    private:  
      Ds1302 _rtc;
      int* Fecha = new int[3];
      int* Hora = new int[3];
      String Linea;
};