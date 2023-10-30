#include "Luz.h"
#include "Reloj.h"
#include "Riego.h"

Reloj r(2,3,4);
Luz l(5,16);
Riego riego(6,A0,A1,7,1000,50);
int* EnciendeLuz[]={15,43,0};
int* ApagaLuz[]={15,44,0};
boolean e=true;
boolean a=true;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  //l.Espectro(10,100,10,50);
  Serial.println(r.getDia());
  Serial.println(r.MostrarFecha());
  Serial.println(r.MostrarHora());
  
  ControlLuz();
  riego.ControlHumedad();
  delay(1000);
} 

void ControlLuz()
{
  int* Hora=r.getHora();
  if(EnciendeLuz[0]==Hora[0] && EnciendeLuz[1]==Hora[1] && a)
  {
    Serial.println("Enciende luz");
    l.Espectro(255,15,255,1000);
    a=false;
    e=true;
  }  
  else if(ApagaLuz[0]==Hora[0] && ApagaLuz[1]==Hora[1] && e)
  {
    Serial.print("ApagaLuz");
    l.Espectro(0,0,0,500);
    e=false;
    a=true;
  }  
}
