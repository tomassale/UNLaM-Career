/************************************************************************************************************************
 Un consorcio desea controlar la cobranza de las expensas en un edificio de 5 pisos donde existen 15
departamentos en cada piso. El valor de las expensas es de $ 1000. Para registrar la cobranza se ingresa el
número de piso (1 a 5) y el número de departamento (correlativo de 1 a 15 en cada piso). El ingreso finaliza
con un piso igual a 99.

Al finalizar mostrar el dinero total recaudado y una tabla con una X indicando aquellos departamentos
deudores de la siguiente manera:
                                      VER FORMATO EN ARCHIVO
************************************************************************************************************************/

#include <stdio.h>

void cargaExpensas(char[][15], int, int);
int ingresoValidadoFin(int, int, int);
int ingresoRango(int, int);
int sumarRecaudado(char[][15], int, int);
void mostrarMatriz(char[][15], int, int, int);

int main(){
  char deudores[5][15] = {{'\0'}};
  int recaudado = 0;

  cargaExpensas(deudores, 5, 15);
  recaudado = sumarRecaudado(deudores, 5, 15);
  mostrarMatriz(deudores, 5, 15, recaudado);

  return 0;
}

void cargaExpensas(char matriz[][15], int cf, int cc){
  int i, j;
  int piso, departamento = -1;

  while(departamento != 99){
    printf("Ingrese el numero de departamento (1 a 15)(99 para fin): ");
    departamento = ingresoValidadoFin(1, 15, 99);

    if(departamento != 99){
      printf("Ingrese el numero de piso (1 a 5): ");
      piso = ingresoRango(1, 5);
  
      matriz[piso-1][departamento-1] = 'X';
    }
  }
}

int ingresoValidadoFin(int min, int max, int fin){
  int num;

  do{
    scanf("%d", &num);
  }while((num < min || num > max) && num != fin);

  return num;
}

int ingresoRango(int min, int max){
  int num;

  do{
    scanf("%d", &num);
  }while(num < min || num > max);

  return num;
}

int sumarRecaudado(char matriz[][15], int cf, int cc){
  int i, j, suma = 0;

  for(i = 0; i < cf; i++){
    for(j = 0; j < cc; j++){
      if(matriz[i][j] == 'X') suma += 1000;
    }
  }

  return suma;
}

void mostrarMatriz(char matriz[][15], int cf, int cc, int recaudado){
  int i, j;

  printf("\n\t\t\t\t\t\t\tTOTAL RECAUDADO");
  printf("\n\t\t\t\t\t\t\tDEPARTAMENTOS DEUDORES");
  printf("\nPISO");
  
  for(i = 0; i < cc; i++){
    printf("\tDPTO %2d", i+1);
  }

  for(i = 0; i < cf; i++){
    printf("\nPISO %d", i+1);
    for(j = 0; j < cc; j++){
      printf("\t%c", matriz[i][j]);
    }
    printf("\n");
  }

  printf("\nTotal recuadado: %d", recaudado);
}
