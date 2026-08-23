/******************************************************************************************************************************************************************************************
Un consultorio odontol�gico que atiende distintas Obras Sociales, trabaja con tres tipos de pr�cticas: Extracciones (c�digo E), Tratamiento de Conducto (c�digo T)
e implantes (c�digo I). Cada pr�ctica tiene un costo del cual el paciente abona el 60% y el resto lo abona la OS. Cada vez que un paciente se atiende se ingresa
(validar los datos con funci�n):
    * DNI (entero, entre 1 y 99999999)
    * C�digo de la Obra Social (entero, de 1001 a 1020)
    * C�digo de practica (car�cter, E, T � I)
    * Importe del tratamiento (real, mayor a cero)
    * Edad del paciente (entero, entre 1 y 100)
El registro de las atenciones finaliza con un DNI de paciente igual a 0. El importe del tratamiento que paga el paciente (60%) lo paga en el momento, mientras
que el 40% restante que le corresponde a la OS, lo pagar� dentro de los 40 d�as. Suponemos que cada paciente se presenta solamente una vez en el per�odo analizado
y para una �nica pr�ctica.
Se pide:
    a) Informar el total a pagar por cada Obra Social, informando adem�s el c�digo de la OS, con t�tulos (Funci�n).
    b) Informar la cantidad de cada c�digo de pr�ctica que se atendieron.
    c) Informar la edad y DNI del paciente m�s joven de los pacientes que se realizaron implantes.
    d) Informar el promedio pagado por los pacientes de las OS que tuvieron atenci�n en el per�odo estudiado (Funci�n).

#include <stdio.h>
#include <ctype.h>

#define OBRA_SOCIAL 20
#define CODIGO_PRACTICA 3

void pedirDatos(float[], float[], int[]);
void mostrarDatosObra(float[]);
void mostrarDatosClientes(float[]);
int validarEntero(int, int, int);
float validarFloat(float, int);
char validarChar(char);
void calcularImporte(float[], float[], float, int);
void acumularCodigo(int[], char);

int main(){
    float pagoObra[OBRA_SOCIAL] = {0};
    float pagoClientes[OBRA_SOCIAL] = {0};
    int acumulacionCodigo[CODIGO_PRACTICA] = {0};

    pedirDatos(pagoObra, pagoClientes, acumulacionCodigo);
    mostrarDatosObra(pagoObra);
    mostrarDatosClientes(pagoClientes);

    return 0;
}

char validarChar(char caracter){
    caracter = tolower(caracter);
    while(caracter != 'i' && caracter != 't' && caracter != 'e'){
        printf("Caracter invalido, ingresar nuevamente: ");
        scanf(" %c", &caracter);
        caracter = tolower(caracter);
    }
    return caracter;
}

int validarEntero(int datoEntero, int min, int max){
    while(datoEntero < min || datoEntero > max){
        printf("Numero incorrecto, ingrese nuevamente el numero: ");
        scanf("%d", &datoEntero);
    }
    return datoEntero;
}

float validarFloat(float datoFlotante, int min){
    while(datoFlotante <= min){
        printf("Numero incorrecto, ingrese nuevamente el numero: ");
        scanf("%f", &datoFlotante);
    }
    return datoFlotante;
}

void mostrarDatosObra(float importeObra[]){
    printf("\nCodigo\t|\tImporte");
    for(int i = 0; i < OBRA_SOCIAL; i++){
        printf("\nObra: %d\tCosto: %.2f", i+1001, importeObra[i]);
    }
}

void mostrarDatosClientes(float importeCliente[]){
    for(int i = 0; i < OBRA_SOCIAL; i++){
        printf("\nObra: %d\tImporte cliente: %.2f", i+1001, importeCliente[i]);
    }
}

void calcularImporte(float importeCliente[], float importeObra[], float importe, int ubicacion){
    float parteObra = importe * 0.4;
    float parteCliente = importe * 0.6;

    importeObra[ubicacion] += parteObra;
    importeCliente[ubicacion] += parteCliente;
}

void pedirDatos(float pagoObra[], float pagoCliente[], int acumulacionCodigo[]){
    int dni, edad, codigoObra;
    int
        acumulador = 0,
        menor = 100,
        dniMenor = 0;
    float importe;
    char codigoPractica;

    while(1){
        printf("\nIngrese el numero de dni (1 al 99.999.999): ");
        scanf("%d", &dni);
        if(dni == 0) {
            printf("\nIngreso de datos finalizado");
            break;
        }
        dni = validarEntero(dni, 1, 99999999);

        printf("Ingrese el codigo de obra social (1001 a 1020): ");
        scanf("%d", &codigoObra);
        codigoObra = validarEntero(codigoObra, 1001, 1020);

        printf("Ingrese el codigo de practica ('E', 'T' o 'I'): ");
        scanf(" %c", &codigoPractica);
        codigoPractica = validarChar(codigoPractica);

        printf("Ingrese el importe del tratamiento (mayor a 0): ");
        scanf("%f", &importe);
        importe = validarFloat(importe, 0);
        calcularImporte(pagoCliente, pagoObra, importe, codigoObra-1001);

        printf("Ingrese la edad del paciente (1 al 100): ");
        scanf("%d", &edad);
        edad = validarEntero(edad, 1, 100);
        if(edad < menor){
            menor = edad;
            dniMenor = dni;
        }
        acumulador++;
        acumularCodigo(acumulacionCodigo, codigoPractica);
    }
    printf("\nEl menor es de edad %d con dni %d", menor, dniMenor);
    printf("\nCodigo acumulado E: %d", acumulacionCodigo[0]);
    printf("\nCodigo acumulado I: %d", acumulacionCodigo[1]);
    printf("\nCodigo acumulado T: %d", acumulacionCodigo[2]);
}

void acumularCodigo(int vectorAcumulacion[], char codigoPractica){
    switch(codigoPractica){
    case 'e':
        vectorAcumulacion[0]++;
        break;
    case 'i':
        vectorAcumulacion[1]++;
        break;
    case 't':
        vectorAcumulacion[2]++;
        break;
    }
}
******************************************************************************************************************************************************************************************/
/******************************************************************************************************************************************************************************************
Una competencia de gimnasia art�stica est� formada por 5 disciplinas diferentes. Por cada disciplina se registra el puntaje de cada uno de los 20
deportistas (numerados del 1000 al 1019). Los puntajes se ingresan de la siguiente manera: Primero los 20 puntajes para la disciplina 1, luego los 20 de
la disciplina 2 y as� hasta completar las 5 disciplinas. Los puntajes siempre se cargan en orden comenzando por el deportista n�mero 1000 al 1019.
Por cada disciplina/deportista se ingresan 3 puntajes de cada uno de los jurados y se debe guardar el promedio de dichos puntajes. En caso de que un deportista
no tenga puntaje para esa disciplina se cargar� un 0 en el puntaje del primer jurado y no se pedir�n los otros dos.

Luego de la carga mostrar (usar una funci�n para cada punto):

1. Un listado con la suma de puntos totales de cada deportista sumando las 5 disciplinas para cada uno mostrando n�mero de deportista y puntaje total obtenido.
2. La cantidad de deportistas que no tuvieron puntaje en al menos una disciplina.

Para el ingreso de datos validados realizar una funci�n que permita ingresar el puntaje que es un n�mero real que va de 0 a 10.


#include <stdio.h>

#define NUM_DISCIPLINA 5
#define NUM_DEPORTISTAS 20
#define JUECES 3

int main(){
    int promedioPuntajes[NUM_DEPORTISTAS] = {0};
    int sumatoriaDeportistas[NUM_DEPORTISTAS] = {0};
    int deportistasNulos[NUM_DEPORTISTAS] = {0};

    pedirDatos(promedioPuntajes, sumatoriaDeportistas, deportistasNulos);
    mostrarDatos(sumatoriaDeportistas, deportistasNulos);

    return 0;
}

void pedirDatos(int promedio[], int sumatoria[], int deportistasNulos[]){

    for(int i = 0; i < NUM_DISCIPLINA; i++){
        printf("\nDisciplina %d", i+1);
        for(int j = 0; j < NUM_DEPORTISTAS; j++){
            printf("\nDeportista %d", j+1000);
            for(int k = 0; k < JUECES; k++){
                int puntuacion, puntuacionValidada;
                printf("\nPuntuacion juez %d (1 al 10): ", k+1);
                scanf("%d", &puntuacion);
                if(k == 0 && puntuacion == 0) {
                    deportistasNulos[j] = 1;
                    break;
                }
                puntuacionValidada = validarDatos(puntuacion, 1, 10);
                sumatoriaPuntos(puntuacionValidada, j, sumatoria);
                calculoPromedio(puntuacionValidada, j, i, promedio);
            }
        }
    }
}

void calculoPromedio(int puntuacionValidada, int indice, int indiceVerificador, int promedio[]){
    promedio[indice] += puntuacionValidada;
    if(indiceVerificador == 2) {
        promedio[indice] /= 3;
    }
}

void sumatoriaPuntos(int puntuacionValidada, int indice, int sumatoria[]){
    sumatoria[indice] += puntuacionValidada;
}

void mostrarDatos(int sumatoria[], int deportistasNulos[]){
    int deportistasPuntuacionNula = 0;
    for(int i = 0; i < NUM_DEPORTISTAS; i++){
        printf("\nDeportista %d: %d", i+1, sumatoria[i]);
        if(deportistasNulos[i] == 1) deportistasPuntuacionNula++;
    }
    printf("\nLa cantidad de deportistas nulos en al menos una disciplina son: %d", deportistasPuntuacionNula);
}

int validarDatos(int num, int min, int max){
    int numValidado = num;
    while(numValidado < min || numValidado > max){
        printf("\nNumero erroneo, ingreselo nuevamente (%d al %d): ", min, max);
        scanf("%d", &numValidado);
    }
    return numValidado;
}
******************************************************************************************************************************************************************************************/
/******************************************************************************************************************************************************************************************
Realizar el c�digo de un programa en lenguaje C que permita: Ingresar informaci�n de los resultados de la primera fase de un torneo de futbol. Hay 5 zonas distintas y en cada una de las
zonas se carga informaci�n de los 6 partidos jugados. Primero se cargan los partidos de la zona 1, luego los de la zona 2 y as� hasta la zona 5. Por cada partido se ingresa: n�mero del
equipo A (1 a 20); goles del partido A (0 a 20); n�mero del equipo B (1 a 20) pero distinto del equipo A; goles del equipo B (0 a 20). Por cada partido ganado se dan 3 puntos y por cada
empate 1 punto (gana el que hace m�s goles, o empatan si tienen igual cantidad de goles). Al finalizar la carga, mostrar un listado con el puntaje que obtuvo cada uno de los 20 equipos en
la primer ronda.
Para el ingreso de datos validados realizar una �nica funci�n gen�rica con par�metros y reutilizarla para todos los ingresos. En caso de error se debe mostrar un mensaje indicando que debe
volver a ingresar el dato aclarando los valores esperados. La validaci�n del equipo B distinto del B distinto del A puede realizarse fuera de la funci�n.
Separar la l�gica en funciones. El main solo debe contener la declaraci�n de la/las colecciones (vectores) y llamadas a funciones.

#include <stdio.h>

#define NUM_PARTIDOS 6
#define NUM_ZONAS 5
#define NUM_EQUIPOS 20

void pedirDatos(int[]);
void calcularPuntaje(int, int, int, int, int[]);
int validarDatos(int, int, int);
void imprimirDatos(int[]);

int main(){

    int puntos[NUM_EQUIPOS] = {0};

    pedirDatos(puntos);
    imprimirDatos(puntos);

    return 0;
}

void pedirDatos(int puntos[]){
    for(int i = 0; i < NUM_ZONAS; i++){
        for(int j = 0; j < NUM_PARTIDOS; j++){
            int equipoA, equipoB, golesA, golesB;

            printf("\nZona %d, Partido %d \n", i+1, j+1);

            printf("Ingrese el numero de equipo A (%d al %d): ", 1, NUM_EQUIPOS);
            scanf("%d", &equipoA);
            equipoA = validarDatos(equipoA, 1, NUM_EQUIPOS);

            printf("Ingrese el numero de goles (%d al %d): ", 0, 20);
            scanf("%d", &golesA);
            golesA = validarDatos(golesA, 0, 20);

            do{
                printf("Ingrese el numero de equipo B (%d al %d, y distinto al A): ", 1, NUM_EQUIPOS);
                scanf("%d", &equipoB);
                equipoB = validarDatos(equipoB, 1, NUM_EQUIPOS);
            }while(equipoA == equipoB);

            printf("Ingrese el numero de goles (%d al %d): ", 0, 20);
            scanf("%d", &golesB);
            golesB = validarDatos(golesB, 0, 20);

            calcularPuntaje(equipoA, equipoB, golesA, golesB, puntos);
        }
    }
}

void calcularPuntaje(int equipA, int equipB, int golesA, int golesB, int puntos[]){
    if(golesA > golesB){
        puntos[equipA - 1] += 3;
    }else if(golesA < golesB){
        puntos[equipB - 1] += 3;
    } else{
        puntos[equipA - 1] += 1;
        puntos[equipB - 1] += 1;
    }
}

int validarDatos(int num, int min, int max){
    while(num > max || num < min){
        printf("El numero no puede ser menor a %d ni mayor a %d, ingrese nuevamente el dato\n", min, max);
        scanf("%d", &num);
    }
    return num;
}

void imprimirDatos(int puntaje[]){
    printf("\n--- Puntajes Finales ---\n");
    for(int i = 0; i < NUM_EQUIPOS; i++){
        printf("\nEquipo %d: %d", i + 1, puntaje[i]);
    }
}

******************************************************************************************************************************************************************************************/
/******************************************************************************************************************************************************************************************
Una empresa de capacitaci�n on-line dispone de 20 cursos distintos numerados del 1 al 20. Cada curso tiene una capacidad de alumnos distinta que debe
solictarse al inicio del programa (de 15 a 50). Luego se cargan las inscripciones ingresando por cada inscripci�n, numero de curso (1 a 20), numero de
promotor (del 100 al 109) y cantidad de inscriptos (mayor a 0). Si en alg�n curso no hay capacidad para las inscripciones se deben inscribir los posibles e indicar
con un mensaje la falta de cupo. La carga de inscripciones finaliza con un c�digo de curso igual a 99. Mostrar.
    1. La cantidad de inscriptos a cada curso.
    2. Listar los n�meros de curso en los cuales hubo gente que no pudo anotarse por falta de cupo
    3. Cantidad de alumnos inscriptos por cada promotor.
Para el ingreso  de datos validados realizar las siguientes funciones:
    * Una funci�n que recibas los l�mites inferior y superior de un rango y un valor adiciones. Y retorne un n�mero entero dentro del rango enviado o el valor adiciones.
      Esta funci�n debe reutilizarse para ingresar el codigo de curso, el n�mero de promotor y la capacidad de cada curso.
    * Una funci�n para ingresar la capacidad de los 20 cursos, esta funci�n debe invocar a la funci�n anterior.
    * Una funci�n para el ingreso de la cantidad de inscriptos.


#include <stdio.h>
#include <ctype.h>

#define OBRA_SOCIAL 20
#define CODIGO_PRACTICA 3

void pedirDatos(float[], float[], int[], int*, int*);
void mostrarDatosObra(float[]);
void mostrarDatosClientes(float[]);
int validarEntero(int, int, int);
float validarFloat(float, float);
char validarChar(char);
void calcularImporte(float[], float[], float, int);
void acumularCodigo(int[], char);
float calcularPromedioPacientes(float[], int);

int main(){
    float pagoObra[OBRA_SOCIAL] = {0};
    float pagoClientes[OBRA_SOCIAL] = {0};
    int acumulacionCodigo[CODIGO_PRACTICA] = {0};
    int edadImplante = 101, dniImplante = 0;

    pedirDatos(pagoObra, pagoClientes, acumulacionCodigo, &edadImplante, &dniImplante);

    mostrarDatosObra(pagoObra);
    mostrarDatosClientes(pagoClientes);

    printf("\n\nEdad y DNI del paciente más joven con implantes: %d - %d", edadImplante, dniImplante);
    printf("\nCantidad de extracciones: %d", acumulacionCodigo[0]);
    printf("\nCantidad de implantes: %d", acumulacionCodigo[1]);
    printf("\nCantidad de tratamientos de conducto: %d", acumulacionCodigo[2]);

    float promedio = calcularPromedioPacientes(pagoClientes, OBRA_SOCIAL);
    printf("\n\nPromedio pagado por pacientes: %.2f", promedio);

    return 0;
}

char validarChar(char caracter){
    caracter = tolower(caracter);
    while(caracter != 'e' && caracter != 't' && caracter != 'i'){
        printf("Código inválido. Ingrese nuevamente (E, T, I): ");
        scanf(" %c", &caracter);
        caracter = tolower(caracter);
    }
    return caracter;
}

int validarEntero(int valor, int min, int max){
    while(valor < min || valor > max){
        printf("Valor inválido. Ingrese entre %d y %d: ", min, max);
        scanf("%d", &valor);
    }
    return valor;
}

float validarFloat(float valor, float min){
    while(valor <= min){
        printf("Valor inválido. Debe ser mayor a %.2f: ", min);
        scanf("%f", &valor);
    }
    return valor;
}

void mostrarDatosObra(float importeObra[]){
    printf("\n--- Importe a pagar por cada Obra Social ---\n");
    for(int i = 0; i < OBRA_SOCIAL; i++)
        printf("OS %d: $%.2f\n", i+1001, importeObra[i]);
}

void mostrarDatosClientes(float importeCliente[]){
    printf("\n--- Importe total pagado por pacientes ---\n");
    for(int i = 0; i < OBRA_SOCIAL; i++)
        printf("OS %d: $%.2f\n", i+1001, importeCliente[i]);
}

void calcularImporte(float importeCliente[], float importeObra[], float importe, int pos){
    float parteObra = importe * 0.4;
    float parteCliente = importe * 0.6;
    importeObra[pos] += parteObra;
    importeCliente[pos] += parteCliente;
}

void acumularCodigo(int vector[], char codigo){
    switch(codigo){
        case 'e': vector[0]++; break;
        case 'i': vector[1]++; break;
        case 't': vector[2]++; break;
    }
}

float calcularPromedioPacientes(float importeClientes[], int tam){
    float total = 0;
    int cantidad = 0;
    for(int i = 0; i < tam; i++){
        if(importeClientes[i] > 0){
            total += importeClientes[i];
            cantidad++;
        }
    }
    return (cantidad > 0) ? total / cantidad : 0;
}

void pedirDatos(float pagoObra[], float pagoCliente[], int acumulacionCodigo[], int *edadImplante, int *dniImplante){
    int dni, edad, codigoObra;
    float importe;
    char practica;

    while(1){
        printf("\nDNI (1-99999999, 0 para terminar): ");
        scanf("%d", &dni);
        if(dni == 0) break;
        dni = validarEntero(dni, 1, 99999999);

        printf("Código de obra social (1001-1020): ");
        scanf("%d", &codigoObra);
        codigoObra = validarEntero(codigoObra, 1001, 1020);

        printf("Código de práctica (E, T, I): ");
        scanf(" %c", &practica);
        practica = validarChar(practica);

        printf("Importe del tratamiento (>0): ");
        scanf("%f", &importe);
        importe = validarFloat(importe, 0);
        calcularImporte(pagoCliente, pagoObra, importe, codigoObra - 1001);

        printf("Edad del paciente (1-100): ");
        scanf("%d", &edad);
        edad = validarEntero(edad, 1, 100);

        if(practica == 'i' && edad < *edadImplante){
            *edadImplante = edad;
            *dniImplante = dni;
        }

        acumularCodigo(acumulacionCodigo, practica);
    }
}
****************************************************************************************************************************************************************************************/
/******************************************************************************************************************************************************************************************
Un estudio de mercado se está llevando a cabo para una plataforma de transmisión de videojuegos que desea evaluar el
desempeño de casi 1500 streamers que han colaborado desde distintas redes sociales en el lanzamiento de nuevos juegos.
El ingreso de los datos finaliza con un código de streamer igual a 999. Por cada streamer se ingresan los siguientes datos
(validar con función):
  * Código de streamer contratado (entero de 4 cifras)
  * Código de la red social en la que trabaja (entero de 5001 a 5030)
  * Cantidad de seguidores que tiene el streamer en la red social(entero>=0)
  * Costo pagado por seguidor por la colaboración(float>0)
Se desea conocer:
  a) Listar el código de streamer que colaboraron, informando código e importe pagado. (Función)
  b) Código/s de streamer/s que logró la mayor cantidad de seguidores durante las transmisiones. Si hay más de uno,
  informarlos a todos.
  c) Porcentaje de redes sociales que no llegó a 100.000 seguidores, entre todos los streamers.
  d) Promedio de dinero pagado por cada red social utilizada por los streamers. (Función)
******************************************************************************************************************************************************************************************/
#include <stdio.h>

void listarCodigo(int[], int[], float[]);
void promedioPagado(int[], int[], float[]);
int validacionEntero(int, int, int);
float validacionFloat(float, float, float);

int main(){
    int codigoStreamer[1500] = {0};
    int redSocialStreamer[1500] = {0};
    int seguidoresStreamer[1500] = {0};
    int sumaSeguidores[30] = {0};
    float pagoSeguidor[1500] = {0};

    int 
        contadorIngreso = 0,
        contadorMinoria = 0,
        ingreso = 0,
        mayor = 0,
        codigo = 0,
        redSocial = 0,
        seguidores = 0;
    float pago = 0;

    printf("\nIngrese el codigo de streamer (1000 a 9999): ");
    scanf(" %d", &codigo);
    while(ingreso < 1500 && codigo != 999){

        printf("\n\nStreamer %d", ingreso+1);

        printf("\nIngrese el codigo de streamer (1000 a 9999): ");
        scanf(" %d", &codigo);
        codigo = validacionEntero(codigo, 1000, 9999);

        printf("Ingrese el codigo de al red social (5001 a 5030): ");
        scanf(" %d", &redSocial);
        redSocial = validacionEntero(redSocial, 5001, 5030);
        
        //TODO MEJORAR VALIDACION
        printf("Ingrese la cantidad de seguidores (0 o más): ");
        scanf(" %d", &seguidores);
        seguidores = validacionEntero(seguidores, 0, 999999999);

        printf("Ingrese el pago por seguidor (numero con coma): ");
        scanf(" %f", &pago);
        pago = validacionFloat(pago, 0.1, 999999999.99);

        codigoStreamer[ingreso] = codigo;
        redSocialStreamer[ingreso] = redSocial;
        seguidoresStreamer[ingreso] = seguidores;
        pagoSeguidor[ingreso] = pago;
        contadorIngreso++;
        ingreso++;
    }
    printf("Ingreso finalizado");


    listarCodigo(codigoStreamer, seguidoresStreamer, pagoSeguidor);

    for(int j = 0; j < 1500; j++){
        if(seguidoresStreamer[j] > mayor) {
            mayor = seguidoresStreamer[j];
        }
    }

    for(int k = 0; k < 1500; k++){
        if(seguidoresStreamer[k] == mayor && seguidoresStreamer[k] > 0){
            printf("\nSeguidores mayor: %d\tId: %d", mayor, k);
        }
    }

    for(int i = 0; i < 1500; i++){
        int indexSumatoria = redSocialStreamer[i];
        sumaSeguidores[indexSumatoria - 5001] += seguidoresStreamer[i];
    };

    for(int i = 0; i < 30; i++){
        if(sumaSeguidores[i] < 100000) contadorMinoria++;
    };

    float porcentaje = (float) contadorMinoria * 100 / 30;

    printf("\nEl porcentaje de redes sociales menores a 100.000 es: %.2f%%", porcentaje);

    promedioPagado(redSocialStreamer, seguidoresStreamer, pagoSeguidor);

    return 0;
};

void listarCodigo(int codigo[], int seguidores[], float importe[]){
    
    float importes[1500] = {0};
    
    printf("\n\n----Datos ingresados----");

    for(int i = 0; i < 1500; i++){
        importes[i] = (float) seguidores[i] * importe[i];
    }

    for(int j = 0; j < 1500; j++){
        if(importes[j] != 0) printf("\nCodigo: %d\tImporte pagado: %.2f", codigo[j], importes[j]);
    }
};

void promedioPagado(int redSocial[], int seguidores[], float pagoSeguidor[]){
    float sumatoriaPagos[30] = {0};
    float promedioPagado[30] = {0};
    int contadorRed[30] = {0};
    
    for(int i = 0; i < 1500; i++){
        int indexRed = redSocial[i] - 5001;
        sumatoriaPagos[indexRed] += (float) seguidores[i] * pagoSeguidor[i];
        contadorRed[indexRed]++;
    }

    for(int j = 0; j < 30; j++){
        promedioPagado[j] = (float) sumatoriaPagos[j] / contadorRed[j];
        if(promedioPagado[j] > 0) printf("\nEl promedio pagado por la red social %d es: %.2f", 5001+j, promedioPagado[j]);
    }
};

int validacionEntero(int numero, int min, int max){
    if(numero < min || numero > max){
        while (getchar() != '\n');
        printf("Valor invalido, ingrese nuevamente el dato (%d a %d): ", min, max);
        scanf(" %d", &numero);
        return validacionEntero(numero, min, max);
    }
    return numero;
};

float validacionFloat(float numero, float min, float max){
    if(numero < min || numero > max){
        while (getchar() != '\n');
        printf("Valor invalido, ingrese nuevamente el dato (%.2f a %.2f): ", min, max);
        scanf(" %f", &numero);
        return validacionFloat(numero, min, max);
    }
    return numero;
};