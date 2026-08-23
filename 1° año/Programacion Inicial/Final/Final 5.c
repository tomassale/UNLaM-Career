/*************************************
La Subsecretaría de Políticas Universitarias (SPU) recibe de forma anual el detalle de la actividad
académica de las casi 2800 Instituciones de Educación Superior Nacionales (universitarios y no universitarios)
que existen en la actualidad. Para ello cuenta con un primer lote de información con los siguientes datos de
cada Institución:
  • Código de la Institución (entero, entre 1000 y 9999).
  • Tipo de Institución (caracter, ‘U’: Universitaria, ‘I’: Instituto no Universitario)

  Este lote de información termina con un código de Institución igual a cero.

En un segundo lote de datos se ingresan los datos enviados por las Instituciones durante el período en estudio,
con el siguiente detalle:
  • Código de la Institución.
  • Código de la materia-comisión (entero, mayor a cero)
  • Cantidad de alumnos que aprobaron la cursada (entero, mayor o igual a 0).
La finalización de la carga de este segundo lote se da por un Código de Institución igual a cero.

Se pide lo siguiente:
  a) Informar, al finalizar el período estudiado, el promedio de notas de Universidades y de Institutos no  Universitarios.
  b) Informar por Código de Institución, la cantidad de alumnos que aprobaron la cursada en cualquiera de los tipos de Institución con el siguiente diseño:
  CÓD. DE INSTITUCIÓN CANT. DE ALUMNOS QUE APROBARON
  c) Informar el porcentaje de instituciones que tuvieron menos de 100 aprobados respecto del total de instituciones
***************************************/

#include <stdio.h>
#include <ctype.h>

int buscarCodigo(int, int, int[]);
void informarAprobados(int, int[], int[]);
void informarPromedio(int, int[]);

int main(){
    int codigoInstitucion[2800] = {0};
    char tipoInstitucion[2800];
    int alumnosAprobados[2800] = {0};
    
    int ingresos = 0, codigoInst = 1, pos, buscaCod = -1, codigoMateria, alumnosAprob;
    int acumUni = 0, contUni = 0, acumNUni = 0, contNUni = 0;
    char tipoInst;
    
    while(codigoInst != 0 && ingresos < 2800){
      do{
          printf("Ingrese el codigo del instituto (1000 a 9999): ");
          scanf("%d", &codigoInst);
      }while((codigoInst < 1000 || codigoInst > 9999) && codigoInst != 0);
      
      if(codigoInst != 0){
          do{
              getchar();
              printf("Ingrese el tipo de institucion (U o I): ");
              scanf("%c", &tipoInst);
              tipoInst = toupper(tipoInst);
          }while(tipoInst != 'U' && tipoInst != 'I');
          
          codigoInstitucion[ingresos] = codigoInst;
          tipoInstitucion[ingresos] = tipoInst;
          ingresos++;
      }
    }
    
    while(buscaCod != 0){
      printf("Ingrese el codigo a buscar: ");
      scanf("%d", &buscaCod);
      
      pos = buscarCodigo(ingresos, buscaCod, codigoInstitucion);
      
      if(pos != -1){
          do{
              printf("Ingrese el codigo de la materia (mayor a 0): ");
              scanf("%d", &codigoMateria);
          }while(codigoMateria < 1);
          do{
              printf("Ingrese la cantidad de alumnos aprobados (mayor a 0): ");
              scanf("%d", &alumnosAprob);
          }while(alumnosAprob < 0);
          
          alumnosAprobados[pos] += alumnosAprob;
          if(tipoInstitucion[pos] == 'U'){
              acumUni += alumnosAprob;
              contUni++;
          }else{
              acumNUni += alumnosAprob;
              contNUni++;
          }
       }
    }
    
    if(contUni > 0) printf("Promedio aprobados universidades: %.2f\n", (float) acumUni / contUni);
    if(contNUni > 0) printf("Promedio aprobados institutos: %.2f\n", (float) acumNUni / contNUni);
    
    informarAprobados(ingresos, codigoInstitucion, alumnosAprobados);
    informarPromedio(ingresos, alumnosAprobados);
    
    return 0;
}  

int buscarCodigo(int ingresos, int codigo, int codigos[]){
    int i = 0, band = 0;
    
    while(band != 1 && i < ingresos){
        if(codigo == codigos[i]){
            band = 1;
        }else{
            i++;
        }
    }
    if(band == 0){
        i = -1;
        printf("Codigo no encontrado\n");
    }
    return i;
}

void informarAprobados(int ingresos, int codigos[], int aprobados[]){
    int i;
    
    printf("\nCOD. DE INSTITUCION  CANT. DE ALUMNOS QUE APROBARON\n");
    for(i = 0; i < ingresos; i++){
        printf("%d  \t\t\t\t\t%d\n", codigos[i], aprobados[i]);
    }
}

void informarPromedio(int ingresos, int aprobados[]){
    int i;
    float porcentaje, contPorcentaje = 0;
    
    for(i = 0; i < ingresos; i++){
        if(aprobados[i] < 100) contPorcentaje++;
    }
    
    if(ingresos > 0){
           porcentaje = contPorcentaje * 100 / ingresos;
        printf("\nEl porcentaje de menores de 100 aprobados es %.2f%%", porcentaje); 
    }
}