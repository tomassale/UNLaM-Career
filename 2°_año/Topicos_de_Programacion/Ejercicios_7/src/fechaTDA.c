#include "fechaTDA.h"

#define AN_MIN 1
#define AN_MAX 5000

#define esBisiesto(X) ( ( ( X ) % 4 == 0 && ( X ) % 100 != 0 ) || ( X ) % 400 == 0 )

static int cantDiasMes(int mes, int anio)
{
    static const char dias[2][12] = {
        { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
        { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };

    return dias[esBisiesto(anio)][mes - 1];
}

static int esFechaValida(const tFecha *fec)
{
    int res = 1;

    if(fec->mes < 1 || fec->mes > 12)
        res = 0;
    else if(fec->anio < AN_MIN || fec->anio > AN_MAX)
        res = 0;
    else if(fec->dia < 1 || fec->dia > cantDiasMes(fec->mes, fec->anio))
        res = 0;

    return res;
}

static const tFecha* mayorFecha(const tFecha *fec1, const tFecha *fec2){
    if(fec1->anio != fec2->anio){
        return fec1->anio > fec2->anio ? fec1 : fec2;
    }

    if(fec1->mes != fec2->mes){
        return fec1->mes > fec2->mes ? fec1 : fec2;
    }

    return fec1->dia >= fec2->dia ? fec1 : fec2;
}

tFecha* FechaTDA_crear(int d, int m, int a){
    tFecha *fec = malloc(sizeof(tFecha));

    if(!fec) return NULL;

    fec->dia = d;
    fec->mes = m;
    fec->anio = a;

    if(!esFechaValida(fec)){
        free(fec);
        return NULL;
    }

    return fec;
}

void FechaTDA_mostrar(const tFecha *fec){
    printf("\n%02d/%02d/%4d", fec->dia, fec->mes, fec->anio);
}

void FechaTDA_sumaDias(tFecha *fec, int diasExtra){
    int diasMes;

    fec->dia += diasExtra;
    while(fec->dia > (diasMes = cantDiasMes(fec->mes, fec->anio))) {
        fec->dia -= diasMes;
        fec->mes++;
        if(fec->mes > 12){
            fec->mes = 1;
            fec->anio++;
        }
    }
}

void FechaTDA_restaDias(tFecha *fec, int diasResta){
    fec->dia -= diasResta;

    while(!esFechaValida(fec)){
        fec->mes--;
        if(fec->mes == 0){
            fec->mes = 12;
            fec->anio--;
        }
        fec->dia += cantDiasMes(fec->mes, fec->anio);
    }
}

tFecha* FechaTDA_diaSiguiente(const tFecha *fec){
    tFecha *fecSiguiente = FechaTDA_crear(fec->dia, fec->mes, fec->anio);

    if(fecSiguiente == NULL){
        printf("Error al asignar puntero a fecha siguiente...");
        exit(1);
    }

    FechaTDA_sumaDias(fecSiguiente, 1);

    return fecSiguiente;
}

int FechaTDA_compararFecha(const tFecha *fec1, const tFecha *fec2){

    const tFecha *mayor = mayorFecha(fec1, fec2);
    const tFecha *menor = (mayor == fec1) ? fec2 : fec1;

    int dias = 0;
    int mes = menor->mes;
    int anio = menor->anio;

    while(mes != mayor->mes || anio != mayor->anio){
        dias += cantDiasMes(mes, anio);
        mes++;
        if(mes > 12){
            mes = 1;
            anio++;
        }
    }

    dias += mayor->dia - menor->dia;

    return (mayor == fec2) ? dias : -dias;
}

int FechaTDA_diaSemana(const tFecha *fec)
{
    static const int t[12] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    int a = fec->anio - (fec->mes < 3);

    return (a + a/4 - a/100 + a/400 + t[fec->mes - 1] + fec->dia) % 7;
}

void FechaTDA_destruir(tFecha *fec)
{
    free(fec);
}
