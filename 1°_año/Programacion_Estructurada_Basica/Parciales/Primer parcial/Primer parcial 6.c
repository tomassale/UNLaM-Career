/*************************************************************************************************************************************
La Ferreteria Industrial necesita actualizar por compras el stock de sus casi 80 productos y para ello se deben registrar y almacenar 
con la estructura adecuada a todo su inventario:

  * Numero de Producto (entero de 3 cifras no correlativo y sin repetidos)
  * Nombre Producto (string de 30 caracteres)
  * Categoria (R Repuestos, Q Quimicos, A Autopartes)
  * Cantidad Comprada (entero positivo)
  * Stock (entero mayor o igual a 0)

La carga de los Productos termina con el ingreso de Nombre Producto igual a "FINAL".
Luego para realizar la actualizacion se ingresaron por cada compra el Numero de Producto y la cantidad comprada (entero mayor a 0).
Con dicha informacion debe actualizar el stock de cantidad comprada de cada producto. La actualizacion finaliza con un Numero de 
Producto igual a 0.

Se necesita determinar e informar:
1. Listado de stock por Producto mostrando su Nombre, Categoria y Stock ordenado alfabeticamente por Nombre (resolver en una funcion).
2. El nombre del Producto con mayor stock, en caso de ser mas de uno mostrarlos a todos (resolver en una funcion).
3. La cantidad total comprada por cada Categoria.
*************************************************************************************************************************************/