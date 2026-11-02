#ifndef FECHACORRECTA_H_INCLUDED
#define FECHACORRECTA_H_INCLUDED

typedef struct {
    int dia;
    int mes;
    int anio;
} tFecha;

int verificarFecha(tFecha *fe);

#endif // FECHACORRECTA_H_INCLUDED
