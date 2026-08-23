/***********************************************************************************************************************************************
Tenías un archivo Stock.dat que guardaba la info de los productos. El struct para los productos era: 
  * código de artículo (char[])
  * descripción (char[])
  * tipo (char)
  * precio (float).
Tenías que actualizar el precio:
  -Si el tipo era 'P', tenías que pedir que ingrese un nuevo precio (verificar con un do while que no pase precio<0) y actualizarlo.
  -Si el tipo era 'H', había que sumarle un 8% al precio que ya estaba.
La actualización terminaba cuando se ingresaba como código "SALE".
Si el código de artículo que ingresbas no existía, tenías que guardarlo en Errores.dat. Ahí solo se guardaba el código, nada más (el struct
de errores era solo un char[] para el código). Si ya habias guardado un codigo de articulo como error anteriormente, no se vuelve a guardar.
**********************************************************************************************************************************************/