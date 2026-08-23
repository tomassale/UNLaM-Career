/************************************************************************************************************************
Se dispone de un archivo llamado Stock.dat que contiene la información de los productos que vende una
fábrica. En el archivo se guarda:
  • Código de artículo (entero)
  • Descripción (50 caracteres máximo)
  • Stock (entero)
Luego se ingresan por teclado las ventas a realizar indicando:
  • Código de artículo
  • Cantidad
La carga por teclado de las ventas finaliza con un código de artículo igual a 0.
Por cada venta se debe controlar si hay stock suficiente y si lo hay, restar el stock de dicho producto, sino
hay stock se debe vender lo que quede disponible y grabar un registro en un archivo Faltantes.dat con la
cantidad que no pudo venderse, dicho registro debe contener:
  • Código de artículo
  • Cantidad faltante
Si ya hay un registro previo en dicho archivo de faltantes con el mismo producto debe incrementarse la
cantidad.
************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  int codigo;
  char descripcion[51];
  int stock;
}Stock;

void ingresoDatos(FILE *pf);
int buscarPosicion(FILE *pf);
void restarStock(FILE *pf);
void stockFaltante(FILE *pf);

int main(){
  FILE *pf;

  pf = fopen("STOCK.dat", "r+b");

  if(pf == NULL){
    printf("Error al abrir el archivo...");
    exit(1);
  }

  ingresoDatos(pf);

  fclose(pf);
  return 0;
}

void ingresoDatos(FILE *pf){
  Stock st;

  do{
    printf("Ingrese el codigo a restar el stock: ");
    scanf("%d", st.codigo);
    pos = buscarCodigo(pf, st.codigo);
  }while(pos == -1 && cod == 0);

  while(st.codigo != 0){
    rewind(pf);
    printf("Ingrese el stock a vender: ");
    scanf("%d", st.stock);
    buscarCodigo(pf, st.codigo);
    


    printf("Ingrese el codigo a restar el stock: ");
    scanf("%d", st.codigo);
  }
}

int buscarPosicion(FILE *pf, int num){
  int pos = -1, i = 0;
  Stock st;

  rewind(pf);
  fread(st, sizeof(Stock), 1, pf);
  while(pos == -1 && !feof(pf)){
    if(st.codigo == num){
      pos = i;
    } else {
      i++;
      fread(st, sizeof(Stock), 1, pf);
    }
  }

  return pos;
}

void restarStock(FILE *pf){

}

void stockFaltante(FILE *pf){

}