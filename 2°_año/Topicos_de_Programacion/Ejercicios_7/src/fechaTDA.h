#ifndef FECHATDA_H_INCLUDED
#define FECHATDA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia;
    int mes;
    int anio;
} tFecha;

static int cantDiasMes(int, int);
static const tFecha* mayorFecha(const tFecha*, const tFecha*);
static int esFechaValida(const tFecha*);
tFecha* FechaTDA_crear(int, int, int);
void FechaTDA_mostrar(const tFecha*);
void FechaTDA_sumaDias(tFecha*, int);
void FechaTDA_restaDias(tFecha*, int);
tFecha* FechaTDA_diaSiguiente(const tFecha*);
int FechaTDA_compararFecha(const tFecha*, const tFecha*);
int FechaTDA_diaSemana(const tFecha*);
void FechaTDA_destruir(tFecha*);

#endif // FECHATDA_H_INCLUDED
