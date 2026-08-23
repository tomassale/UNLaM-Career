/************************************************************************************************************************
Se ingresan código y precio unitario de los productos que vende un negocio. No se sabe la cantidad exacta de productos,
pero sí se sabe que son menos de 50. El código es alfanumérico de 3 caracteres y la carga de los datos de productos
termina con un código igual al “FIN”. Luego se registran las ventas del día y por cada venta se ingresa el código de
producto y cantidad de unidades vendidas terminando con una cantidad igual a 0. Se solicita:
  a. Calcular la recaudación total del día y el producto del cual se vendió menor cantidad de unidades.
  b. Mostrar el listado de productos con su precio ordenado en forma alfabética por código de producto.
************************************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ingresosDatos(char[][5], float[], int);
void ingresoVentas(char[][5], int[], int);
float validacionPrecio(float);
int validacionVentas(int);
char validacionCodigo(char[][5], int);
void acomodarPalabra(char[], int);
int buscarCodigo(char[][5], char[], int);
float calcularRecaudacion(float[], int[], int);
int buscarMenor(int[], int);
void ordenarListado(char[][5], float[], int);
void mostrarListado(char[][5], float[], int);



int main(){
  char codigos[50][5] = {{'\0'}};
  float precios[50] = {0};
  int ventas[50] = {0};
  int ingresos = 0;
  float recaudacion;
  int posMenor;

  ingresos = ingresosDatos(codigos, precios, 50);

  if(ingresos != 0){
    ingresoVentas(codigos, ventas, ingresos);
    recaudacion = calcularRecaudacion(precios, ventas, ingresos);
    posMenor = buscarMenor(ventas, ingresos);

    printf("\nRecaudacion total del dia: $%.2f", recaudacion);
    printf("\nEl producto de menor ventas es: %s\n", codigos[posMenor]);
    mostrarListado(codigos, precios, ingresos);
  }

  return 0;
}

int ingresosDatos(char codigos[][5], float precios[], int ce){
  char codigo[5];
  int i = 0, pos, ultimo;
  int band;

  printf("\n--- INGRESO DE PRODUCTOS ---\n");
  do {
    do {
      printf("Ingrese el codigo de producto (%d de %d) [FIN para terminar]: ", i+1, ce);
      fgets(codigo, 5, stdin);
      ultimo = strlen(codigo) - 1;
      acomodarPalabra(codigo, ultimo);

      band = strcmp(codigo, "FIN");
      pos = buscarCodigo(codigos, codigo, i);

      if (pos != -1 && band != 0) {
          printf("Error: Ese codigo ya fue ingresado. Intente otro.\n");
      }
    } while (pos != -1 && band != 0);

    if (band != 0) {
      strcpy(codigos[i], codigo);
      precios[i] = validacionPrecio(0.01);
      i++;
    }
  } while (band != 0 && i < ce);

  return i;
}

void acomodarPalabra(char texto[], int ultimo){
  if(texto[ultimo] == '\n') texto[ultimo] = '\0';
}

void ingresoVentas(char codigos[][5], int ventas[], int ce){
  int i = 0, venta, ultimo, pos;
  char codigo[5];

  printf("\n--- INGRESO DE VENTAS ---\n");
  printf("Ingrese la cantidad de ventas (0 para terminar): ");
  venta = validacionVentas(0);

  while(venta != 0){
    printf("Ingrese el codigo del producto vendido: ");
    fgets(codigo, 5, stdin);
    ultimo = strlen(codigo) - 1;
    acomodarPalabra(codigo, ultimo);

    pos = buscarCodigo(codigos, codigo, ce);

    if (pos != -1) {
        ventas[pos] += venta;
        i++;
    } else {
        printf("Error: Codigo no encontrado.\n");
    }

    printf("\nIngrese la cantidad de ventas (0 para terminar): ");
    venta = validacionVentas(0);
  }
}

float validacionPrecio(float min){
  float num;
  do{
    printf("Ingrese el valor del producto: ");
    scanf("%f", &num);
  }while(num < min);

  getchar();
  return num;
}

int validacionVentas(int min){
  int num;
  do{
    scanf("%d", &num);
  }while(num < min);

  getchar();
  return num;
}

int buscarCodigo(char codigos[][5], char cod[], int ce){
  int pos = -1, i = 0;
  while(i < ce && pos == -1){
    if(strcmp(codigos[i], cod) == 0)
      pos = i;
    else
      i++;
  }
  return pos;
}

float calcularRecaudacion(float precio[], int ventas[], int ce){
  int i;
  float recaudacion = 0;
  for(i = 0; i < ce; i++){
    recaudacion += ventas[i] * precio[i];
  }
  return recaudacion;
}

int buscarMenor(int ventas[], int ce){
  int pos = 0;
  int i = 0;
  int menor = ventas[0];

  for(i = 1; i < ce; i++){
    if(ventas[i] < menor){
      menor = ventas[i];
      pos = i;
    }
  }
  return pos;
}

void ordenarListado(char codigos[][5], float precios[], int ce){
  int i, cota = ce-1;
  int desordenado = 1;
  float aux;
  char auxChar[5];

  while(desordenado){
    desordenado = 0;
    for(i = 0; i < cota; i++){
      if(strcmp(codigos[i], codigos[i+1]) > 0){
        strcpy(auxChar, codigos[i]);
        strcpy(codigos[i], codigos[i+1]);
        strcpy(codigos[i+1], auxChar);

        aux = precios[i];
        precios[i] = precios[i+1];
        precios[i+1] = aux;

        desordenado = i;
      }
    }
    cota = desordenado;
  }
}

void mostrarListado(char codigos[][5], float precios[], int ce){
  int i;

  ordenarListado(codigos, precios, ce);
  printf("\n\n\tLISTADO DE PRODUCTOS");
  printf("\n\tCODIGOS\tPRECIOS");
  for(i = 0; i < ce; i++){
    printf("\n\t%3s\t$%.2f", codigos[i], precios[i]);
  }
  printf("\n");
}
