/************************************************************************************************************************
Una empresa debe registrar los pedidos recibidos de cada uno sus 10 productos a lo largo del día. Cada producto está 
identificado por un código de 4 cifras. Los códigos deben ingresarse al inicio del programa mediante la función 
IngresaCódigos y no pueden repetirse.
Por cada pedido se recibe:
  • Código de producto
  • Cantidad de unidades solicitadas
Se puede recibir más de un pedido por producto.
La carga de pedidos finaliza cuando se ingresa un producto igual a 0.

Al finalizar se debe:
  a) Emitir un listado con código y cantidad de unidades solicitadas de cada producto.
  b) El / los productos del cual se solicitaron mayor cantidad de unidades.
  c) El / los productos del cual se solicitaron menos cantidad de unidades.
************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ingresoAleatorio(int[], int, int);
void ingresoCodigos(int[], int);
void ingresoPedidos(int[], int[]);
int validacionLimite(int, int);
int validacionMinimo(int);
int minimo(int[], int);
int maximo(int[], int);
void mostrarListado(int[], int[], int);
void mostrarMyM(int[], int[], int, int, int);

int main(){
  int codigos[10] = {0};
  int solicitado[10] = {0};

  int min, max, ingresos = 0;

  srand(time(NULL));

  //ingresoAleatorio(codigos, 10, 9999);
  ingresoCodigos(codigos, 10);

  ingresoPedidos(codigos, solicitado);

  min = minimo(solicitado, 10);
  max = maximo(solicitado, 10);
  if(max != 0){
    mostrarListado(codigos, solicitado, 10);
    mostrarMyM(codigos, solicitado, 10, min, max);
  }

  return 0;
}

void ingresoAleatorio(int vec[], int ce, int max){
  int i;
  for(i = 0; i < ce; i++){
    vec[i] = rand() % max;
  }
}

int minimo(int vec[], int ce){
  int i, min = vec[0];

  for(i = 0; i < ce; i++){
    if(vec[i] < min) min = vec[i];
  }

  return min;
}

int maximo(int vec[], int ce){
  int i, max = vec[0];

  for(i = 0; i < ce; i++){
    if(vec[i] > max) max = vec[i];
  }

  return max;
}

int conseguirPos(int cod[], int num){
  int i = 0, pos = -1;

  while(pos == -1 && i < 10){
    if(cod[i] == num)
      pos = i;
    else
      i++;
  }

  return pos;
}

void ingresoCodigos(int vec[], int ce){
  int i, pos, aux;

  for(i = 0; i < ce; i++){
      do{
        aux = validacionLimite(1000, 9999);
        pos = conseguirPos(vec, aux);
        if(pos != -1) printf("Dato duplicado. Ingrese otro\n");
      }while(pos != -1);
      vec[i] = aux;
  }
}


void ingresoPedidos(int cod[], int sol[]){
  int cantidad, codigo = -1, pos;

  printf("Ingreso de pedidos\n");
  while(codigo != 0){
    codigo = validacionLimite(1000, 9999);
    if(codigo != 0){
      pos = conseguirPos(cod, codigo);
      if(pos != -1){
        cantidad = validacionMinimo(0);
        sol[pos] += cantidad;
      }else{
        printf("Codigo no encontrado\n");
      }
    }
  }
  printf("Ingreso finalizado\n");
}


int validacionLimite(int min, int max){
  int num;

  do{
    printf("Ingrese un numero (%d a %d): ", min, max);
    scanf("%d", &num);
  }while((num < min || num > max) && num != 0);

  return num;
}

int validacionMinimo(int min){
  int num;

  do{
    printf("Ingrese un numero mayor a %d: ", min);
    scanf("%d", &num);
  }while(num < min);

  return num;
}

void mostrarListado(int codigos[], int solicitados[], int ce){
  int i;

  printf("\nCodigos\t\tSolicitados\n");
  for(i = 0; i < ce; i++){
    printf("%d\t\t\t%d\n", codigos[i], solicitados[i]);
  }
}

void mostrarMyM(int cod[], int sol[], int ce, int min, int max){
  int i;

  for(i = 0; i < ce; i++){ 
    if(max == sol[i]) 
      printf("\nEl producto %d tiene mayores pedidos que el resto (%d pedidos)", cod[i], max);
    if(min == sol[i])
      printf("\nEl producto %d tiene menos pedidos que el resto (%d pedidos)", cod[i], min);
  }
}