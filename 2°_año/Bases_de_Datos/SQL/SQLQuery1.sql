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
 SELECT * 
 FROM Proveedor;

 SELECT *
 FROM Articulo;

 SELECT *
 FROM Cliente;

 SELECT *
 FROM Pedido;

 SELECT *
 FROM Stock;

 SELECT name
 FROM sys.tables;


 
 --2. Hallar los clientes (nomCli) que solicitan artículos provistos por p015.

SELECT *
 FROM Cliente;

SELECT *
 FROM Pedido;

SELECT *
 FROM Articulo;

SELECT *
 FROM Proveedor;

SELECT *
 FROM Stock;

SELECT nomCli 
 FROM Cliente
WHERE IN(
	SELECT 
);

 --3. Hallar los clientes que solicitan algún item provisto por proveedores con categoría
 --mayor que 4.

  /*
 4. Hallar los pedidos en los que un cliente de Rosario solicita artículos producidos en
 la ciudad de Mendoza.
 */


/*
 5. Hallar los pedidos en los que el cliente c23 solicita artículos solicitados por el
 cliente c30.
 */
 --in
--eXISTS



 /*
 6. Hallar los proveedores que suministran todos los artículos cuyo precio es superior
 al precio promedio de los artículos que se producen en La Plata.
 */