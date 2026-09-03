/************************************************************************************************************************
Utilizando la siguiente definición de estructura, realice un programa que solicite memoria para 5 alumnos.
  struct alumno
  {
    int legajo;
    char sexo;
    char nombre[30];
    float promedio;
  };
El usuario ingresara por teclado los datos que se cargara en la estructura- Mostrar el nombre de los alumnos uno debajo
del otro. A continuación, mostrar el alumno con mejor promedio.
************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int legajo;
    char sexo;
    char nombre[31];
    float promedio;
}alumno;

void ingresoDatos(alumno*);
alumno* mejorPromedio(alumno*);
void mostrarNombres(alumno*);

int main(){
    alumno *vec;
    alumno *ptr;

    vec = (alumno*)calloc(5, sizeof(alumno));

    if(vec == NULL){
        printf("Error al asignar memoria...");
        exit(1);
    }

    ingresoDatos(vec);
    mostrarNombres(vec);
    ptr = mejorPromedio(vec);

    printf("\nEl mejor promedio lo tiene el alumno %s: %.2f", ptr->nombre, ptr->promedio);

    free(vec);
    free(ptr);

    return 0;
}

void ingresoDatos(alumno *vec){
    int i;

    for(i = 0; i < 5; i++){
        printf("Ingrese el legajo: ");
        scanf("%d", &vec[i].legajo);

        getchar();
        printf("Ingrese el nombre: ");
        fgets(vec[i].nombre, 31, stdin);
        printf("Ingrese el sexo: ");
        scanf("%c", &vec[i].sexo);
        printf("Ingrese el promedio: ");
        scanf("%f", &vec[i].promedio);
    }
}

alumno* mejorPromedio(alumno *vec){
    int i;
    alumno *mejorProm = &(vec[0]);

    for(i = 0; i < 5; i++){
        if((vec+i)->promedio > mejorProm->promedio)
            mejorProm = &(vec[i]);
    }

    return mejorProm;
}



void mostrarNombres(alumno *vec){
    int i;

    printf("\nNOMBRES ORDENADOS\n");
    for(i = 0; i < 5; i++){
        printf("\nNombre: %s", (vec+i)->nombre);
    }
}
