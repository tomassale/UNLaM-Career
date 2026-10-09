#include "main.h"

#define N 7

int main(){
    void *pm;
    int vector[N] = {0};
    int matrizCorrecta;

    srand(time(NULL));

    pm = Matriz_crear(N, N, sizeof(int));

    if(pm == NULL){
        printf("No se pudo asignar el puntero de matriz 1...");
        return 0;
    }

    Matriz_llenarResultados(pm, N);
    matrizCorrecta = Matriz_verificarCreacion(pm, N);
    if(matrizCorrecta){
        Matriz_mostrarTabla(pm, N);
        Matriz_mostrarResultado(pm, vector, N);
    }else{
        printf("No esta correctamente creada.\n");
    }

    Matriz_destruir(pm);

    return 0;
}
