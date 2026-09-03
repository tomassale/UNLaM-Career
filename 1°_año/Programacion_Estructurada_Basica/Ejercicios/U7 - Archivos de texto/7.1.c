/************************************************************************************************************************
Realizar un programa que genere el archivo “cadenas.txt” que guarde cadenas de caracteres que se ingresan por teclado
hasta ingresar la cadena “FINALIZAR”.
************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *pf;
    char texto[51];
    int ultimo;

    pf = fopen("CADENAS.txt", "wt");

    if(pf == NULL){
        printf("Error al abrir el archivo...");
        exit(1);
    }

    printf("Ingrese el texto [FINALIZAR para fin]: ");
    fgets(texto, 51, stdin);
    while(strcmp(texto, "FINALIZAR\n") != 0){
        fputs(texto, pf);
        printf("Ingrese el texto [FINALIZAR para fin]: ");
        fgets(texto, 51, stdin);
    }
    fflush(pf);

    fclose(pf);

    return 0;
}

