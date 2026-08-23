/************************************************************************************************************************
La empresa de colectivos línea 166 desea saber cuánto debe cobrar en un mes determinado según los
viajes realizados y registrados en el sistema mediante la tarjeta SUBE para ello dispone de un archivo
de viajes los viajes del mes que está ordenado por número de Interno (colectivo) que contiene la siguiente
información:
  • Número de Interno (entero)
  • Número tarjeta SUBE (entero)
  • Código de Tarifa (texto de 10 caracteres máximo)
  • Día (entero)
  • Hora (entero)
Se dispone de un segundo archivo llamado tarifas.dat que contiene información de las tarifas por cada mes con
la siguiente estructura:
  • Mes (entero)
  • Código de Tarifa (texto de 10 caracteres máximo)
  • Precio (float)
Se sabe que como máximo se manejan 8 tarifas distintas en cada mes.
Se solicita:
  a. Ingresar por teclado el mes a procesar y recuperar las tarifas correspondientes
  b. Mostrar el importe total a cobrar por la empresa
  c. Generar un archivo que contenga la cantidad de viajes y la recaudación de cada interno en el mes.
  d. Informar el interno que realizó menos cantidad de viajes
  e. Por cada interno mostrar cuantos viajes se realizaron por cada tipo de tarifa ordenado por cantidad de
  viajes en forma descendente.
Funciones obligatorias:
  • CargaTarifas: que levanta a un vector en memoria las tarifas del mes ingresado por teclado.
  • OrdenarViajes: para ordenar los viajes según lo pedido en el punto e.
  • MostrarViajes: para mostrar en forma de listado los viajes ordenados del punto e.
************************************************************************************************************************/