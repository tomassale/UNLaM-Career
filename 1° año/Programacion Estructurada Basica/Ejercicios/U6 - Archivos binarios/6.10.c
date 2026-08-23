/******************************************************************************96+
******************************************
Dado el archivo pagos.dat con los pagos realizados por los alumnos a un curso, se desea registrar los
pagos de las cuotas. El archivo tiene el siguiente formato:
  • DNI
  • Fecha de último pago (3 enteros, día, mes y año)
Para registrar los pagos se ingresa el número de DNI (7 a 8 dígitos) y la fecha de pago. Se debe actualizar el
archivo de pagos, y si el DNI no se encuentra se pregunta al usuario si desea agregar un nuevo alumno. En caso
afirmativo se debe agregar un nuevo registro en dicho archivo con el nuevo pago y además agregar el nuevo
alumno al archivo alumnos.dat, dicho archivo contiene el DNI y nombre completo del alumno (40 caracteres
máximo).

Todos los datos de ingreso deben estar validados (para simplificar al validar la fecha considerar día de 1 a 31
para todos los meses).

Se procesan varios pagos hasta que se ingresa un DNI 0. Al finalizar mostrar un listado de los alumnos, DNI y
nombre de todos aquellos que adeudan la última cuota (del mes de febrero 2024). 
************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  int dia;
  int mes;
  int anio;
} Fecha;

typedef struct{
  int dni;
  Fecha pago;
} Pago;

typedef struct{
  int dni;
  char nombre[41];
} Alumno;

void ingresoDatos(FILE *pf, FILE *pfA);
void actualizarPagos(FILE *pf, int pos, Fecha nuevaFecha);
void registrarAlumno(FILE *pfA, Alumno al);
int buscarAlumno(FILE *pfA, int dni);
int buscarPago(FILE *pf, int dni);
int validacionDia(Pago pg);
void mostrarListado(FILE *pf, FILE *pfA);

int main(){
  FILE *pf, *pfA;

  pf = fopen("PAGOS.dat", "r+b");
  pfA = fopen("ALUMNOS.dat", "r+b"); 

  if(pf == NULL || pfA == NULL){
    printf("Error al abrir los archivos...\n");
    exit(1);
  }

  ingresoDatos(pf, pfA);
  
  mostrarListado(pf, pfA);

  fclose(pf);
  fclose(pfA);
  return 0;
}

void ingresoDatos(FILE *pf, FILE *pfA){
  int dni, pos;
  char respuesta;
  Pago pg;
  Alumno al;
  int c;

  printf("Ingrese el DNI (0 para fin): ");
  scanf("%d", &dni);

  while(dni != 0){
    if(dni < 1000000 || dni > 99999999){
      printf("DNI invalido. Debe tener entre 7 y 8 digitos.\n\n");
    } else {
      pg.dni = dni;
      
      do {
        printf("Ingrese fecha de ultimo pago (DD MM AAAA): ");
        scanf("%d %d %d", &pg.pago.dia, &pg.pago.mes, &pg.pago.anio);
        
        if(validacionDia(pg) == 0){
          printf("Fecha invalida. Intente nuevamente.\n");
        }
      } while(validacionDia(pg) == 0);

      pos = buscarPago(pf, dni);

      if(pos != -1){
        actualizarPagos(pf, pos, pg.pago);
        printf("Pago actualizado exitosamente.\n");
      } else {
        printf("DNI no encontrado. Desea agregar un nuevo alumno? (s/n): ");
        scanf(" %c", &respuesta);

        if(respuesta == 's' || respuesta == 'S'){
          al.dni = dni;
          
          while ((c = getchar()) != '\n' && c != EOF);

          printf("Ingrese el nombre completo: ");
          gets(al.nombre); 

          registrarAlumno(pfA, al);

          fseek(pf, 0, SEEK_END);
          fwrite(&pg, sizeof(Pago), 1, pf);
          printf("Alumno y pago registrados correctamente.\n");
        }
      }
    }

    printf("\nIngrese el DNI (0 para fin): ");
    scanf("%d", &dni);
  }
}

void actualizarPagos(FILE *pf, int pos, Fecha nuevaFecha){
  Pago pg;
  
  fseek(pf, pos * sizeof(Pago), SEEK_SET);
  fread(&pg, sizeof(Pago), 1, pf);
  
  pg.pago = nuevaFecha;
  
  fseek(pf, -(long)sizeof(Pago), SEEK_CUR);
  fwrite(&pg, sizeof(Pago), 1, pf);
  fflush(pf);
}

void registrarAlumno(FILE *pfA, Alumno al){
  fseek(pfA, 0, SEEK_END);
  fwrite(&al, sizeof(Alumno), 1, pfA);
  fflush(pfA);
}

int buscarPago(FILE *pf, int dni){
  int pos = -1, i = 0;
  Pago pg;

  rewind(pf);
  fread(&pg, sizeof(Pago), 1, pf);
  while(!feof(pf) && pos == -1){
    if(pg.dni == dni)
      pos = i;
    else
      i++;
    fread(&pg, sizeof(Pago), 1, pf);
  }
  return pos;
}

int buscarAlumno(FILE *pfA, int dni){
  int pos = -1, i = 0;
  Alumno al;

  rewind(pfA);
  fread(&al, sizeof(Alumno), 1, pfA);
  while(!feof(pfA) && pos == -1){
    if(al.dni == dni)
      pos = i;
    else
      i++;
    fread(&al, sizeof(Alumno), 1, pfA);
  }
  return pos;
}

int validacionDia(Pago pg){
  int val = 1;

  if(pg.pago.dia < 1 || pg.pago.dia > 31)
    val = 0;
  if(pg.pago.mes < 1 || pg.pago.mes > 12)
    val = 0;
  if(pg.pago.anio < 2000 || pg.pago.anio > 2100)
    val = 0;

  return val;
}

void mostrarListado(FILE *pf, FILE *pfA){
  Pago pg;
  Alumno al;
  int pos;

  rewind(pf);
  printf("\n--- ALUMNOS QUE ADEUDAN LA CUOTA (Antes de 02/2024) ---\n");
  
  fread(&pg, sizeof(Pago), 1, pf);
  while(!feof(pf)){
    if(pg.pago.anio < 2024 || (pg.pago.anio == 2024 && pg.pago.mes < 2)){
      pos = buscarAlumno(pfA, pg.dni);
      
      if(pos != -1){
        fseek(pfA, pos*sizeof(Alumno), SEEK_SET);
        fread(&al, sizeof(Alumno), 1, pfA);
        printf("DNI: %8d | Nombre: %s\n", al.dni, al.nombre);
      }
    }
    fread(&pg, sizeof(Pago), 1, pf); 
  }
}