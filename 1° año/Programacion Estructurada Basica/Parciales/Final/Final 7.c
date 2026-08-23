/*******************************************************************************************************************************************
Se dispone del archivo inscripciones.dat con registros con el siguiente formato:
  * typedef struct {int dni; char codigoCurso[11] } sInsc;
Por otro lado, se dispone de un segundo archivo llamado Cursos.dat con registros con el siguiente formato:
  * typedef struct {char codigoCurso[11]; int codigoDeMateria; int capacidad; int inscriptos} sCur;

Se sabe que como máximo hay inicialmente 50 cursos distintos y que el campo inscriptos es igual a 0. Tomando en cuenta ambos archivos se 
desea realizar un programa en lenguaje C que permita:
1. Actualizar el archivo Cursos.dat con la cantidad de inscriptos (no debe sobrepasar la capacidad).
2. En el caso de que se sobrepase la capacidad de un curso se debe agregar un nuevo registro con todos los que no entraron en el 
   curso original por capacidad, poniendo en el campo capacidad un -1 para indicar que es un curso agregado y el código de curso debe 
   ser igual al original, pero con una letra B agregada al final del código.
3. Actualizar el archivo inscripciones cambiando el código de curso para aquellos alumnos que fueron inscriptos en un curso tipo B.

Para aprobar (nota 4) debe tener al menos el 60% del parcial correcto (6 ptos) y no tener errores conceptuales. No se permiten preguntas la 
interpretación del enunciado es parte de la evaluación. Respetar las reglas de la programación estructurada, haciendo un uso correcto de las 
estructuras Utilizar identificadores de variables representativos al contenido. Usar letra imprenta clara en birome. El código debe estar 
correctamente tabulado. No está permitido el uso de variables globales
*******************************************************************************************************************************************/