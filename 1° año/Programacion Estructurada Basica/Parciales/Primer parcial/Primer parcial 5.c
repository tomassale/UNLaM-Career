/*******************************************************************************************************************************************
La matriz de la función representa los asientos de un avión de 36 filas con 2 butacas de cada lado y un pasillo central. En la matriz el 
pasillo central no está representado. Si el asiento está disponible tiene la letra D, si está ocupado tiene la letra O. Se desea completar 
el código de la función para que reciba la matriz y la cantidad de asientos a reservar (1 a 4) y muestre las filas disponibles 
con asientos consecutivos.
void MostrarFilasDisponibles(char m[][4], int asientos) {//completar }. Las reglas de asignación de asientos son las siguientes:
Si es un único asiento se debe preguntar si prefiere ventanilla o pasillo. Si son 2 asientos siempre se deben buscar dos del mismo 
lado del avión. Si son 3 deben estar pegados en la misma fila por más que los separe el pasillo. Si son 4 debe estar toda la fila vacía.

Cargar: 
  * Código (texto de 5 caracteres) 
  * Descripción (texto de 30) 
  * Precio de los productos de una empresa (máximo 30 productos
La carga finaliza con código FIN). 
Luego cargar ventas indicando 
  * Código de producto
  * Cantidad vendida
  * Código de vendedor (1001 a 1009). 
Finalizando la carga de ventas con un código de vendedor igual a 0. 
Al finalizar mostrar:
a) Un listado ordenado de mayor a menor por cantidad de ventas de cada producto, mostrando código, descripción, cantidad vendida e 
importe total de ventas de dicho producto.
b) Adicionalmente mostrar un listado de la cantidad de ventas realizadas por cada vendedor
******************************************************************************************************************************************/