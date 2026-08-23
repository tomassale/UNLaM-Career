/**********************************************************************************************************************************************
Una empresa de taxis necesita gestionar el historial de servicios mecánicos de cada auto de su flota de 50 vehículos durante un mes. 
La empresa también registra a los mecánicos que trabajan en el mantenimiento de la flota. Al inicio del programa, se deben cargar los 
datos de los casi 100 mecánicos disponibles. Por cada mecánico, se ingresa la siguiente información:
    * ID de Mecánico (entero, mayor a cero)
    * Especialidad (Carácter, 'E' para Electricidad, 'M' para Mecánica General, 'C' para Chapa y Pintura)
La carga de mecánicos finaliza cuando se ingresa un ID de Mecánico igual a cero.

Posteriormente, se procesan los servicios mecánicos realizados por cada taxi durante el mes. Por cada servicio se registra:
    * Número de Taxi (entero, de 1 a 50)
    * Tipo de Servicio (carácter, 'E', 'M' o 'C')
    * ID de Mecánico Asignado
    * Horas Invertidas (entero, entre 1 y 168)
La carga de servicios finaliza cuando se ingresa un Número de Taxi igual a cero. Si el ID de Mecánico Asignado no existe en el 
lote inicial de mecánicos, se debe informar la situación; el servicio de mantenimiento para ese taxi será rechazado.

Se pide:

    a) Porcentaje de cada especialidad requerida respecto del total.
    b) Mostrar el ID de Mecánico que fue asignado a la mayor cantidad de servicios de mecánica (sin contar los servicios 
    rechazados). Puede haber más de uno. FUNCIÓN
    c) Mostrar, para cada taxi, el Número de Taxi y la cantidad total de horas de mantenimiento (en cualquier especialidad) que 
    se le invirtieron durante el mes. FUNCIÓN
**********************************************************************************************************************************************/

#include <stdio.h>
#include <ctype.h>

int buscarCodigo(int, int, int[]);
void mayoresServicios(int, int[], int[]);
void mostrarDatos(int[]);

int main(){
    int idMecanico[100] = {0};
    char especialidades[100];
    int contServicios[100] = {0};
    int horasMantenimiento[50] = {0};

    int ingresos = 0, id = -1;
    int numTaxi = -1, idBuscar, horasInvertidas, pos;
    int contE = 0, contM = 0, contC = 0, contTotal = 0;
    char especialidad, servicio;

    while(id != 0 && ingresos < 100){
        do{
            printf("Ingrese el id del mecanico (mayor a 0 ó 0 para fin): ");
            scanf("%d", &id);
        }while(id < 0);
        
        if(id != 0){
            do{
                getchar();
                printf("Ingrese la especialidad del mecanico (E, M o C): ");
                scanf("%c", &especialidad);
                especialidad = toupper(especialidad);
            }while(especialidad != 'E' && especialidad != 'M' && especialidad != 'C');

            idMecanico[ingresos] = id;
            especialidades[ingresos] = especialidad;
            ingresos++;
        }
    }

    while(numTaxi != 0 && ingresos != 0){
        do{
            printf("Ingrese el numero de taxi (1 a 50 y 0 para fin): ");
            scanf("%d", &numTaxi);    
        }while(numTaxi < 0 || numTaxi > 50);

        if(numTaxi != 0){
            do{
                getchar();
                printf("Ingrese el servicio a hacer (E, M o C): ");
                scanf("%c", &servicio);
                servicio = toupper(servicio);
            }while(servicio != 'E' && servicio != 'M' && servicio != 'C');

            printf("Ingrese el mecanico a asignar: ");
            scanf("%d", &idBuscar);

            pos = buscarCodigo(ingresos, idBuscar, idMecanico);

            if(pos != -1){
                do{
                    printf("Ingrese la cantidad de hora invertidas (1 a 168): ");
                    scanf("%d", &horasInvertidas);
                }while(horasInvertidas < 1 || horasInvertidas > 168);
                
                horasMantenimiento[numTaxi-1] += horasInvertidas;
                switch(servicio){
                    case 'E': contE++; break;
                    case 'M': contM++; break;
                    case 'C': contC++; break;
                }
                contTotal++;
                contServicios[pos]++;

            }else{
                printf("Servicio rechazado\n");
            }
        }else{
            printf("Ingreso finalizado\n");
        }
    }

    
    if(contTotal != 0 || ingresos != 0){
        printf("\nPORCENTAJES DE ESPECIALIDAD\n");
        printf("\nEspecialidad E: %.2f%%", (float)(contE * 100) / contTotal);
        printf("\nEspecialidad M: %.2f%%", (float)(contM * 100) / contTotal);
        printf("\nEspecialidad C: %.2f%%", (float)(contC * 100) / contTotal);

        mayoresServicios(ingresos, idMecanico, contServicios);
        mostrarDatos(horasMantenimiento);
    }else{
        printf("\nNo se ingresaron datos");
    }

    return 0;
}

int buscarCodigo(int ingresos, int codigo, int codigos[]){
    int i = 0, band = 0;

    while(i < ingresos && band != 1){
        if(codigo == codigos[i]){
            band = 1;
        }else{
            i++;
        }
    }
    if(band == 0) i = -1;

    return i;
}

void mayoresServicios(int ingresos, int codigos[], int servicios[]){
    int i, mayor = servicios[0];

    for(i = 0; i < ingresos; i++){
        if(servicios[i] > mayor) mayor = servicios[i];
    }

    for(i = 0; i < ingresos; i++){
        if(servicios[i] == mayor)
            printf("\nEl mecanico %d tuvo la mayor cantidad de servicios (%d)", codigos[i], mayor);
    }
}

void mostrarDatos(int horas[]){
    int i;

    printf("\nTAXI HORAS\n");
    for(i = 0; i < 50; i++){
        printf("%d\t%d\n", i+1, horas[i]);
    }
}