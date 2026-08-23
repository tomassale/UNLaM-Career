/************************************************************************************************************************
Se dispone de un archivo denominado INSCRIPTOS.dat que contiene la información de los inscriptos a un
curso de programación. El archivo aún no está completo ya que la inscripción se realiza por partes. Por cada
inscripto se tiene la siguiente información:
  • DNI (entero)
  • Apellido y Nombres (texto de 20 caracteres máximo)
  • Pagado (campo entero donde 1 indica que pagó y 0 que aún adeuda la matrícula)
Se desea realizar un programa que cumpla con dos funciones:
  a. Registrar los pagos de los alumnos ya inscriptos.
  b. SI hay cupo, agregar nuevos inscriptos (el cupo máximo es de 60 alumno).
El programa solicitará el ingreso del DNI y lo buscará entre los inscriptos, en caso de que lo encuentre dará
la opción para registrar el pago (si es que no está pago ya). En caso de que no lo encuentre dará la opción
para inscribirlo al curso (el pago se realiza luego). En el momento que ya no quede cupo en el curso si llega
un nuevo inscripto se le preguntará si desea quedar registrado para un curso futuro, y en caso afirmativo
se le solicitará el teléfono y se guardará el nombre, DNI y teléfono en un archivo Interesados.dat.

El ingreso de datos finaliza con un DNI negativo.
************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int dni;
  char nombre[21];
  int pagado;
} Inscripcion;

typedef struct {
  int dni;
  char nombre[21];
  int telefono;
} Interesado;

void ingresoDatos(FILE *pf);
int contarCupos(FILE *pf);
int buscarDni(FILE *pf, int dni);
void registroPago(FILE *pf, int dni);
void ingresoInteresado(int dniBuscado);
void registrarInteresado(Interesado it);

int main() {
  FILE *pf;

  pf = fopen("INSCRIPTOS.dat", "r+b");

  if(pf == NULL) {
    printf("Error al abrir el archivo INSCRIPTOS.dat\n");
    exit(1);
  }

  ingresoDatos(pf);

  fclose(pf);
  return 0;
}

void ingresoDatos(FILE *pf) {
  int dni, pos, cupos;
  char respuesta;
  Inscripcion nuevaIns;
  int c;

  cupos = contarCupos(pf);

  printf("Ingrese el DNI del alumno (negativo para salir): ");
  scanf("%d", &dni);

  while (dni >= 0) {
    pos = buscarDni(pf, dni);

    if (pos != -1) {
      printf("El alumno ya se encuentra inscripto. Desea registrar el pago? (s/n): ");
      scanf(" %c", &respuesta);

      if (respuesta == 's' || respuesta == 'S') {
        registroPago(pf, dni);
        printf("Pago registrado exitosamente.\n");
      }
    }
    else {
      if (cupos < 60) {
        printf("Alumno no inscripto. Hay cupo disponible. Desea inscribirlo? (s/n): ");
        scanf(" %c", &respuesta);

        if (respuesta == 's' || respuesta == 'S') {
          nuevaIns.dni = dni;
          nuevaIns.pagado = 0;

          printf("Ingrese Apellido y Nombre: ");
          fgets(nuevaIns.nombre, 21, stdin);

          fseek(pf, 0, SEEK_END);
          fwrite(&nuevaIns, sizeof(Inscripcion), 1, pf);

          cupos++;
          printf("Alumno inscripto correctamente.\n");
        }
      }
      else {
        printf("El curso esta lleno (60 alumnos). Desea quedar en lista de espera? (s/n): ");
        scanf(" %c", &respuesta);

        if (respuesta == 's' || respuesta == 'S') {
          ingresoInteresado(dni);
        }
      }
    }

    printf("\nIngrese el DNI del alumno (negativo para salir): ");
    scanf("%d", &dni);
  }
}

int contarCupos(FILE *pf) {
  int cupo = 0, pos;

  fseek(pf, 0, SEEK_END);
  pos = ftell(pf);
  cupo = pos / sizeof(Inscripcion);

  rewind(pf);
  return cupo;
}

int buscarDni(FILE *pf, int dni) {
  int i = 0, pos = -1;
  Inscripcion ins;

  rewind(pf);

  fread(&ins, sizeof(Inscripcion), 1, pf);
  while(!feof(pf) && pos == -1) {
    if(dni == ins.dni)
      pos = i;
    else
      i++;

    fread(&ins, sizeof(Inscripcion), 1, pf);
  }

  return pos;
}

void registroPago(FILE *pf, int dni) {
  Inscripcion ins;
  int pos;

  pos = buscarDni(pf, dni);

  fseek(pf, pos * sizeof(Inscripcion), SEEK_SET);
  fread(&ins, sizeof(Inscripcion), 1, pf);

  if (ins.pagado == 1) {
    printf("El alumno ya tenia la matricula pagada.\n");
  } else {
    ins.pagado = 1;
    fseek(pf, -(long)sizeof(Inscripcion), SEEK_CUR);
    fwrite(&ins, sizeof(Inscripcion), 1, pf);
    fflush(pf);
  }
}

void ingresoInteresado(int dniBuscado) {
  Interesado it;
  int c;

  it.dni = dniBuscado;

  while ((c = getchar()) != '\n' && c != EOF);

  printf("Ingrese el nombre: ");
  fgets(it.nombre, 21, stdin);

  printf("Ingrese el telefono: ");
  scanf("%d", &it.telefono);

  registrarInteresado(it);
  printf("Registrado en la lista de interesados.\n");
}

void registrarInteresado(Interesado it) {
  FILE *pfI;

  pfI = fopen("INTERESADOS.dat", "ab");

  if(pfI == NULL) {
    printf("Error al abrir el archivo INTERESADOS.dat\n");
    exit(1);
  }

  fwrite(&it, sizeof(Interesado), 1, pfI);
  fclose(pfI);
}
