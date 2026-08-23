/************************************************************************************************************************
 Un laboratorio dispone de una lista con sus 50 medicamentos. De cada uno conoce:
  • Código del medicamento (entero, de 3 cifras).
  • Precio (real).
  • Stock (entero).
Se solicita:
  a. Declarar un tipo de dato que contenga la información del medicamento.
  b. Declarar un vector de estructura de tipo de datos creado en el punto a
  c. Cargar en un sector de estructuras, los datos referentes a los medicamentos. Función INGRESO.
  d. Consultar el precio según código del medicamento. Función BUSQUEDA_MEDI.
  e. Informar los códigos de los medicamentos cuyo stock es inferior a 10 unidades. Función INFORME.
************************************************************************************************************************/

#include <stdio.h>

typedef struct{
  int codigo;
  float precio;
  int stock;
} Medicamentos;

void inicializarStruct(Alumno[], int);
void INGRESO(Medicamentos[], int);
void BUSQUEDA_MEDI(Medicamentos[], int);
void INFORME(Medicamentos[], int);

int main(){
  Medicamentos vMed[50];

  inicializarStruct(vMed, 50);
  INGRESO(vMed, 50);
  BUSQUEDA_MEDI(vMed, 50);
  INFORME(vMed, 50);
  
  return 0;
}

void inicializarStruct(Medicamentos med[], int ce){
  int i;

  for(i = 0; i < ce; i++){
    med[i].codigo = 0;
    med[i].precio = 0;
    med[i].stock = 0;
  }
}

void INGRESO(Medicamentos med[], int ce){
  int i, codigo, stock;
  float precio;

  for(i = 0; i < ce; i++){
    do{
      printf("Ingrese el codigo del medicamento: ");
      scanf("%d", &codigo);
    }while(codigo < 100 || codigo > 999);

    do{
      printf("Ingrese el precio del medicamento: ");
      scanf("%f", &precio);
    }while(precio <= 0);

    do{
      printf("Ingrese el stock del medicamento: ");
      scanf("%d", &stock);
    }while(stock < 0);

    med[i].codigo = codigo;
    med[i].precio = precio;
    med[i].stock = stock;
  }
}


void BUSQUEDA_MEDI(Medicamentos med[], int ce){
  int i, codigo = -1, pos;

  while(codigo != 0){
    pos = -1;
    i = 0;
    printf("Ingrese el codigo a buscar: ");
    scanf("%d", &codigo);

    if(codigo != 0){
      while(i < ce && pos == -1){
        if(med[i].codigo == codigo)
          pos = i;
        else
          i++;
      }

      if(pos != -1)
        printf("\nCodigo: %d\tPrecio: %.2f", med[pos].codigo, med[pos].precio);
      else
        printf("\nEl codigo %d no fue encontrado.", codigo);
    }
  }
}

void INFORME(Medicamentos med[], int ce){
  int i;

  for(i = 0; i < ce; i++)
    if(med[i].stock < 10 && med[i]. stock != 0)
      printf("\nEl medicamento %d tiene menos de 10 de stock.", med[i].codigo);
}