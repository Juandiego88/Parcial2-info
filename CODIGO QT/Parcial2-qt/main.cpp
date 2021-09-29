#include <iostream>
#include <imagen.h>

using namespace std;

int main()
{

    //Imagen a("../Parcial2-qt/imagenes/japon.jpg");
    //Imagen a("../Parcial2-qt/imagenes/col.jpg");
    //Imagen a("../Parcial2-qt/imagenes/antioquia.jpg");

    //Imagen a("../Parcial2-qt/imagenes/bandera-alemania.jpg");
    //Imagen a("../Parcial2-qt/imagenes/brasil.jpg");
    Imagen a("../Parcial2-qt/imagenes/inglaterra.jpg");
    a.analisis();
    a.mostrar();
    return 0;
}
