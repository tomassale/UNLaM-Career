/************************************************************************************************************************
4.6 La fórmula 1 está compuesta por 20 pilotos y en el año se corrieron 23 carreras.
    a) Se desea ingresar la información de cada piloto (nombre, escudería) y la posición en la que llegó dicho
       piloto en cada una de las 23 carreras (1 a 20).
    
    b) Luego se debe poder elegir el número de carrera del año y mostrar el listado de los 10 primeros puestos
       de dicha carrera. Repetir el proceso con distintos números de carreras hasta ingresar un 0 como número
       de carrera.
************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct{
    char nombre[31];
    char escuderia[26];
    int posicion[23];
} Piloto;

void cargarPilotos(Piloto[], int);
int buscarPosicion(Piloto[], int, int, int);
int validacionRango(int, int);
void validacionPalabra(char[], int);
void mostrarResultados(Piloto[], int);

int main(){
    Piloto vPil[20];
    
    cargarPilotos(vPil, 20);
    mostrarResultados(vPil, 20);
    
    return 0;
}

void cargarPilotos(Piloto vec[], int ce){
    int i, j, posicion, pos;
    char piloto[31], escuderia[26];
    
    for(i = 0; i < ce; i++){
        printf("Ingrese el nombre del piloto: ");
        validacionPalabra(piloto, 31);
        
        printf("Ingrese el nombre de escuderia: ");
        validacionPalabra(escuderia, 26);
        
        for(j = 0; j < 23; j++){
            do{
                printf("Ingrese la posicion de la carrera (%d de 23): ", j+1);
                posicion = validacionRango(1, 20);
                pos = buscarPosicion(vec, j, posicion, i);
            }while(pos != -1);
            vec[i].posicion[j] = posicion;
        }
        strcpy(vec[i].nombre, piloto);
        strcpy(vec[i].escuderia, escuderia);
    }
}

int buscarPosicion(Piloto vec[], int carrera_id, int num, int ce){
    int i = 0, pos = -1;
    
    while(pos == -1 && i < ce){
        if(vec[i].posicion[carrera_id] == num)
            pos = i;
        else
            i++;
    }
    
    return pos;
}

int validacionRango(int min, int max){
    int num;
    
    do{
        scanf("%d", &num);
    }while(num < min || num > max);
    
    getchar();
    return num;
}

void validacionPalabra(char texto[], int medida){
    int ultimo, i;
    
    fgets(texto, medida, stdin);
    ultimo = strlen(texto) - 1;
    if(texto[ultimo] == '\n') texto[ultimo] = '\0';
    for(i = 0; i < ultimo; i++){
        texto[i] = tolower(texto[i]);
    }
}

void mostrarResultados(Piloto vec[], int ce){
    int i, j, carrera = -1, pos;
    
    printf("\n\t\t\tCARRERAS POSICION 10\n");
    while(carrera != 0){
        printf("Ingrese la carrera a ver resultado: ");
        carrera = validacionRango(0, 23);
        if(carrera != 0){
            printf("\n\t\tPOSICION\t\tPILOTO");
            for(j = 0; j < 10; j++){
                pos = buscarPosicion(vec, carrera-1, j+1, 20);
                printf("\n\t\t%d\t%s", j+1, vec[pos].nombre);
            }
        }
    } 
}