#include "imagen.h"

Imagen::Imagen(string name)
{
    imagen=new QImage(name.c_str());
       ancho=imagen->width();
       largo=imagen->height();
       dimenx=ancho/leds;
       dimeny=largo/leds;
       for(int i =0;i<dimenx*(i+1);){
           for(int j=0;;){

           }
           
       }
}
