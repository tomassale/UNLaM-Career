#include "main.h"

#define N 4

int main(){
    void *pm;
    bool res;

    srand(time(NULL));

    pm = Matriz_crear(N, N, sizeof(int));

    if(pm == NULL){
        printf("No se pudo asignar el puntero de matriz...");
        return 0;
    }

    Matriz_llenarAleatorioInt(pm, N, N, 1, 15);

    res = esSimetrica(pm, N);

    if(res){
        printf("\nEs simetrica la matriz");
    }else{
        printf("\nNo es simetrica la matriz");
    }

    Matriz_mostrarInt(pm, N, N);

    Matriz_destruir(pm);
    return 0;
}
