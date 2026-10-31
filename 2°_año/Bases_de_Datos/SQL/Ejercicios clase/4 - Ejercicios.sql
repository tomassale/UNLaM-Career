USE EJERCICIO_2
GO

/*
Proveedor (NroProv, NomProv, Categoria, CiudadProv)
Artículo  (NroArt, Descripción, CiudadArt, Precio)
Cliente   (NroCli, NomCli, CiudadCli)
Pedido    (NroPed, NroArt, NroCli, NroProv, FechaPedido, Cantidad, PrecioTotal)
Stock     (NroArt, fecha, cantidad)
*/

-- ANTES DE EMPEZAR CON LOS DE LA GUIA:

-- 0.0 - Listar todos los proovedores
-- ? DONDE ESTAN LOS PROVEEDORES?

SELECT *
FROM Proveedor

-- 0.1 - Listar todas las categorias de los proovedores

SELECT categoria
FROM proveedor

-- 0.2 - Listar los clientes (NomCli) y las sus ciudades

SELECT NomCli, CiudadCli
FROM Cliente

-- 0.3 - Listar Clientes sin pedidos

-- clientes con pedidos:
SELECT nroCli
FROM Pedido

-- TODOS LOS CLIENTES
SELECT * 
FROM Cliente

-- CLIENTES SIN PEDIDOS

-- OPCION 1 CON NOT INT
SELECT * 
FROM Cliente
WHERE NroCli NOT IN (SELECT NroCli FROM Pedido)

-- OPCION 2 CON EXCEPT
SELECT nroCli FROM Cliente
EXCEPT 
SELECT NroCli FROM Pedido

-- 0.4 - Listar Articulos con stock

-- hacemos una junta para saber si el articulo esta en stock
SELECT *
FROM Articulo 
	JOIN Stock 
		ON Articulo.NroArt = Stock.NroArt

-- OPCION CON IN
SELECT *
FROM Articulo 
WHERE NroArt IN (SELECT NroArt FROM Stock )


-- 0.5 - Listar Articulos sin stock

SELECT *
FROM Articulo 
WHERE NroArt NOT IN (SELECT NroArt FROM Stock )

-- 0.6 - Listar Clientes (NroCli) con 4 o más pedidos

SELECT NroCli, COUNT(*) [cant de pedidos del cliente]
FROM Pedido
GROUP BY NroCli
HAVING COUNT(*) > 3



--> luego seguir con:

 --1. Hallar el código (nroProv) de los proveedores que proveen el artículo a146.
 
 SELECT DISTINCT PE.NroProv
 FROM Pedido PE
 JOIN Proveedor P
 ON P.NroProv=PE.NroProv
 JOIN Articulo A
 ON A.NroArt=PE.NroArt
 WHERE Descripcion='a146'

 
 --2. Hallar los clientes (nomCli) que solicitan artículos provistos por p015.

 SELECT DISTINCT NomCli
 FROM Pedido PE
 JOIN Proveedor PR
 ON PR.NroProv=PE.NroProv
 JOIN Cliente C
 ON C.NroCli=PE.NroCli
 WHERE NomProv = 'p015'


 --3. Hallar los clientes que solicitan algún item provisto por proveedores con categoría
 --mayor que 4.
 
 SELECT DISTINCT C.NroCli, NomCli, Categoria
 FROM Pedido PE
 JOIN Proveedor PV ON PE.NroProv = PV.NroProv
 JOIN Cliente   C  ON PE.NroCli  = C.NroCli
 WHERE PV.Categoria > 4

  /*
 4. Hallar los pedidos en los que un cliente de Rosario solicita artículos producidos en
 la ciudad de Mendoza.
 */

 SELECT PE.*
 FROM Pedido PE
 JOIN Cliente  C ON C.NroCli = PE.NroCli
 JOIN Articulo A ON A.NroArt = PE.NroArt
 WHERE CiudadArt = 'Mendoza' AND CiudadCli = 'Rosario'

/*
 5. Hallar los pedidos en los que el cliente c23 solicita artículos solicitados por el
 cliente c30.
 */
 --in
SELECT PE.*, C.NomCli
FROM Pedido PE
JOIN Cliente C ON C.NroCli = PE.NroCli
WHERE C.NomCli = 'c23'
AND PE.NroArt IN(
				SELECT PE.NroArt
				FROM Pedido PE
				JOIN Cliente C ON PE.NroCli = C.NroCli
				WHERE C.NomCli = 'c30'
				)

--eXISTS
SELECT PE.*, C.NomCli
FROM Pedido PE
JOIN Cliente C ON PE.NroCli = C.NroCli
WHERE C.NomCli = 'c23'
AND EXISTS(
			SELECT 1
			FROM Pedido P
			JOIN Cliente C ON P.NroCli = C.NroCli
			WHERE C.NomCli = 'c30'
			AND PE.NroArt=P.NroArt
		 )

 /*
 6. Hallar los proveedores que suministran todos los artículos cuyo precio es superior
 al precio promedio de los artículos que se producen en La Plata.
 */

SELECT *
FROM Proveedor
WHERE NroProv NOT IN(
					SELECT NroProv
					FROM Pedido PE
					JOIN Articulo A
					ON PE.NroArt=A.NroArt
					WHERE Precio<= (
									SELECT AVG(PRECIO)
									FROM Articulo A
									WHERE A.CiudadArt='La Plata'
									)
					)


/* 7. Hallar la cantidad de artículos diferentes provistos por cada proveedor que provee
 a todos los clientes de Junín. */

SELECT * FROM sys.tables

SELECT *
FROM 



/* 8. Hallar los nombres de los proveedores cuya categoría sea mayor que la de todos
 los proveedores que proveen el artículo “cuaderno”. */



/* 9. Hallar los proveedores que han provisto más de 1000 unidades entre los artículos A001 y A100. */



/* 10. Listar la cantidad y el precio total de cada artículo que han pedido los Clientes a
 sus proveedores entre las fechas 01-01-2004 y 31-03-2004 (se requiere visualizar
 Cliente, Articulo, Proveedor, Cantidad y Precio). */



/* 11. Idem anterior y que además la Cantidad sea mayor o igual a 1000 o el Precio sea
 mayor a $ 1000. */



/* 12. Listar la descripción de los artículos en donde se hayan pedido en el día más del
 stock existente para ese mismo día. */



/* 13. Listar los datos de los proveedores que hayan pedido de todos los artículos en un
 mismo día. Verificar sólo en el último mes de pedidos. */
 


/* 14. Listar los proveedores a los cuales no se les haya solicitado ningún artículo en el
 último mes, pero sí se les haya pedido en el mismo mes del año anterior. */



/* 15. Listar los nombres de los clientes que hayan solicitado más de un artículo cuyo
 precio sea superior a $100 y que correspondan a proveedores de Capital Federal.
 Por ejemplo, se considerará si se ha solicitado el artículo a2 y a3, pero no si
 solicitaron 5 unidades del articulo a2 */

