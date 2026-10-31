 --1. Hallar el código (nroProv) de los proveedores que proveen el artículo a146.
 
 select distinct pe.NroProv
 from  [dbo].[Pedido] pe
  join Articulo a
 on a.NroArt=pe.NroArt
 WHERE A.Descripcion='a146'




 
 --2. Hallar los clientes (nomCli) que solicitan artículos provistos por p015.


 SELECT  DISTINCT NomCli
 FROM Pedido PE
 JOIN Proveedor PR
 ON PR.NroProv=PE.NroProv
 JOIN Cliente C
 ON C.NroCli=PE.NroCli
 WHERE NomProv ='p015'


 --3. Hallar los clientes que solicitan algún item provisto por proveedores con categoría
 --mayor que 4.

 SELECT  *--NroCli
 FROM Pedido PE
 JOIN Proveedor PR
 ON PE.NroProv=PR.NroProv
 WHERE PR.Categoria>4

  /*
 4. Hallar los pedidos en los que un cliente de Rosario solicita artículos producidos en
 la ciudad de Mendoza.
 */
SELECT  P.*
FROM [dbo].[Pedido] P
JOIN [dbo].[Cliente] C
ON P.[NroCli] =C.[NroCli]
JOIN  [dbo].[Articulo] A
ON A.[NroArt]=P.[NroArt] 
WHERE  C.[CiudadCli]='Rosario' AND A.[CiudadArt]='Mendoza'


/*
 5. Hallar los pedidos en los que el cliente c23 solicita artículos solicitados por el
 cliente c30.
 */
 --in
  SELECT P.*
 FROM Pedido P
 JOIN Cliente C
 ON P.NroCli=C.NroCli
 WHERE C.NomCli='c23'
 AND P.NroArt IN(
				  SELECT PE.NroArt
				 FROM Pedido PE
				 JOIN Cliente C
				 ON PE.NroCli=C.NroCli
				 WHERE C.NomCli='c30'
				)

--eXISTS

 SELECT P.*
 FROM Pedido P
 JOIN Cliente C
 ON P.NroCli=C.NroCli
 WHERE C.NomCli='c23'
 AND EXISTS  (
				SELECT 1
				 FROM Pedido PE
				 JOIN Cliente C
				 ON PE.NroCli=C.NroCli
				 WHERE C.NomCli='c30'
				 AND  PE.NroArt=P.NroArt

				)

 --

 SELECT P.NroArt
 FROM Pedido P
 JOIN Cliente C
 ON P.NroCli=C.NroCli
 WHERE C.NomCli='c23'

 INTERSECT 
 SELECT PE.NroArt
 FROM Pedido PE
 JOIN Cliente C
 ON PE.NroCli=C.NroCli
 WHERE C.NomCli='c30'

 /*
 6. Hallar los proveedores que suministran todos los artículos cuyo precio es superior
 al precio promedio de los artículos que se producen en La Plata.
 */
  SELECT AVG(PRECIO)
			 FROM Articulo A
			 WHERE A.CiudadArt='La Plata'



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


 /*
 7. Hallar la cantidad de artículos diferentes provistos por cada proveedor que provee
 a todos los clientes de Junín.
 */
SELECT  *
FROM  [dbo].[Proveedor] PP
WHERE NOT EXISTS (
					SELECT 1
					FROM [dbo].[Cliente] C
					WHERE [CiudadCli]='Junín' and
						NOT EXISTS (
										SELECT 1
										FROM [dbo].[Pedido] P
										WHERE P.[NroProv]=PP.[NroProv] 
											AND C.[NroCli]=P.[NroCli]
											)
					)
										
--rESULTADO
SELECT [NroProv],COUNT(DISTINCT [NroArt]) CANT_ART
FROM [dbo].[Pedido] PE
WHERE PE.[NroProv] IN (
							SELECT [NroProv]
							FROM [dbo].[Proveedor] PP
							WHERE NOT EXISTS (
												SELECT 1
												FROM [dbo].[Cliente] C
												WHERE [CiudadCli]='Junín' and
													NOT EXISTS (
																	SELECT 1
																	FROM [dbo].[Pedido] P
																	WHERE P.[NroProv]=PP.[NroProv]
																		AND C.[NroCli]=P.[NroCli]
																		)
												)


						)
GROUP BY [NroProv]

/* 8. Hallar los nombres de los proveedores cuya categoría sea mayor que la de todos
 los proveedores que proveen el artículo “cuaderno”.
 */

 SELECT *
 FROM Proveedor
 WHERE Categoria >(

				 SELECT MAX(PR.Categoria)
				 FROM Pedido PE
				 JOIN Proveedor PR
				 ON PE.NroProv=PR.NroProv
				 JOIN Articulo A
				 ON A.NroArt=PE.NroArt
				 WHERE A.Descripcion='cuaderno'
				 )
---

 SELECT *
 FROM Proveedor
 WHERE Categoria >  ALL (

				 SELECT PR.Categoria
				 FROM Pedido PE
				 JOIN Proveedor PR
				 ON PE.NroProv=PR.NroProv
				 JOIN Articulo A
				 ON A.NroArt=PE.NroArt
				 WHERE A.Descripcion='cuaderno'
				 )



 /*
 9. Hallar los proveedores que han provisto más de 1000 unidades entre los artículos
 A001 y A100.
 */

 SELECT NroProv,SUM(Cantidad)
 FROM Pedido PE
 JOIN Articulo A
 ON  A.NroArt=PE.NroArt
 WHERE A.Descripcion BETWEEN 'A001' AND 'A100'
 GROUP BY NroProv
 HAVING SUM(Cantidad)>1000




 /*

 10. Listar la cantidad y el precio total de cada artículo que han pedido los Clientes a
 sus proveedores entre las fechas 01-01-2004 y 31-03-2004 (se requiere visualizar
 Cliente, Articulo, Proveedor, Cantidad y Precio).
 */

 SELECT  NroCli,NroArt,NroProv, SUM(Cantidad),SUM(PrecioTotal)
 FROM Pedido PE
 WHERE FechaPedido BETWEEN  '2004-01-01' AND '2004-03-31'
 GROUP BY  NroCli,NroArt,NroProv


 /*
 11. Idem anterior y que además la Cantidad sea mayor o igual a 1000 o el Precio sea
 mayor a $ 1000.
 */
  SELECT  NroCli,NroArt,NroProv, SUM(Cantidad) CantidadTotal,SUM(PrecioTotal) PrecioTotal
 FROM Pedido PE
 WHERE FechaPedido BETWEEN  '2004-01-01' AND '2004-03-31'
 GROUP BY  NroCli,NroArt,NroProv
 HAVING SUM(Cantidad)>100 OR  SUM(PrecioTotal) >1000




 /*
 12. Listar la descripción de los artículos en donde se hayan pedido en el día más del
 stock existente para ese mismo día.
 */


SELECT PE.NroArt,PE.FechaPedido,SUM(Cantidad)
FROM Pedido PE

GROUP BY PE.NroArt,PE.FechaPedido
HAVING SUM(Cantidad) >(
							SELECT [cantidad]
							FROM Stock S
							WHERE S.NroArt=PE.NroArt
							AND S.fecha=PE.FechaPedido
						)



 /*

 13. Listar los datos de los proveedores que hayan pedido de todos los artículos en un
 mismo día. Verificar sólo en el último mes de pedidos.
 */
 
SELECT P.NroProv ,pE.FechaPedido,COUNT(DISTINCT PE.NroArt)
FROM [dbo].[Proveedor] P
JOIN [dbo].[Pedido] PE
ON P.NroProv=PE.NroProv
GROUP BY P.NroProv ,pE.FechaPedido
HAVING COUNT(DISTINCT PE.NroArt)= (

									SELECT COUNT(*)
									FROM [dbo].[Articulo]
									)

 

 /*
 14. Listar los proveedores a los cuales no se les haya solicitado ningún artículo en el
 último mes, pero sí se les haya pedido en el mismo mes del año anterior.
 */
 SELECT *
FROM [dbo].[Proveedor] PR
WHERE NOT EXISTS (
					SELECT 1
					FROM [dbo].[Pedido] P1
					WHERE PR.[NroProv]=P1.[NroProv]
					AND [FechaPedido] BETWEEN DATEADD(mm,-1,DATEADD(mm,DATEDIFF(mm,0,GETDATE()),0))    AND EOMONTH(GETDATE(),-1) 
					--DATEADD(MM, -1,GETDATE())

				)
and  exists (
SELECT 1
					FROM [dbo].[Pedido] P1
					WHERE PR.[NroProv]=P1.[NroProv]
					AND [FechaPedido] BETWEEN DATEADD(mm,-1,DATEADD(mm,DATEDIFF(mm,0,dATEADD(year, -1, getdate())),0))    AND EOMONTH(dATEADD(year, -1, getdate()),-1) 

			)

 /*
 15. Listar los nombres de los clientes que hayan solicitado más de un artículo cuyo
 precio sea superior a $100 y que correspondan a proveedores de Capital Federal.
 Por ejemplo, se considerará si se ha solicitado el artículo a2 y a3, pero no si
 solicitaron 5 unidades del articulo a2



 */


 SELECT   P.NroCli,COUNT( DISTINCT P.[NroArt])
FROM [dbo].[Cliente] C
JOIN [dbo].[Pedido] P
ON  C.[NroCli]=P.[NroCli]
JOIN [dbo].[Articulo] A
ON A.NroArt=P.NroArt
JOIN [dbo].[Proveedor] PR
ON PR.NroProv=P.NroProv
WHERE A.Precio>100
AND  PR.CiudadProv='Capital Federal'
GROUP BY P.NroCli
HAVING COUNT( DISTINCT P.[NroArt])>=2


