#include "main.h"

int main()
{
    tFecha *fec = FechaTDA_crear(13, 5, 2003);
    int res;

    if(fec == NULL){
        printf("Error al inicalizar el puntero");
        exit(1);
    }

    res = FechaTDA_diaSemana(fec);

    FechaTDA_mostrar(fec);

    switch(res){
        case 0:    printf(" -> %d: Domingo", res);   break;
        case 1:    printf(" -> %d: Lunes", res);     break;
        case 2:    printf(" -> %d: Martes", res);    break;
        case 3:    printf(" -> %d: Miercoles", res); break;
        case 4:    printf(" -> %d: Jueves", res);    break;
        case 5:    printf(" -> %d: Viernes", res);   break;
        case 6:    printf(" -> %d: Sabado", res);    break;
        default:   printf(" -> Dia invalido");       break;
    }

    FechaTDA_destruir(fec);

    return 0;
}
