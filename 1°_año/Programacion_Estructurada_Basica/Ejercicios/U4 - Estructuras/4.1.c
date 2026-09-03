/************************************************************************************************************************
Una empresa que vende neumáticos desea realizar un programa para actualizar el total de ventas del mes
de sus productos. Para ello primeramente se ingresan la información de los productos formados por:
  • Código (5 caracteres).
  • Precio (real).
  • Descripción (30 caracteres).
  • Cantidad de unidades vendidas (al mes anterior, entero).
  • Importe Total Vendido (al mes anterior, real).
Se sabe que la empresa no vende más de 50 productos. El ingreso de la carga de productos finaliza con un
producto con descripción “FIN”.
Luego ingresan las ventas del mes:
  • Código de Producto (5 caracteres).
  • Cantidad pedida.
El ingreso de datos de las ventas finaliza con una cantidad igual a 0. Se solicita:
  a. Actualizar la información de los productos con las ventas realizadas en el mes.
  b. Al finalizar, mostrar el listado de productos actualizado, informando:
                                  VER FORMATO EN ARCHIVO
************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    char codigo[6];
    float precio;
    char descripcion[32];
    int ventas;
    float total;
} Productos;

int ingresoDatos(Productos[], int);
void cargaVentas(Productos[], int);
int buscarCodigo(Productos[], char[], int);
int validacionLimite(int);
float validacionPrecio(float);
void validacionTexto(char[], int);
void validacionPalabra(char[], int);
void calcularValor(Productos[], int);
void mostrarResultado(Productos[], int);

int main(){
    Productos vProd[50];
    int ingresos = 0;
    
    ingresos = ingresoDatos(vProd, 50);
    if(ingresos != 0){
        cargaVentas(vProd, ingresos);
        calcularValor(vProd, ingresos);
        mostrarResultado(vProd, ingresos);
    }else{
        printf("\nNo hubieron ingresos");
    }
    
    return 0;
}

int ingresoDatos(Productos prod[], int ce){
    int i = 0, band = -1, pos;
    char codigo[6];
    
    while(i < ce && band != 0){
        printf("Ingrese la descripcion del producto (30 caracteres)[FIN para terminar]: ");
        validacionTexto(prod[i].descripcion, 32);
        band = strcmp(prod[i].descripcion, "FIN");
        if(band != 0){
            do{
                printf("Ingrese el codigo del producto (5 caracteres): ");
                validacionPalabra(codigo, 6);
                pos = buscarCodigo(prod, codigo, i);
            }while(pos != -1);
            strcpy(prod[i].codigo, codigo);
            
            printf("Ingrese el precio (mayor a 0): ");
            prod[i].precio = validacionPrecio(0);
            
            printf("Ingrese la cantidad de ventas del mes pasado (positivo): ");
            prod[i].ventas = validacionLimite(-1);
            
            prod[i].total = prod[i].precio * prod[i].ventas;
            i++;
        }
    }
    
    return i;
}

void cargaVentas(Productos prod[], int ingresos){
    int cantidad = -1, pos;
    char codigoB[6];
    
    
    while(cantidad != 0){
        printf("Ingrese la cantidad de ventas (mayor a 0)[0 para finalizar]: ");
        cantidad = validacionLimite(-1);
        
        if(cantidad != 0){
            do{
                printf("Ingrese el codigo de venta: ");
                validacionPalabra(codigoB, 6);
                pos = buscarCodigo(prod, codigoB, ingresos);
                if(pos == -1) printf("\nEl codigo no existe");
            }while(pos == -1);
            
            prod[pos].ventas += cantidad;
        }
    }
}

int validacionLimite(int min){
    int num;
    
    do{
        scanf("%d", &num);
    }while(num < min);
    
    getchar();
    
    return num;
}

int buscarCodigo(Productos prod[], char texto[], int ce){
    int i = 0, pos = -1;
    
    while(pos == -1 && i < ce){
        if(strcmp(prod[i].codigo, texto) == 0)
            pos = i;
        else
            i++;
    }
    
    return pos;
}

float validacionPrecio(float min){
    float num;
    
    do{
        scanf("%f", &num);
    }while(num < min);
    
    getchar();
    
    return num;
}

void validacionPalabra(char texto[], int ce){
    int medida, i;
    do{
        scanf("%s", texto);
        medida = strlen(texto);
    }while(medida == 0 || medida >= ce);
          
    for(i = 0; i < medida; i++)
        texto[i] = toupper(texto[i]);
}

void validacionTexto(char texto[], int ce){
    int medida, i;
    do{
        fgets(texto, ce, stdin);
        medida = strlen(texto);
        if(texto[medida-1] == '\n'){
            texto[medida-1] = '\0';
            medida--;
        }
    }while(medida == 0 || medida > ce);
    
    for(i = 0; i < medida; i++){
        if(texto[i] != ' ') 
            texto[i] = toupper(texto[i]);
    }
}

void calcularValor(Productos prod[], int ce){
  int i;

  for(i = 0; i < ce; i++){
    prod[i].total = prod[i].precio * prod[i].ventas;
  }
}


void mostrarResultado(Productos prod[], int ce){
  int i;

  printf("\n\t\tDESCRIPCION\tCANTIDAD UNIDADES VENDIDAS\tIMPORTES");
  for(i = 0; i < ce; i++){
    printf("\n%30s\t%4d\t\t\t$%5.2f", prod[i].descripcion, prod[i].ventas, prod[i].total);
  }
}