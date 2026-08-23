
/******************************************************************************************************************************************************************************
1.Realizar programa que invoque función sin retorno y permita ingresar por teclado un código (int) y una marca (string). Las variables se muestran en el main luego de invocar
la función.
******************************************************************************************************************************************************************************/


#include <stdio.h>

void IngresarDatos (int*, char*);

int main()
{
    int cod = 0;
    char marca[31];
    int *ptrNum;

    ptrNum = &cod;

    IngresarDatos(ptrNum, marca);

    printf("Codigo registrado en el main: %d\n", cod);
    printf("Marca registrada en el main: %s\n", marca);

    return 0;
}

void IngresarDatos (int *ptrNum, char *pMarca){

    printf("Ingrese el codigo: ");
    scanf("%d", ptrNum);

    printf("Ingrese la marca del producto: ");
    scanf("%s", pMarca);
}


/******************************************************************************************************************************************************************************
Una empresa de transporte logístico necesita actualizar los montos atrasados de sus choferes tercerizados. Para ello cuenta con un archivo llamado fleteros.dat con la
siguiente estructura:
    *CODIGO (string 3 caracteres)
    *Nombre (string 30 caracteres)
    *Monto (real)
    *Condición (char 'A' o 'B')
Por otro lado, los viajes rendidos en el dia se encuentran en viajes.dat (ordenados por código) con la estructura :
    *CODIGO (string 3 caracteres)
    *Cant viajes (int)
    *Tarifa por viaje (real)
Se solicita actualizar el monto a liquidar de fleteros.dat. Si un chofer que rindió viajes no figura en el archivo maestro se debe registrar la anomalía en un archivo de texto
“rechazos.txt” guardando el código de chofer. Al final eliminar de “fleteros.dat” a los choferes de baja “B”.
*****************************************************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char codigo[4];
    char nombre[31];
    float monto;
    char condicion;
} Fletero;

typedef struct{
    char codigo[4];
    int cantViajes;
    float tarifa;
} Viaje;

void corteControl(FILE *pf, FILE *pfV);
void escribirMonto(FILE *pf, float, char[]);
int buscarCodigo(FILE *pf, char[]);
void borrarFleteros();
void registrarAnomalia(char[]);

int main(){
    FILE *pf, *pfV;

    pf = fopen("fleteros.dat", "r+b");
    pfV = fopen("viajes.dat", "rb");


    if(pf == NULL || pfV == NULL){
        printf("Error al abrir el archivo...");
        exit(1);
    }

    corteControl(pf, pfV);

    fclose(pf);
    fclose(pfV);

    borrarFleteros(pf);

    return 0;
}

void corteControl(FILE *pf, FILE *pfV){
    Viaje vj;
    char text[4];
    float acumMonto = 0;

    fread(&vj, sizeof(Viaje), 1, pfV);
    while(!feof(pfV)){
        strcpy(text, vj.codigo);
        acumMonto = 0;
        while(!feof(pfV) && strcmp(text,vj.codigo) == 0){
            acumMonto += vj.cantViajes * vj.tarifa;
            fread(&vj, sizeof(Viaje), 1, pfV);
        }
        escribirMonto(pf, acumMonto, text);

    }
}

void borrarFleteros(){
    Fletero fl;
    FILE *pfTmp;
    FILE *pf;

    pfTmp = fopen("fleteros.tmp", "wb");
    pf = fopen("fleteros.dat", "rb");

    if(pfTmp == NULL || pf == NULL){
        printf("Error al abrir el archivo...");
        exit(1);
    }

    fread(&fl, sizeof(Fletero), 1, pf);
    while(!feof(pf)){
        if(fl.condicion != 'B'){
            fwrite(&fl, sizeof(Fletero), 1, pf);
        }
        fread(&fl, sizeof(Fletero), 1, pf);
    }

    fclose(pf);
    fclose(pfTmp);

    remove("fleteros.dat");
    rename("fleteros.tmp", "fleteros.dat");
}

void escribirMonto(FILE *pf, float monto, char codigo[]){
    int pos;
    Fletero fl;

    pos = buscarCodigo(pf, codigo);
    if(pos != -1){
        fseek(pf, pos*sizeof(Fletero), SEEK_SET);
        fread(&fl, sizeof(Fletero), 1, pf);
        fl.monto += monto;
        fseek(pf, -1*sizeof(Fletero), SEEK_CUR);
        fwrite(&fl, sizeof(Fletero), 1, pf);
        fflush(pf);
    }else{
        registrarAnomalia(codigo);
    }
}

int buscarCodigo(FILE *pf, char codigo[]){
    int i = 0, pos = -1;
    Fletero fl;

    rewind(pf);
    fread(&fl, sizeof(Fletero), 1, pf);
    while(!feof(pf) && pos == -1){
        if(strcmp(fl.codigo, codigo) == 0){
            pos = i;
        }
        else{
            i++;
            fread(&fl, sizeof(Fletero), 1, pf);
        }
    }
    return pos;
}

void registrarAnomalia(char cod[]){
    FILE *pfF;

    pfF = fopen("rechazos.txt", "at");

    if(pfF == NULL){
        printf("Error al abrir el archivo...");
        exit(1);
    }

    fprintf(pfF, "%s\n", cod);

    fclose(pfF);
}
