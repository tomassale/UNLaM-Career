/************************************************************************************************************************
Dada la estructura alumno:
  struct alumno
  {
  char nom[31];
  int dni;
  };
Realizar un programa que permita cargar alumnos y mostrarlos. Como máximo permitir 50 alumnos. El ingreso
finaliza con un DNI igual a 0. Realizar una función para cargar y otra para mostrar usando notación de punteros.
************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nombre[31];
    int dni;
}alumno;

void cargarDatos(alumno*, int);
void mostrarDatos(alumno*, int);

int main(){
    alumno *vecAl;
    int ingresos = 0;

    do{
        printf("Ingrese el tamanio del vector (menor a 50): ");
        scanf("%d", &ingresos);
    }while(ingresos < 1 || ingresos > 50);

    vecAl = (alumno*)calloc(ingresos, sizeof(alumno));

    if(vecAl == NULL){
        printf("\nError al asignas memoria...");
        exit(1);
    }

    cargarDatos(vecAl, ingresos);
    mostrarDatos(vecAl, ingresos);

    free(vecAl);
    return 0;
}

void cargarDatos(alumno *vec, int ce){
    int i = 0, dniAux, medida;
    char aux[31];

    printf("Ingrese el dni: ");
    scanf("%d", &dniAux);
    while(i < ce && dniAux != 0){
        getchar();
        printf("Ingrese el nombre: ");
        fgets(aux, 31, stdin);
        medida = strlen(aux);
        if(aux[medida-1] == '\n')
            aux[medida-1] = '\0';

        (vec+i)->dni = dniAux;
        strcpy((vec+i)->nombre, aux);
        i++;
        if(i < ce){
            printf("Ingrese el dni: ");
            scanf("%d", &dniAux);
        }
    }
}

void mostrarDatos(alumno *vec, int ce){
    int i;

    printf("\nDatos cargados");
    for(i = 0; i < ce; i++){
        printf("\nDNI Alumno: %d | Nombre Alumno: %s", (vec+i)->dni, (vec+i)->nombre);
    }
}
