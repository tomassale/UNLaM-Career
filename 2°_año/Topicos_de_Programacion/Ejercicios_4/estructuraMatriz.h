#ifndef ESTRUCTURAMATRIZ_H_INCLUDED
#define ESTRUCTURAMATRIZ_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void* Matriz_crear(int, int, size_t);
void Matriz_mostrarInt(void*, int, int);
void Matriz_mostrarFloat(void*, int, int);
void Matriz_generarIdentidad(void*, int, int);
void Matriz_generarDiagonal(void*, int, int);
void Matriz_generarSimetricaInt(void*, int, int, int);
void Matriz_generarSimetricaFloat(void*, int, int, int);
void Matriz_llenarAleatorioInt(void*, int, int, int, int);
void Matriz_llenarAleatorioFloat(void*, int, int, int, int);
void Matriz_destruir(void*);

#endif // ESTRUCTURAMATRIZ_H_INCLUDED
