#include "ofuscado.h"

int buscador(char *regla, char letra, int ceRegla){
    int pos = -1, i = 0;

    while(i < ceRegla && pos == -1)
        if(*(regla+i) == letra){
          pos = i;
        }else{
            i++;
        }

    return pos;
}

char letraDesofuscada(char *regla, int posicion, int ceRegla, int adelanto){
    char letraDes;

    posicion += adelanto;
    while(posicion >= ceRegla)
        posicion -= ceRegla;

    letraDes = *(regla+posicion);

    return letraDes;
}

void desofuscar(char *texto, char *regla, int ceTexto, int ceRegla){
    int i = 0, j = 0, pos = 1, posLetra = 0;
    char letraActual = *(texto+i), letraNueva;

    while(i < ceTexto && letraActual != '\0'){
        if(isalpha(letraActual)){
            posLetra = buscador(regla, letraActual, ceRegla);
            if(posLetra != -1){
                letraNueva = letraDesofuscada(regla, posLetra, ceRegla, pos);
                *(texto+j) = letraNueva;
            }else{
                *(texto+j) = letraActual;
            }
            pos++;
            j++;
        }else{
            *(texto+j) = letraActual;
            j++;
            pos = 1;
        }
        i++;
        letraActual = *(texto+i);
    }
    *(texto+j) = '\0';
}
