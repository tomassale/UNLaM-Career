#include "normalizador.h"

/***************************************************************************************************
Desarrollar una función que normalice la cadena de texto que se le pasa como argumento.
    - la cadena se encontrará normalizada cuando la primera letra de cada palabra sea mayúscula y
         las siguientes minúsculas.
    - no deberá contener espacios o tabulaciones al inicio o al final.
    - se deberán eliminar los excedentes de espacios o tabulaciones.
    - Se debe modificar la cadena pasada como argumento.
    - No puede realizar copias locales de la cadena original.
Contemple las condiciones de borde y haga un listado de éstas.
***************************************************************************************************/

#define ES_ESPACIO(c) (isspace(c) ? 1: 0);

void normalizarCadena(char *vector, int ce){
    int i = 0, j = 0;
    int espacioAnterior = 1;

    while(i < ce && *(vector+i) != '\0'){
        //Borra espacio
        if(!isspace(*(vector+i)) && !espacioAnterior){
            *(vector+j) = tolower(*(vector+i));
            j++;
        }

        //Pone mayuscula
        if(!isspace(*(vector+i)) && espacioAnterior){
            if(j > 0){
                *(vector+j) = ' ';
                j++;
            }
            *(vector+j) = toupper(*(vector+i));
            j++;
         }
        espacioAnterior = ES_ESPACIO(*(vector+i));
        i++;
    }

    *(vector+j) = '\0';
}
