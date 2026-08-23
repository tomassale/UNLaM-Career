/************************************************************************************************************************
 Se solicita modificar el programa anterior para que además de la butaca y fila ingrese la cantidad de butacas
de la reserva. En dicho caso se deberá verificar si existen a partir de la butaca ingresada la cantidad suficiente
de butacas disponibles consecutivas (tomar siempre hacia la derecha del seleccionado). Si están disponibles
reservar todas las butacas, sino mostrar un mensaje de error.
************************************************************************************************************************/

#include <stdio.h>
#include <ctype.h>

void inicializarMatriz(char[][9], int, int);
int verificacionButacas(char[][9], int, int);
void butacasMultiples(char[][9], int, int);
void ingresoReservas(char[][9], int[], int, int);
int ingresoRango(int, int);
int ingresoRangoFin(int, int, int);
int contarDisponibilidad(char[][9], int, int, char);
void sumaFilas(char[][9], int[], int, int);
void sumaColumnas(char[][9], int[], int, int);
void ordenarDescendiente(int[], int[], int);
int maximo(int[], int);
int buscaCodigo(int[], int, int);
void mostrarContadores(int, int);
void mostrarFilas(int[], int, int);
void mostrarListado(int[], int[], int);
void mostrarMatriz(char[][9], int, int);

int main(){
  char matriz[12][9];
  int asientos[9] = {8, 6, 4, 2, 1, 3, 5, 7, 9};
  int contCol[9] = {0};
  int contFil[12] = {0};
  int contDisp = 0, contRes = 0, max;

  inicializarMatriz(matriz, 12, 9);
  ingresoReservas(matriz, asientos, 12, 9);
  contDisp = contarDisponibilidad(matriz, 12, 9, 'D');
  contRes = contarDisponibilidad(matriz, 12, 9, 'R');

  mostrarContadores(contDisp, contRes);
  sumaFilas(matriz, contFil, 12, 9);
  sumaColumnas(matriz, contCol, 12, 9);
  max = maximo(contFil, 12);
  mostrarContadores(contDisp, contRes);
  mostrarFilas(contFil, 12, max);
  ordenarDescendiente(asientos, contCol, 9);
  mostrarListado(asientos, contCol, 9);
  mostrarMatriz(matriz, 12, 9);

  return 0;
}

void inicializarMatriz(char matriz[][9], int cf, int cc){
  int i, j;

  for(i = 0; i < cf; i++){
    for(j = 0; j < cc; j++){
      matriz[i][j] = 'D';
    }
  }
}

int buscaCodigo(int vec[], int ce, int num){
  int i = 0, pos = -1; 

  while(pos == -1 && i < ce){
    if(vec[i] == num)
      pos = i;
    else
      i++;
  }

  return pos;
}

int verificacionButacas(char matriz[][9], int cod, int pos){
  int i = 0, num, band = 0;
  int restantes = 9 - pos;

  do{
    printf("Ingrese la cantidad de butacas a reservar: ");
    scanf("%d", &num);
  }while(num <= 0);

  if(num > restantes){
    printf("\nNo hay suficientes butacas hacia la derecha.");
    num = -1;
  }else{
    while(i < num && band != -1){
      if(matriz[cod-1][pos+i] == 'R'){
        printf("\n¡Error! La butaca ya esta ocupada. Vuelva a ingresar los datos.");
        band = -1;
        num = -1;
      }else{
        i++;
      }
    }
  }

  return num;
}

void butacasMultiples(char matriz[][9], int cod, int pos){
  int posFinal, ingresos;
  
  ingresos = verificacionButacas(matriz, cod, pos);

  if(ingresos != -1){
    posFinal = pos + ingresos;
    for(pos; pos < posFinal; pos++){
      matriz[cod-1][pos] = 'R';
    }
  }
}

void ingresoReservas(char matriz[][9], int cod[], int cf, int cc){
  int fila, butaca, pos;

  fila = ingresoRangoFin(1, 12, 0);
  while(fila > 0){
      do{
        butaca = ingresoRango(1, 9);
        pos = buscaCodigo(cod, 9, butaca);
      }while(pos == -1);
      butacasMultiples(matriz, fila, pos);
      fila = ingresoRangoFin(1, 12, 0);
  }
}

int ingresoRango(int min, int max){
  int num;

  do{
    printf("Ingrese el numero (%d a %d): ", min, max);
    scanf("%d", &num);
  }while(num < min || num > max);

  return num;
}

int ingresoRangoFin(int min, int max, int fin){
  int num;

  do{
    printf("Ingrese el numero (%d a %d): ", min, max);
    scanf("%d", &num);
  }while((num < min || num > max) && num >= fin);

  return num;
}

int contarDisponibilidad(char matriz[][9], int cf, int cc, char car){
  int i, j, cont = 0;

  for(i = 0; i < cf; i++){
    for(j = 0; j < cc; j++){
      if(car == matriz[i][j]) cont++;
    }
  }

  return cont;
}

void sumaFilas(char matriz[][9], int suma[], int cf, int cc){
  int i, j;

  for(i = 0; i < cf; i++){
    for(j = 0; j < cc; j++){
      if(matriz[i][j] == 'R')
        suma[i]++;
    }
  }
}

void sumaColumnas(char matriz[][9], int suma[], int cf, int cc){
  int i, j;

  for(i = 0; i < cc; i++){
    for(j = 0; j < cf; j++){
      if(matriz[j][i] == 'R')
        suma[i]++;
    }
  }
}

void ordenarDescendiente(int cod[], int asientos[], int ce){
  int i, aux, cota = ce-1;
  int desordenado = 1;

  while(desordenado){
    desordenado = 0;
    for(i = 0; i < cota; i++){
      if(asientos[i] < asientos[i+1]){
        aux = asientos[i];
        asientos[i] = asientos[i+1];
        asientos[i+1] = aux;

        aux = cod[i];
        cod[i] = cod[i+1];
        cod[i+1] = aux;
        desordenado = i;
      }
    }
    cota = desordenado;
  }
}

int maximo(int vec[], int ce){
  int i, max = vec[0];

  for(i = 0; i < ce; i++){
    if(vec[i] > max) max = vec[i];
  }

  return max;
}

void mostrarContadores(int vacios, int reservados){
  printf("\nHay %d asientos reservados", reservados);
  printf("\nHay %d asientos vacios", vacios);
}

void mostrarFilas(int suma[], int ce, int max){
  int i;

  for(i = 0; i < ce; i++){
    if(suma[i] == 0)
      printf("\nLa fila %d no tiene ingresos", i+1);
    if(suma[i] == max)
      printf("\nLa fila %d tiene los maximos ingresos (%d)", i+1, max);
  }
}

void mostrarListado(int cod[], int sum[], int ce){
  int i;

  printf("\n\tButaca Cantidad\n");
  for(i = 0; i < ce; i++){
    printf("\t%d\t%2d\n", cod[i], sum[i]);
  }
}

void mostrarMatriz(char matriz[][9], int cc, int cf){
  int i, j;

  printf("\n\t\tMOSTRAR MATRIZ\n{\n");
  for(i = 0; i < cf; i++){
      printf("\t");
      for(j = 0; j < cc; j++){
          printf("%c, ", matriz[i][j]);
      }
      printf("\n");
  }
  printf("}");
}