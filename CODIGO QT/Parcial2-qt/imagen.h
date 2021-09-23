#ifndef IMAGEN_H
#define IMAGEN_H
#include <iostream>
#include <QImage>
#include <map>
#include <vector>
using namespace std;
#define leds 16

class Imagen
{
public:
    Imagen(string name);
    
private:

    QImage *imagen;
    float ancho,largo,dimenx,dimeny;
    vector<int> rojo;
    vector<int> verde;
    vector<int> azul;
    int Mrojo[leds][leds],Mverde[leds][leds],Mazul[leds][leds];

    
    
    
};

#endif // IMAGEN_H
