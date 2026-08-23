/************************************************************************************************************************
Dado el archivo productos.dat con la siguiente estructura:
  • Código (entero)
  • Precio (float)
  • Descripción (de hasta 50 caracteres)
Realizar un programa que permita eliminar productos dado su código
************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int codigo;
  float precio;
  char descripcion[51];
}Producto;

void ingresoDatos(FILE *pf);
int buscarCodigo(FILE *pf, int);
void borrarRegistro(FILE *pf, int);
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

  return 0;
}

void ingresoDatos(FILE *pf){
  int codigoBuscar, pos;
  float precioNuevo;

  do{
    printf("Ingrese el codigo del producto a borrar: ");
    scanf("%d", &codigoBuscar);
    pos = buscarCodigo(pf, codigoBuscar);
  }while(codigoBuscar != 0 && pos == -1);

  while(codigoBuscar != 0){
    borrarRegistro(pf, codigoBuscar);
    pf = fopen("PRODUCTOS.dat", "r+b");
    leerArchivo(pf);
    do{
      printf("Ingrese el codigo del producto a borrar: ");
      scanf("%d", &codigoBuscar);
      pos = buscarCodigo(pf, codigoBuscar);
    }while(codigoBuscar != 0 && pos == -1);
  }
  fclose(pf);
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

void borrarRegistro(FILE *pf, int codigo){
  FILE *pfTemp;
  Producto pr;

  rewind(pf);
  pfTemp = fopen("PRODUCTOS.tmp", "wb");

  if(pfTemp == NULL){
    printf("Error al abrir el archivo...");
    exit(1);
  }

  fread(&pr, sizeof(Producto), 1, pf);
  while(!feof(pf)){
    if(pr.codigo != codigo)
      fwrite(&pr, sizeof(Producto), 1, pfTemp);
    fread(&pr, sizeof(Producto), 1, pf);
  }

  fclose(pf);
  fclose(pfTemp);
  remove("PRODUCTOS.dat");
  rename("PRODUCTOS.tmp", "PRODUCTOS.dat");
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