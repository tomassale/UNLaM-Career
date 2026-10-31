#include "TDAvector.h"

#define MIN_TAM 10

int TDAVector_crear(tdaVect *self, unsigned size, unsigned tam)
{
    self->vec = malloc(sizeof(tam));
}

void TDAVector_vaciar(const tdaVect *self)
{
    unsigned i;

    for(i = 0; i < self->ce; i++){
        self->vec(i+self->tam);
    }
}

void TDAVector_llenar(const tdaVect*)
{

}

void TDAVector_map(const tdaVect *self, int action(void*))
{
    void* lvec = self->vec;
    unsigned i;

    for(i=0; i < self-> ce; i++){
        action(lvec);
        lvec+= self->tam;
    }

    return self;
}

int TDAVector_insertarExpandir(const tdaVect *self, const void *dato)
{
    void *tpm;

    if(self->ce == self->ctotal){
        tmp = malloc((self->ctotal + MIN_TAM) * sizeof(self->tam));
        if(!tmp){
            return 0;
        }

        memcpy(tmp, self->vec, self->ce*self->tam);
        free(self->vec);
        self->vec = tmp;
        self->ctotal = self->ctotal+MIN_TAM;
    }

    memcpy(self->vec+(self->ce*self->tam), dato, self->tam);
    (self->ce)++;
    return 1;
}

void TDAVector_orden(const tdaVect*, const void*, int cmp(const void*, const void*))
{

}

void TDAVector_insertarOrdenado(const tdaVect*)
{

}

void TDAVector_destruir(const tdaVect *self)
{
    free(tdaVect->vec);

    tdaVect->ce = 0;
    tdaVect->ctotal = 0;
    tdaVect->tam = 0;
}
