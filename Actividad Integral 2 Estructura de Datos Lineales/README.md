# Actividad Integradora 2 Estructura de Datos Lineales

## Tienda de objetos de League of Legends

El programa aqui presentado es en su mayoría un pequeño prototipo con el cual se puede observar un catalogo de objetos del juego MOBA de league of legends desarrollado por la empresa Riot Games. Dentro de este catalo de 30 objetos los cuales pertenecen a la clase de "Magos" ya que utilizan poder de habilidad o magia, dentro de los cuales se puede consultar el nombre de cada objeto, el costo del mismo, y las estadisticas que aporta como los son: vida, mana, poder de habilidad, resistencia magica, armadura etc.

Dentro del programa se podran realizar 4 opciones. La primera se basa en visualizar el conjunto de objetos de manera original, tomados del archivo txt de "Objetos.txt", La segunda opcion consiste en la realización de una busqueda de los objetos con alguna caractersitica especifica, ya sea que propocionen vida, mana o algun otro atributo, La tercera opción consiste en guarda el conjunto de objeto de la lista ligada a un archivo txt generado automaticamente. Por ultimo se encuentra la cuarta opcion la cual despliega casos de prueba para revisar el correcto funcionamiento del programa.

## Especificaciones de uso

En el respositorio presentado se encuentran todos los archivos necesarios para correr el programa los cuales son:
* main.cpp
* item.h
* tienda.h
* Objetos.txt
Para un uso mucho mas practico y eficaz es recomendable contar con los 4 archivos en una sola carpeta a la hora de copilar todos los archivos.

El programa cuenta con multiples menus con los que se facilita el uso y manejo del programa.

## Casos de Prueba / Funcionalidad del Programa

Para la esta entrega se generó dentro de la interfaz virtual de opciones una opción para mostrar casos de prueba predeterminados con los cuales se puede revisar si el programa esta funcionando correctamente.

## Análisis de Complejidad
### Funciones Principales

Dentro de esta nueva interación del programa se utilizaron listas ligadas en la cuales se tiene 4 funciones principales que puede realizar el programa las cuales son: 
* cargarLista() que se encarga de leer el archivo txt y crear la lista ligada en si.
* mostrarLista() muestra por completo todos los objetos sin ningun filtro de atributo.
* buscarLista(int) la cual muestra solo objetos que cumplan con los atributos que se buscan.
* guardarLista() la cual toma la lista ligada y guarda todos los objetos en un archivo txt nuevo.

### Metodo cargarLista()

Esta funcion o metodo presenta una complejidad algo interesante ya que se ayuda de otras funciones auxiliares en el programa las cuales son: addfirst(), add() y vacio() en la cuales se realizan operaciones para añadir poco a poco los objetos a la lista ligada analizando cada una por separado, tenemos que la complejidad de addFirst y vacio es O(1), ya que es un caso especifico en el cual el arreglo de objetos esta completamente vacio, dando un insert de un objeto en solo un paso, para el segundo caso que es el caso general en el cual se recorre todo el arreglo de apuntadores hasta llegar al ultimo donde se inserta el ultimo objeto dando una complejidad lineal de O(n), tomando todo esto en cuenta al ser la función una lectura del archivo txt que se basa en leer una linea y encontrar información y en base en eso utiliza la función add(). En conclusion ya que la lectura del archivo se realiza de manera constante en 1 paso y considerando que la función add() tiene una complejidad de O(n) llegamos a la conclusion en la cual la complejidad total de cargarLista() es de O(n).

### Metodo MostrarLista()

Esta función presenta una complejidad de O(n), ya que solo se basa en recorrer todo el arreglo de objetos e ir imprimiendo todos los objetos presentando de manera constante una complejidad de O(n).

### BuscarLista()

Esta función tiene una complejidad de O(n) porque al igual que la función anterior esta tiene que recorrer todo el arreglo en busca de objetos con los atributos seleccionados dando como resultado que en el peor de los casos se recorra todo el arreglo en busca de los objetos.

### GuardarLista

Esta función lo que realiza es que recorre todo el arreglo de objetos y va consiguiendo de estos toda la información que posteriormente guarda en el archivo txt en un solo paso, dando una complejidad de O(n) hasta finalizar todo el arreglo de objetos.
