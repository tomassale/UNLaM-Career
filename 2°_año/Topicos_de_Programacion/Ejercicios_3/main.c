#include "main.h"

int main()
{
    char texto1[101];
    char texto2[101];
    char vector1[101], vector2[101];
    int res;

    printf("Ingrese un texto: ");
    scanf("%s", texto1);

    printf("Ingrese otro texto: ");
    scanf("%s", texto2);

    res = comparacion(texto1, texto2, 101, 101);

    while(res != 0){
        if(res > 0){
            strcpy(vector2, texto1);
            strcpy(vector1, texto2);
        }else{
            strcpy(vector1, texto1);
            strcpy(vector2, texto2);
        }
        printf("Vector 1: %s\n", vector1);
        printf("Vector 2: %s\n", vector2);

        printf("Ingrese un texto: ");
        scanf("%s", texto1);

        printf("Ingrese otro texto: ");
        scanf("%s", texto2);

        res = comparacion(texto1, texto2, 101, 101);
    }

    printf("\nIngreso finalizado");

    return 0;
}
