/*****************************************************************************************************************************************************
El archivo Inscriptos.dat es un archivo que se genera el día en que el estudiante se inscribe a las materias para el próximo cuatrimestre. 
Este archivo contiene: 
  * DNI (entero) 
  * Código de materia (entero)
  * día y turno (entero) 
  * estado (entero) (1 aprobado, 0 rechazado) 
  * motivo del rechazo (char) (F (falta de cupo), C (adeuda correlativas)). 
Este archivo se encuentra ordenado por DNI.

1- Eliminar del archivo Inscriptos.dat todas aquellas inscripciones rechazadas por adeudar correlativas, resguardando los registros eliminados 
en un archivo histórico.

2- Generar un archivo de texto resumen que indique en total por cada materia (60 en total) la cantidad de inscripciones rechazadas por falta de cupo. 
  El archivo debe generarse en formato csv con: Nombre de la materia y cantidad de inscripciones rechazadas por falta de cupo. 
Para obtener los nombres de las materias existe un archivo llamado materias.dat que contiene código de materia (entero) y descripción (texto 
de 30 caracteres máximo).
*****************************************************************************************************************************************************/