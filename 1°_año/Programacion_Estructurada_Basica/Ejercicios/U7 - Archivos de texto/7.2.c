//Realizar un programa que lea el contenido del archivo “cadenas.txt” creado en el punto anterior.

#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *pf;
    char texto[51];

    pf = fopen("CADENAS.txt", "rt");

    if(pf == NULL){
        printf("Error al abrir el archivo...");
        exit(1);
    }

    while(fgets(texto, 51, pf)){
        printf("%s", texto);
    }

    fclose(pf);
    return 0;
}