/***********************************************************************************************************************************
Una entidad educativa posee una pagina web con material disponible para descargar por los alumnos. La entidad desea contabilizar las 
descargas que se realizaron para los casi 100 archivos utilizados en el mes de Enero 2025. La informacion es la siguiente:
  * Codigo de archivo (entero, de 4 cifras)
  * Nombre del archivo (char, 30 caracteres)
  * Nombre de la materia (char, 30 caracteres)
La carga de datos finaliza con nombre de archivo igual a "FIN". Utilizar una funcion para dicho proceso llamada CARGAR_ARCHIVOS(). 
No se admiten codigos de archivos duplicados.

Luego, se ingresan de a una descarga por archivo y dia, finalizando con codigo de archivo igual a 999. El ingreso de estos datos 
tiene el siguiente formato:
  * Codigo de archivo (entero, de 4 cifras)
  * Dia de descarga (entero, 1 a 31)
Utilizar una funcion para dicho proceso llamada INGRESO_DESCARGAS().

Se pide desarrollar un programa en lenguaje C que cumpla con las siguientes consignas:

Informar para cada archivo la cantidad de descargas para cada dia, informando nombre del archivo y la cantidad de descargas dia por 
dia de la siguiente manera:

Nombre de Archivo | dia 1 | dia 2 | dia 3 | dia 4 | .......... | dia 31
------------------------------------------------------------------------

El o los nombres de los archivos que no tienen descargas el dia 25.
*************************************************************************************************************************************/