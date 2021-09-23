//Importamos esta libreria necesaria para el manejo de los neopixel
#include<Adafruit_NeoPixel.h>

//definimos el puerto de entrada
int neopixelPin = 2;
//definimos el numero de leds (# de filas * 16)
int no_ofPixels = 256;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(no_ofPixels, neopixelPin, NEO_GRB + NEO_KHZ800);

void setup()
{
  pixels.begin();
}

void loop()
{
  //pixels.setPixelColor(# bombillo, pixels.Color(R,G,B));
  pixels.setPixelColor(0, pixels.Color(255,0,0));
  
  pixels.setPixelColor(1, pixels.Color(255,0,0));
  
  pixels.setPixelColor(15, pixels.Color(255,0,0));

  pixels.setPixelColor(16, pixels.Color(255,0,0));
  
  pixels.setPixelColor(18, pixels.Color(0,255,0));
   
  pixels.setPixelColor(32, pixels.Color(0,255,0));
  
  pixels.setPixelColor(48, pixels.Color(0,0,255));
  
  pixels.setPixelColor(64, pixels.Color(0,0,255));
  
  pixels.setPixelColor(79, pixels.Color(0,0,255));
  
  pixels.setPixelColor(80, pixels.Color(0,0,255));
  
  pixels.setPixelColor(96, pixels.Color(0,255,255));

  pixels.setPixelColor(112, pixels.Color(255,0,255));
  
  pixels.setPixelColor(128, pixels.Color(0,255,255));
  
  pixels.setPixelColor(144, pixels.Color(0,255,255));
  
  pixels.setPixelColor(160, pixels.Color(0,255,255));
  
  pixels.setPixelColor(176, pixels.Color(0,255,255));
  
  pixels.setPixelColor(192, pixels.Color(0,255,255));
  
  pixels.setPixelColor(208, pixels.Color(0,255,255));
  
  pixels.setPixelColor(224, pixels.Color(0,255,255));
  
  pixels.setPixelColor(240, pixels.Color(0,255,255));
  
  //Despues de asignar todos los datos, mostramos a traves de la ste función
  pixels.show();


  
}