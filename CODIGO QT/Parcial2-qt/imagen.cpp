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
    float cont1=0,cont2=0;
    int pixelrojo,pixelazul,pixelverde,poselegida,aux0,aux1=0;

    for(int i=0;1<=15;i++){ // i filas
        for(int j=0;j<=15;j++){// j columnas
            for(cont1=(i*dimenx);cont1<(dimenx*(i+1));cont1++){//11.75 dimeny 16.75 dimenx

                for(cont2=(j*dimeny);cont2<(dimeny*(j+1));cont2++){

                    pixelrojo=imagen->pixelColor(cont1,cont2).red();
                    pixelazul=imagen->pixelColor(cont1,cont2).blue();
                    pixelverde=imagen->pixelColor(cont1,cont2).green();
                    rojo.push_back(pixelrojo);
                    azul.push_back(pixelazul);
                    verde.push_back(pixelverde);

                    if(rojosin.size()==0){
                        rojosin.push_back(pixelrojo);

                    }
                    else{
                        for(int ite=0;ite<rojosin.size();ite++){
                            if(rojosin[ite]!=pixelrojo){
                                rojosin.push_back(pixelrojo);
                            }
                        }

                    }

                    if(azulsin.size()==0){
                        azulsin.push_back(pixelazul);

                    }
                    else{
                        for(int ite=0;ite<azulsin.size();ite++){
                            if(azulsin[ite]!=pixelazul){
                                azulsin.push_back(pixelazul);
                            }
                        }

                    }

                    if(verdesin.size()==0){
                        verdesin.push_back(pixelverde);

                    }
                    else{
                        for(int ite=0;ite<verdesin.size();ite++){
                            if(verdesin[ite]!=pixelverde){
                                verdesin.push_back(pixelverde);
                            }
                        }

                    }

                }
            }

            for(int it=0;it<rojosin.size();it++){
                aux0=0;
                for(int ite=0;rojo.size();ite++){
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

            for(int it=0;it<azulsin.size();it++){
                aux0=0;
                for(int ite=0;azul.size();ite++){
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
            for(int it=0;it<verdesin.size();it++){
                aux0=0;
                for(int ite=0;verde.size();ite++){
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
    int digi;
        string str;
        cout<<"\n//////////////// Matriz pixeles rojos ////////////////"<<endl;
        for(int i=0;i<16;i++){
            for(int j=0;j<16;j++){
                cout<<Mrojo[int(j)][int(i)];
                str=to_string(Mrojo[int(j)][int(i)]);
                digi=str.size();
                if(digi==1) cout<<"   ";
                else if(digi==2) cout<<"  ";
                else cout<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n//////////////// Matriz pixeles verdes ////////////////"<<endl;

}

Imagen::~Imagen()
{
    delete imagen;
}
