#include "fechaCorrecta.h"

#define ANIO_MIN 1
#define ANIO_MAX 5000
#define ES_BISIESTO(X) (((X) % 4 == 0 && (X) % 100 != 0 ) || (X) % 400 == 0 )


int verificarFecha(tFecha *fe)
{
    int res = 1;
    int dias[2][12] = {
                    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
                  };

    if(fe->anio < ANIO_MIN || fe->anio > ANIO_MAX) res = 0;
    if(fe->mes < 1 || fe->mes > 12) res = 0;
    if(fe->dia < 1 || fe->dia > dias[ES_BISIESTO(fe->anio)][fe->mes -1]) res = 0;


    return res;
}
