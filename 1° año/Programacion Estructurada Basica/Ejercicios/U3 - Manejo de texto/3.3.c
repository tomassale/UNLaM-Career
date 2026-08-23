/************************************************************************************************************************
Ingresar nombre y DNI de los alumnos de un curso. Como máximo el curso puede tener 50 alumnos. La carga finaliza con
un alumno de nombre FIN. Luego de cargar los alumnos se pide:
  a. Ingresar nombres de a uno en uno y buscarlos. Si el nombre está en el curso mostrar su DNI y sino
  informar que no está. Seguir ingresando nombres hasta que se ingrese un nombre igual a
  NOBUSCARMAS.
  b. Mostrar el listado de alumnos ordenado alfabéticamente de menor a mayor.
************************************************************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int ingresoDatos(char[][16], int[], int);
int ingresoValidado(int, int);
void acomodarVector(char[], int);
void ingresoBusqueda(char[][16], int[], int);
int buscaDni(int[], int, int);
int buscarAlumnos(char[][16], char[], int);
void ordenarNombres(char[][16], int[], int);
void mostrarResultado(char[][16], int[], int);

int main(){
    char nombres[50][16];
    int dni[50] = {0};
    int ingresos = 0;

    ingresos = ingresoDatos(nombres, dni, 50);
    if(ingresos != 0){
        ingresoBusqueda(nombres, dni, ingresos);
        ordenarNombres(nombres, dni, ingresos);
        mostrarResultado(nombres, dni, ingresos);
    }else{
        printf("\nNo hubieron ingresos");
    }


    return 0;
}

int buscarDni(int dnis[], int num, int ce){
    int i = 0, band = 0;

    while(band == 0 && i < ce)
        if(dnis[i] == num)
            band = 1;
        else
            i++;

    if(band == 0) i = -1;

    return i;
}

int ingresoValidado(int min, int max){
    int num;

    do{
        scanf("%d", &num);
    }while(num < min || num > max);

    return num;
}

int ingresoDatos(char matriz[][16], int dnis[], int ce){
    int i = 0, dni, band = 0, ultimo, pos;
    char nombre[16];

    printf("Ingrese el nombre del alumno (FIN para terminar): ");
    fgets(nombre, 16, stdin);
    ultimo = strlen(nombre) - 1;
    acomodarVector(nombre, ultimo);
    band = strcmp(nombre, "FIN");

    while(band  != 0 && i < ce){

        do{
            printf("Ingrese el documento: ");
            dni = ingresoValidado(1, 99999999);
            pos = buscarDni(dnis, dni, i);
        }while(pos != -1);


        getchar();

        dnis[i] = dni;
        strcpy(matriz[i], nombre);
        i++;

        printf("Ingrese el nombre del alumno (FIN para terminar): ");
        fgets(nombre, 16, stdin);
        ultimo = strlen(nombre) - 1;
        acomodarVector(nombre, ultimo);
        band = strcmp(nombre, "FIN");
    }
    return i;
}

void acomodarVector(char vector[], int ultimo){
    if(vector[ultimo] == '\n')
        vector[ultimo] = '\0';
}

void ingresoBusqueda(char matriz[][16], int dni[], int ce){
    int band = 0, pos, ultimo;
    char nombre[16];

    printf("Ingrese el alumno a buscar (NOBUSCARMAS para finalizar): ");
    fgets(nombre, 16, stdin);
    ultimo = strlen(nombre) - 1;
    acomodarVector(nombre, ultimo);
    band = strcmp(nombre, "NOBUSCARMAS");

    while(band != 0){
      pos = buscarAlumnos(matriz, nombre, ce);
      if(pos != -1)
        printf("\n\tAlumno %s, documento %d", matriz[pos], dni[pos]);
      else
        printf("\n\tAlumno no encontrado\n");

      printf("\nIngrese el alumno a buscar (NOBUSCARMAS para finalizar): ");
      fgets(nombre, 16, stdin);

      ultimo = strlen(nombre) - 1;
      acomodarVector(nombre, ultimo);
      band = strcmp(nombre, "NOBUSCARMAS");
    }
}

int buscarAlumnos(char matriz[][16], char palabra[], int ce){
    int i = 0, band = 0;

    while(!band && i < ce)
        if(strcmp(matriz[i], palabra) == 0)
            band = 1;
        else
            i++;

    if(band == 0) i = -1;

    return i;
}

void ordenarNombres(char matriz[][16], int dni[], int ce){
    int i, aux, cota = ce-1;
    int desordenado = 1;
    char auxNombre[16];

    while(desordenado){
        desordenado = 0;
        for(i = 0; i < cota; i++){
            if(strcmp(matriz[i], matriz[i+1]) > 0){
                strcpy(auxNombre, matriz[i]);
                strcpy(matriz[i], matriz[i+1]);
                strcpy(matriz[i+1], auxNombre);

                aux = dni[i];
                dni[i] = dni[i+1];
                dni[i+1] = aux;

                desordenado = i;
            }
        }
        cota = desordenado;
    }
}

void mostrarResultado(char matriz[][16], int dni[], int ce){
    int i = 0, j = 0;

    printf("\n\t\tALUMNOS REGISTRADOS");
    printf("\n\t\tDNI\t\tNOMBRE");
    for(i = 0; i < ce; i++){
        printf("\n\t%8d", dni[i]);
        printf("\t\t%s", matriz[i]);
    }
}
