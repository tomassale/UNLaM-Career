#include "main.h"

int main()
{
    tFecha fecha;
    tFecha *pf = &fecha;
    int res = 0;

    if(pf == NULL){
        printf("Error al asignar el puntero.");
        exit(1);
    }

    pf->dia = 29;
    pf->mes = 2;
    pf->anio = 1950;

    res = verificarFecha(pf);

    (res) ? printf("Esta bien la fecha") : printf("La fecha no esta bien");

    return 0;
}
