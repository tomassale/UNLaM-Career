/************************************************************************************************************************
El archivo ventas.dat contiene información histórica de las ventas realizadas por una empresa desde el año
2014 al 2023. El formato de registro es el siguiente:
  • Mes (entero)
  • Año (entero)
  • Dia (entero)
  • Código de Producto (entero)
  • Importe de la venta (real)
Se pide ingresar un rango de años y mostrar un cuadro ventas realizadas en cada mes de cada año. Por ejemplo,
si se ingresa desde 2020 a 2022 debe mostrar lo siguiente:
                                      VER FORMATO DE ARCHIVO
Una vez configurados los años debe poder cambiarse la vista para en lugar de visualizar cantidad de ventas, ver el
detalle de importe por mes/año. El usuario podrá alternar las vistas las veces que quiera. Agregar una opción
para finalizar el programa.
************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int mes;
  int anio;
  int dia;
  int codigo;
  float importe;
}

void ingresoDatos(FILE *pf);
int validacionRango(int, int);

int main(){
    FILE *pf;

    pf = fopen("VENTAS.dat", "rb");

    if(pf == NULL){
        printf("Error al abrir el archivo...");
        exit(1);
    }

    ingresoDatos(pf);
    fclose(pf);
    return 0;
}

int validacionRango(int min, int max){
    int num;

    do{
        scanf("%d", &num);
    }while(num < min || num > max);

    return num;
}

void ingresoDatos(){
    int anioMin, anioMax;


}










