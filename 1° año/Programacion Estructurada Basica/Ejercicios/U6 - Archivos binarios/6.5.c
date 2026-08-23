/************************************************************************************************************************
Se desea realizar un programa que permita actualizar la lista de precios de una empresa en forma individual
a cada uno de sus productos.
Los productos que están guardados en el archivo productos.dat con la siguiente estructura:
  • Código (entero)
  • Precio (float)
  • Descripción (de hasta 50 caracteres)
Para modificar un precio se ingresa por teclado el código del producto y el nuevo precio. La modificación
de precios finaliza con un código de producto igual a 0.
************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int codigo;
  float precio;
  char descripcion[51];
}Producto;

void ingresoDatos(FILE *pf);
void modificacionPrecios(FILE *pf, int, float);
int buscarCodigo(FILE *pf, int);
void leerArchivo(FILE *pf);

int main(){
  FILE *pf;

  pf = fopen("PRODUCTOS.dat", "r+b");
  if(pf==NULL){
    printf("Error al abrir el archivo...");
    exit(1);
  }

  leerArchivo(pf);
  ingresoDatos(pf);
  fclose(pf);

  return 0;
}

void ingresoDatos(FILE *pf){
  int codigoBuscar, pos;
  float precioNuevo;

  do{
    printf("Ingrese el codigo del producto: ");
    scanf("%d", &codigoBuscar);
    pos = buscarCodigo(pf, codigoBuscar);
  }while(codigoBuscar != 0 && pos == -1);

  while(codigoBuscar != 0){
    printf("Ingrese el precio nuevo: ");
    scanf("%f", &precioNuevo);

    modificacionPrecios(pf, pos, precioNuevo);
    leerArchivo(pf);
    do{
      printf("Ingrese el codigo del producto: ");
      scanf("%d", &codigoBuscar);
      pos = buscarCodigo(pf, codigoBuscar);
    }while(codigoBuscar != 0 && pos == -1);
  }
}

int buscarCodigo(FILE *pf, int cod){
  int i = 0, pos = -1;
  Producto pr;

  rewind(pf);
  fread(&pr, sizeof(Producto), 1, pf);
  while(!feof(pf) && pos == -1){
    if(pr.codigo == cod)
      pos = i;
    else
      i++;
      fread(&pr, sizeof(Producto), 1, pf);
  }

  return pos;
}

void modificacionPrecios(FILE *pf, int pos, float precioNuevo){
  Producto pr;

  rewind(pf);
  fseek(pf, pos * sizeof(Producto), SEEK_SET);
  fread(&pr, sizeof(Producto), 1, pf);
  pr.precio = precioNuevo;
  fseek(pf, -sizeof(Producto), SEEK_CUR);
  fwrite(&pr, sizeof(Producto), 1, pf);
  fflush(pf);
}

void leerArchivo(FILE *pf){
  Producto pr;

  rewind(pf);
  fread(&pr, sizeof(Producto), 1, pf);
  while(!feof(pf)){
    printf("Codigo: %4d | Precio: %8.2f | Descripcion: %29s\n", pr.codigo, pr.precio, pr.descripcion);
    fread(&pr, sizeof(Producto), 1, pf);
  }
}