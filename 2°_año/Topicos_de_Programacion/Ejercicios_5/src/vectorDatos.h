#ifndef VECTORDATOS_H_INCLUDED
#define VECTORDATOS_H_INCLUDED

typedef struct{
    char texto[21];
    int numT;
    float numF;
    char letra;
} tDatos;

tDatos* reservarMemoriaDato(int);
void asignarValoresDato(tDatos*, int);
void mostrarValoresDato(tDatos*, int);
void liberarMemoriaDato(tDatos*);

#endif // VECTORDATOS_H_INCLUDED
