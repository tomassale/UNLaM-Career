/************************************************************************************************************************
Realizar una función que permita ingresar por teclado un valor entero, un flotante y un carácter. La función
no debe retornar ningún valor. Las variables se declaran y se muestran en el programa principal.
************************************************************************************************************************/

#include <stdio.h>

void ingresoDatos(int*, int*, int*);

int main(){
  int numI, *pi, *pf, *pc;
  float numF;
  char car;

  pi = &numI;
  pf = &numF;
  pc = &car;

  ingresoDatos(pi, pf, pc);

  printf("\nNumero Entero: %d", *pi);
  printf("\nNumero flotante: %f", *pf);
  printf("\nCaracter: %c", *pc);

  return 0;
}

void ingresoDatos(int pi*, int pf*, int pc*){
  printf("Ingrese el numero entero: ");
  scanf("%d", *pi);
  printf("Ingrese el valor del flotante: ");
  scanf("%f", *pf);
  printf("Ingrese el valor del caracter: ");
  scanf("%c", *pc);
}