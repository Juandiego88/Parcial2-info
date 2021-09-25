#include "imagen.h"

Imagen::Imagen(string name)
{
   imagen=new QImage(name.c_str());
   ancho=imagen->width();
   largo=imagen->height();
   dimenx=ancho/leds;
   dimeny=largo/leds;


}

void Imagen::analisis()
{
    bool band=true;
    float cont1=0,cont2=0;
    int pixelrojo,pixelazul,pixelverde,poselegida,aux0,aux1=0;

    for(int i=0;i<16;i++){ // i filas
        for(int j=0;j<16;j++){// j columnas
            for(cont1=(i*dimenx);cont1<(dimenx*(i+1)-1);cont1++){

                for(cont2=(j*dimeny);cont2<(dimeny*(j+1)-1);cont2++){

                    pixelrojo=imagen->pixelColor(cont1,cont2).red();
                    pixelazul=imagen->pixelColor(cont1,cont2).blue();
                    pixelverde=imagen->pixelColor(cont1,cont2).green();

                    rojo.push_back(pixelrojo);
                    azul.push_back(pixelazul);
                    verde.push_back(pixelverde);
                    if(rojosin.size()==0){
                        rojosin.push_back(pixelrojo);
                        band=false;
                    }

                    else{
                        band=true;
                        for(unsigned int ite=0;ite<(rojosin.size());ite++){
                            if(rojosin[ite]==pixelrojo){
                                band=false;
                            }
                        }
                    }
                    if(band==true) rojosin.push_back(pixelrojo);



                    if(azulsin.size()==0){
                        azulsin.push_back(pixelazul);
                        band=false;
                    }
                    else{
                        band=true;
                        for(unsigned int ite=0;ite<(azulsin.size());ite++){
                            if(azulsin[ite]==pixelazul){
                                band=false;
                            }
                        }
                    }
                    if(band==true) azulsin.push_back(pixelazul);


                    if(verdesin.size()==0){
                        verdesin.push_back(pixelverde);
                        band=false;
                    }

                    else{
                        band=true;
                        for(unsigned int ite=0;ite<(verdesin.size());ite++){
                            if(verdesin[ite]==pixelverde){
                                band=false;
                            }
                        }
                    }
                    if(band==true) verdesin.push_back(pixelverde);

                }
            }
            for(unsigned int it=0;it<(rojosin.size());it++){
                aux0=0;
                for(unsigned int ite=0;ite<rojo.size();ite++){
                    if(rojosin[it]==rojo[ite]){
                        aux0++;
                    }

                }
                if(aux0>aux1){
                    aux1=aux0;
                    poselegida=it;
                }
            }
            Mrojo[i][j]=rojosin[poselegida];
            aux1=0;

            for(unsigned int it=0;it<(azulsin.size());it++){
                aux0=0;
                for(unsigned int ite=0;ite<azul.size();ite++){
                    if(azulsin[it]==azul[ite]){
                        aux0++;
                    }

                }
                if(aux0>aux1){
                    aux1=aux0;
                    poselegida=it;
                }
            }
            Mazul[i][j]=azulsin[poselegida];
            aux1=0;
            for(unsigned int it=0;it<verdesin.size();it++){
                aux0=0;
                for(unsigned int ite=0;ite<verde.size();ite++){
                    if(verdesin[it]==verde[ite]){
                        aux0++;
                    }

                }
                if(aux0>aux1){
                    aux1=aux0;
                    poselegida=it;
                }
            }
            Mverde[i][j]=verdesin[poselegida];
            aux1=0;
            rojo.clear();
            azul.clear();
            verde.clear();
            rojosin.clear();
            azulsin.clear();
            verdesin.clear();
        }

    }

}

void Imagen::mostrar()
{
    ////////////CODIGO PARA IMPRIMIR 3 ARREGLOS INDIVIDUALES DE 256
          /*  cout<<"\n\nbyte rojos[256] = {";
            for(int i=0;i<16;i++) {
                for(int j=0;j<16;j++) {
                    if(i==15 && j==15)
                        cout<<Mrojo[(j)][(i)]<<"};";
                    else
                        cout<<Mrojo[(j)][(i)]<<",";
                }
                cout<<endl;
            }

            cout<<"\n\nbyte verdes[256] = {";
            for(int i=0;i<16;i++) {
                for(int j=0;j<16;j++) {
                    if(i==15 && j==15)
                        cout<<Mverde[(j)][(i)]<<"};";
                    else
                        cout<<Mverde[(j)][(i)]<<",";
                }
                cout<<endl;
            }

            cout<<"\n\nbyte azules[256] = {";
            for(int i=0;i<16;i++) {
                for(int j=0;j<16;j++) {
                    if(i==15 && j==15)
                        cout<<Mazul[(j)][(i)]<<"};";
                    else
                        cout<<Mazul[(j)][(i)]<<",";
                }
                cout<<endl;
            }*/
    /////////CODIGO PARA IMPREMIR EL ARREGLO DE 256 LEDS RGB {R,G,B}
            cout<<"{";
            for(int i=0;i<16;i++) {
                for(int j=0;j<16;j++){
                    if(i==15 && j==15) {
                        cout<<"{"<<Mrojo[(j)][(i)]<<","<<Mverde[(j)][(i)]<<","<<Mazul[(j)][(i)]<<"};";
                    }
                    else{
                        cout<<"{"<<Mrojo[(j)][(i)]<<","<<Mverde[(j)][(i)]<<","<<Mazul[(j)][(i)]<<"},";
                    }
                }
                cout<<endl;
            }
            cout<<"};\n\n";


}

Imagen::~Imagen()
{
    delete imagen;
}
