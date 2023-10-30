#include "Reloj.h"
#include <Ds1302.h>

Reloj::Reloj(int PIN_ENA, int PIN_CLK, int PIN_DAT):_rtc(PIN_ENA, PIN_CLK, PIN_DAT){
    _rtc.init();
}

Reloj::int* getHora(){
    Ds1302::DateTime now;
    _rtc.getDateTime(&now);
    if (now.hour < 10) Hora[0]=0;
    Hora[0]=now.hour;    // 00-23
    if (now.minute < 10) Hora[1]=0;
    Hora[1]=now.minute;  // 00-59
    if (now.second < 10) Hora[2]=0;
    Hora[2]=now.second;  // 00-59
    return Hora;
}

Reloj::int* getFecha(){
    Ds1302::DateTime now;
    _rtc.getDateTime(&now);    
    Fecha[0]=(2000+now.year); // 00-99
    if (now.month < 10) Fecha[1]=0;
    Fecha[1]=now.month;// 01-12
    if (now.day < 10) Fecha[2]=0;
    Fecha[2]=now.day;// 01-31
    return Fecha;
}

Reloj::String getDia(){
    Ds1302::DateTime now;
    _rtc.getDateTime(&now);
    return (WeekDays[now.dow-1]); // 1-7
}

Reloj::String MostrarHora(){
    int* Hora=getHora();
    Linea=String(Hora[0])+":"+String(Hora[1])+":"+String(Hora[2]);
    return Linea;
}

Reloj::String MostrarFecha(){
    int* Fecha=getFecha();
    Linea=String(Fecha[0])+"/"+String(Fecha[1])+"/"+String(Fecha[2]);
    return Linea;
}
