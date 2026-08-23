/*

* DNI (entero entre 1 y 9999999)
* Codigo OS (1001 a 1020)
* Codigo practica (E T I)
* Importe tratamiento (real, mayor a 0)
* Edad paciente (1 a 100)

Fin en 0 de DNI.

1.informar el total a pagar por cada OS. informando además el código de la OS, con títulos.
2.Informar la cantidad de cada código de práctica que se atendieron.
3.Informar la edad y el DNI del paciente más joven de los pacientes que se realizaron implantes.
4.Informar el promedio pagado por los pacientes de las OS que tuvieron atención en el promedio estudiado.

*/

#include <stdio.h>
#include <ctype.h>

int validacionInt(int, int);
char validacionChar();
float validacionFloat(float);
void pagoOS(float[]);
void promedioPagado(float);


int main(){
    float pagoOs[20] = {0};

    int contE = 0, contT = 0, contI = 0, edadMenor = 101, menorDNI = 0, contPacientes = 0;
    int dni = -1, codigoOs, edad;
    char codigoPractica;
    float acumPagoPacientes = 0, promedioPago = 0, importe;

    while(dni != 0){
        dni = validacionInt(0, 99999999);

        if(dni != 0){
            codigoOs = validacionInt(1001, 1020);
            codigoPractica = validacionChar();
            importe = validacionFloat(0);
            edad = validacionInt(1, 100);

            if(edad < edadMenor && codigoPractica == 'I'){
                edadMenor = edad;
                menorDNI = dni;
            }
            pagoOs[codigoOs - 1001] += importe * 0.4;
            acumPagoPacientes += importe * 0.6;
            contPacientes++;

            switch(codigoPractica){
                case 'E': contE++; break;
                case 'T': contT++; break;
                case 'I': contI++; break;
            }
        }else{
            printf("\nIngreso finalizado");
        }
    }
    

    pagoOS(pagoOs);

    printf("\nCodigo de practica E atendidos: %d", contE);
    printf("\nCodigo de practica T atendidos: %d", contT);
    printf("\nCodigo de practica I atendidos: %d", contI);

    if(edadMenor != 101)
        printf("\nEl dni %d es del menor en implantes con %d anios", menorDNI, edadMenor);

    if(contPacientes != 0){
        promedioPago = (float) acumPagoPacientes / contPacientes;
        promedioPagado(promedioPago);
    }else{
        printf("No hubieron ingresos, por lo que no se puede sacar promedio");
    }

    return 0;
}

int validacionInt(int min, int max){
    int num;
    
    do{
        printf("Ingrese el numero (%d a %d): ", min, max);
        scanf("%d", &num);
    }while(num < min || num > max);

    return num;
}

float validacionFloat(float min){
    float num;

    do{
        printf("Ingrese el monto (mayor a %f): ", min);
        scanf("%f", &num);
    }while(num <= 0);

    return num;
}

char validacionChar(){
    char car;

    do{
        getchar();
        printf("Ingrese el caracter (E, T o I): ");
        scanf("%c", &car);
        car = toupper(car);
    }while(car != 'E' && car != 'T' && car != 'I');

    return car;
}

void pagoOS(float recaudo[]){
    int i;

    printf("\nCODIGO RECAUDO\n");
    for(i = 0; i < 20; i++){
        printf("%d %.2f\n", i+1001, recaudo[i]);
    }
}

void promedioPagado(float promedio){
    printf("\nEl promedio pagado por por los pacientes es de: %.2f", promedio);
}