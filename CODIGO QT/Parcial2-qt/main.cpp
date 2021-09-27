#include <iostream>
#include <imagen.h>

using namespace std;

int main()
{
    //Imagen a("../Parcial2-qt/imagenes/japon.jpg");
    //Imagen a("../Parcial2-qt/imagenes/col.jpg");
    //Imagen a("../Parcial2-qt/imagenes/antioquia.jpg");
    Imagen a("../Parcial2-qt/imagenes/islas.jpg");
    //Imagen a("../Parcial2-qt/imagenes/bandera-alemania.jpg");

    a.analisis();
    a.mostrar();
    return 0;
}
