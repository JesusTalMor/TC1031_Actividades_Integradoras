# Actividad Integradora 4 Grafos

## Tienda de objetos mejorada de League of Legends

El programa aqui presentado es una nueva mejora para la tienda de objetos para la clase mago del juego MOBA de League of Legends dessaroolado por la empresa de Riot Games. Dentro de este nuevo y mejorado catalogo que fue cambiado debido a cambios de pretemporada, se presentan 41 objetos diferentes de la clase mago y ahora con la implementacion de un grafo se pueden observar las conexiones entre los objetos y como estos pueden evolucionar a objetos mucho mas poderosos. Dentro de el txt ObjetosActualizadosGuia.txt se podrán observar las clases y atributos de todos los objetos presentados.

Para esta cuarta entrega se implemento un grafo asiclico direccionado, con el cual la principal función es mostrar las conexiones como las evoluciones y componentes que puede tener un objeto dentro de la tienda, mostrando como algunos objetos se conectan con todos y todas las posibles combianciones que puedes crear con un objeto. Para esta implementacion se usaron 41 nodos con 60 arcos, y su utilizó una presentacion de una Lista de adyacencia para la presentacion de las conexiones y los nodos, de la misma manera se implementaron 2 casos de txt cada uno con una direccion ya sea en el sentido de evolucionar un objeto o conseguir los complementos de algun objeto, para conseguir esto se usó un BFS una busqueda en anchura para conseguir todos los componentes.

## Especificaciones de uso

En el respositorio presentado se encuentran todos los archivos necesarios para correr el programa los cuales son:
* main.cpp
* item.h
* tienda.h
* ConexionesAscendentes.txt
* ConexionesDescendentes.txt
* ObjetosActualizados.txt
* ObjetosActualizadosGuia.txt
Para un uso mucho mas practico y eficaz es recomendable contar con los 4 archivos en una sola carpeta a la hora de copilar todos los archivos.

Para este caso el txt *ObjetosActualizadosGuia*, muestra la separacion y organizacion de los nuevos objetos para esta entrega en conjunto con las clases y numeros de estos. Para un mejor entendimiento.

El programa cuenta con multiples menus con los que se facilita el uso y manejo del programa.

## Casos de Prueba / Funcionalidad del Programa

Al igual que en entregas anteriores tenemos dentro del programa una seccion de casos de prueba para poder revisar el correcto funcionamiento del programa y con esto checar de manera eficiente si el programa esta en correcto funcionamiento o no.

## Análisis de Complejidad
### Funciones Principales

### Metodo cargarLista()
Esta función presenta una complejidad lineal de O(n) ya que depende completamente de la cantidad de objetos que se inserten en el txt, mientras mas objetos se inserten mas pasos realizará la función.

### Metodo MostrarLista()
Al igual que la función anterior esta función es O(n) ya que imprime completamente o parcialmente todos los objetos que se encuentran en el arreglo de objetos.

### Metodo LoadGraphList()
Esta función lo que realiza es iniciar el vector de la lista de adyacencia y llenarlo con las conexiones de todos los nodos, esta función se ve aafectada directamente por el numero de arcos que tiene el txt donde se encuentran las conexiones por lo tanto este presenta una complejidad de O(n) donde n son los numeros de arcos del grafo.

### Metodo printAdjList()
Esta función imprime todos los nodos existentes en el grafo en conjunto con todos los arcos que estos contienen por lo que la función se ve anidada en 2 for el primero haciendo relacion con la cantidad de nodos y el segundo haciendo referencia a los nodos con los cuales esta conectado. Dando una complejidad de O(n) haciendo referencia a la cantidad de nodos y O(a) haciendo referencia a los arcos totales con los que cuenta el grafo. Dando una complejidad de O(n+a) donde los nodos y los arcos se suman, pero haciendo analisis asintotico y redondeando nos da una complejidad media de O(n).

### Metodo BFS()
Esta función de la misma manera recorre todos los nodos y todas sus conexiones para conseguir 

