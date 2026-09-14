#include "contar_apariciones.h"

int verificacionPalabra(char *texto, char *palabra, int *posFinal, int pos){
    int i = 0, res = 1;

    while(*(palabra+i) != '\0' && res == 1){
        if(*(palabra+i) != *(texto+pos+i)){
            res = 0;
        }else{
            i++;
        }
    }
    *(posFinal) += i;

    return res;
}

int contarApariciones(char *texto, char *palabra, int ce){
    int i = 0, contApariciones = 0;

    int *posFinal = &i;

    if(posFinal == NULL){
        printf("Error al asignar el puntero...");
        exit(1);
    }

    while(i < ce && *(texto+i) != '\0'){
        if(*(palabra) == *(texto+i)){
            contApariciones += verificacionPalabra(texto, palabra, posFinal, i);
        }
        i++;
    }

    return contApariciones;
}
