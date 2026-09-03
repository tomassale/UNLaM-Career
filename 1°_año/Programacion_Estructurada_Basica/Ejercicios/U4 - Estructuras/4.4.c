/************************************************************************************************************************
Se ingresan las ventas de un comercio de insumos de computación. Por cada venta se ingresa:
  • Número de cliente (entero de 4 dígitos no correlativos).
  • Importe (mayor a cero).
  • Número de vendedor (entero de 1 a 10)
El ingreso de datos finaliza con un número de cliente 999.
Se sabe que no son más de 100 clientes, la carga de los clientes se debe realizar al inicio del programa con la
función CARGA_CLIENTE () y para cada uno se ingresa:
  • Código de cliente (entero de 4 dígitos no correlativos).
  • Nombre y Apellido (50 caracteres máximo).
Se solicita:
  a. Determinar la cantidad de ventas realizadas por cliente.
  b. La cantidad de ventas realizadas por vendedor.
  c. Informar en forma ordenada por total facturado (modo descendente), el total facturado a cada cliente, informando:
                                      VER FORMATO EN ARCHIVO
************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct{
  int codigo;
  char nombreApellido[51];
  int ventas;
  float facturado;
} Cliente;

void inicializarStruct(Cliente[], int);
int buscarCodigo(Cliente[], int, int);
void CARGA_CLIENTE(Cliente[], int);
void cargaVentas(Cliente[], int[], int);
int validacionRango(int, int);
float validacionImporte(float);
void validacionTexto(char[], int);
void ordenarDescendente(Cliente[], int);
void mostrarVentas(int[], int);
void mostrarInforme(Cliente[], int);

int main(){
  Cliente vClient[100];
  int ventasVendedor[10] = {0};

  inicializarStruct
  CARGA_CLIENTE(vClient, 100);
  cargaVentas(vClient, ventasVendedor, 100);
  mostrarVentas(ventasVendedor, 10);
  mostrarInforme(vClient, 100);

  return 0;
}

void inicializarStruct(Cliente vec[], int ce){
  int i;

  for(i = 0; i < ce; i++){
    vec[i].codigo = 0;
    strcpy(vec[i].nombreApellido, " ");
    vec[i].ventas = 0;
    vec[i].facturado = 0;
  }
}

int buscarCodigo(Cliente vec[], int num, int ce){
  int i = 0, pos = -1;

  while(i < ce && pos == -1){
    if(vec[i].codigo == num)
      pos = i;
    else
      i++;
  }

  return pos;
}

void CARGA_CLIENTE(Cliente vec[], int ce){
  int i = 0, cliente = -1, pos;
  char nombApell[51];

  for(i = 0; i < ce; i++){
    do{
      printf("Ingrese el numero de cliente (4 digitos): ");
      cliente = validacionRango(999, 10000);
      pos = buscarCodigo(vec, cliente, ce);
    }while(pos != -1);

    printf("Ingrese el nombre y apellido (hasta 50 caracteres): ");
    validacionTexto(nombApell, 51);

    vec[i].codigo = cliente;
    strcpy(vec[i].nombreApellido, nombApell);
  }
}

void cargaVentas(Cliente vec[], int vend[], int ce){
  int cliente = -1, vendedor, pos;
  float importe;

  while(cliente != 999){
    do{
      printf("Ingrese el cliente [999 para fin]: ");
      scanf("%d", &cliente);
      getchar();
      pos = buscarCodigo(vec, cliente, ce);
    }while(pos == -1 || cliente == 999);

    if(cliente != 999){
      printf("Ingrese el importe: ");
      importe = validacionImporte(0);
  
      printf("Informe el vendedor: ");
      vendedor = validacionRango(1, 10);

      vend[vendedor-1]++;
      vec[pos].facturado += importe;
      vec[pos].ventas++;
      
    }
  }
}

int validacionRango(int min, int max){
  int num;

  do{
    scanf("%d", &num);
  }while(num < min || num > max);
  getchar();

  return num;
}

float validacionImporte(float min){
  float num;

  do{
    scanf("%f", &num);
  }while(num <= min);
  getchar();

  return num;
}

void validacionTexto(char texto[], int medida){
  int ultimo;

  getchar();
  fgets(texto, medida, stdin);
  ultimo = strlen(texto) - 1;
  if(texto[ultimo] == '\n') texto[ultimo] = '\0';
}

void ordenarDescendente(Cliente vec[], int ce){
  int i, cota = ce-1;
  int desordenado = 1;
  Cliente aux;

  while(desordenado){
    desordenado = 0;
    for(i = 0; i < cota; i++){
      if(vec[i].facturado < vec[i+1].facturado){
        aux = vec[i];
        vec[i] = vec[i+1];
        vec[i+1] = aux;

        desordenado = i;
      }
    }
    cota = desordenado;
  }
}

void mostrarVentas(int vent[], int ce){
  int i;

  printf("\n\tVENTAS POR VENDEDOR");
  for(i = 0; i < ce; i++){
    printf("\nVendedor %d: %d", i+1, vent[i]);
  }
}

void mostrarInforme(Cliente vec[], int ce){
  int i;

  ordenarDescendente(vec, ce);
  printf("\n\tCODIGO DE CLIENTE\tNOMBRE Y APELLIDO\t\tTOTAL FACTURADO");
  for(i = 0; i < ce; i++){
    printf("\n\t\t%4d\t%s\t\t$%4.2f", vec[i].codigo, vec[i].nombreApellido, vec[i].facturado);
  }
}