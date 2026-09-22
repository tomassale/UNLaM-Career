#include "comparacion.h"

int mi_strcmpi(char *texto1, char *texto2){
    int i = 0;
    int peso1, peso2, res;

    while(*(texto1+i) != '\0' && tolower(*(texto1+i)) == tolower(*(texto2+i))){
        i++;
    }

    peso1 = tolower(*(texto1+i));
    peso2 = tolower(*(texto2+i));
    res = peso1 - peso2;

    return res;
}

int mi_strlen(char *texto){
    int i = 0;
    while(*(texto+i) != '\0'){
        i++;
    }
    return i;
}

int comparacion(char *texto1, char *texto2, int ceTexto1, int ceTexto2){
    int med1 = mi_strlen(texto1);
    int med2 = mi_strlen(texto2);
    int res;

    if(med1 != med2){
        res = med1 - med2;
    }else{
        res = mi_strcmpi(texto1, texto2);
    }

    return res;
}
