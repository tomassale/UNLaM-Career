/*******************************************************************************************************************************************
struct vendedor: 
  * char codigoDeVendedor[5]
  * char nombre[31]
  * int porcentajeDeComision
  * float dineroObtenidoPorComision
struct Venta: 
  * char rubro
  * char codigoDeVendedor[5]
  * float precioUnitario.
Procesar todas las ventas de ventas.dat. Si se encuentra al vendedor en cuestión en vendedores.dat, hay que sobreescribir su registro para 
aumentar su ganancia de comisiones. Si no, se añade un registro a errores.dat.
mostrar el nombre del vendedor que obtuvo la menor comisión. Si más de uno la obtuvo, mostrarlos a todos. 
Finalmente, mostrar con corte de control qué porcentaje del total facturado corresponde a comisiones de vendedores, según el rubro.
******************************************************************************************************************************************/