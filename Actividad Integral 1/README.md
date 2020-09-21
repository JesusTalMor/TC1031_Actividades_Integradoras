# Actividad Integradora 1 Conceptos Básicos y Algoritmos Fundamentales

## Tienda de objetos de League of Legends

El programa aqui presentado es en su mayoría un pequeño prototipo con el cual se puede observar un catalogo de objetos del juego MOBA de league of legends desarrollado por la empresa Riot Games. Dentro de este catalo de 30 objetos los cuales pertenecen a la clase de "Magos" ya que utilizan poder de habilidad o magia, dentro de los cuales se puede consultar el nombre de cada objeto, el costo del mismo, y las estadisticas que aporta como los son: vida, mana, poder de habilidad, resistencia magica, armadura etc.

Dentro del programa se podran realizar 4 opciones. La primera se basa en visualizar el conjunto de objetos de manera desordenada, tomados del archivo txt de "Objetos.txt", La segunda opcion consiste en ordenar el catalogo de objetos basandose en algun atributo de los mismos, ya sea nombre, costo o alguna otra estadistica, La tercera opción consiste en una busqueda rapida por medio de atributos para encontrar los objetos que contegan el atributo deseado, excluyendo todo aquel objeto que no cuente con este atributo. Por ultimo se encuentra la cuarta opcion que consiste en tomar el conjunto de objetos con los que se ha estado trabajando y guardarlos en un archivo txt.

## Especificaciones de uso

En el respositorio presentado se encuentran todos los archivos necesarios para correr el programa los cuales son:
* main.cpp
* item.h
* tienda.h
* Objetos.txt
Para un uso mucho mas practico y eficaz es recomendable contar con los 4 archivos en una sola carpeta a la hora de copilar todos los archivos.

El programa cuenta con multiples menus con los que se facilita el uso y manejo del programa.

## Casos de Prueba / Funcionalidad del Programa

***1. Mostrar Objetos Originales sin Ordenar*** Para este proceso es necesario que en el menú principal de opciones se seleccione la opción número 1, la cual despliegará con un formato la lista de objetos en su orden original sin excluir ningun objeto.

***2. Ordenar lista con respecto al atributo nombre*** Para realizar este caso de prueba es necesario que en el menu principal seleccione la opción número 2 para pasar a un menú secundario donde se despliegará las posibles opciones de ordenarmiento con atributos, para este caso de prueba seleccione la opcion 1, si el funcionamiento es correcto del programa el ultimo objeto que debe de presentar debe ser el objeto ***Velo de la Banshee***.

***3. Busqueda de objetos por el atributo de reducción de enfriamiento*** Para este caso de prueba es necesario en el menu principal seleccionar la tercera opcion que desplegará un menu secundario donde se encontrarán los atributos que se pueden filtrar de los objetos, dentro de este menú seleccione la opción 3, si el procedimiento es correcto, en pantalla se desplegarán solo objetos que cuenten con el atributo de reducción de enfriamiento.

***4. Ordenamiento y posterior guardado de un conjunto*** Para este ultimo caso prueba es necesario primero modificar el conjunto de objetos seleccione en el menu principal la opción número 2, seguidamente seleccione cualquiera de los atributos con los que quiera acomodar los objetos (Le recomiendo usar el criterio de costo), una vez realizado la modificación salga del menú secundario pulsando el número 9 y posteriormente pulse la opción número 4 para guardar el conjunto de objetos ya ordenados. Por último revise en la carpeta donde estan alojados los archivos para este programa, si el funcionamiento es correcto deberia de encontrar en el un nuevo archivo txt con el nombre de ListaGuarda.txt (Flexibilidad para el nombre en posteriores avances).

## Análisis de Complejidad
### Ordenamientos

Dentro del programa se utilizaron 2 metodos de ordenamiento para el acomodo de los objetos los cuales fueron:
* Burbuja
* Selección

#### Metodo burbuja para ordenar arreglos (bubbleSort)

Esta función presenta una complejidad cuadra de O(n^2), esto es debido a que su funcionamiento se basa en 2 ciclos for anidados los cuales van recorriendo todo el arreglo que para este caso es un arreglo de objetos, mediante el cual se toma el maximo valor que se encuentre en el arreglo ya sea de cualquier atributo, y este se coloca hasta la parte maxima del arreglo, posteriormente esta casilla queda bloqueada del ciclo anidado de for ya que ese espacio ya se ha acomodado dando un comportamiento en el cual el ciclo no siempre es n, pero ya que se esta tomando el peor de los casos su complejidad se mantiene en O(n^2). Viendo de forma matemática al tener a dos ciclos for con base a n (que en este caso son 30 objetos) tendriamos un aproximado de 900 pasos en el peor de los casos para acomodar todo el arreglo de objetos.

#### Metodo de seleccion para ordenar arreglos (SelectionSort)

Esta función presenta de igual forma presenta una complejidad de O(n^2), esto es debido que de la misma manera que el bubbleSort esta función cuenta con dos ciclos for anidados, en los cuales se tiene un comportamiento similar que el bubbleSort, pero en este caso se tiene un ciclo for recorriendo todo el arreglo en busca del menor valor el cual guarda o mantiene para posteriormente intercambiarlo con  la posicion que le corresponde por ejemplo para la posicion 0 del arreglo se tendria el valor mas pequeño de todo el arreglo dando como resultado que si dentro de esta posicion esta un numero de 350, un ciclo for recorrerá todo el arreglo en busca de un numero menor a todos y los remplazara en la posición 0. Es por lo mismo que en el caso anterior el hecho de que siempre se este recorriendo el arreglo por el ciclo for dentro del ciclo for que su complejidad se mantiene en O(n^2) en el peor de los casos.

#### Busqueda 

Para este caso solo se utilizo un metodo de busqueda que es la busqueda secuencial en el cual se recorre todo el arreglo en busqueda de algun aspecto, en este caso del programa se buscaban atributos dentro de los objetos y se imprimian aquellos objetos que contarán con estos atributos. Por lo mismo de que la función se basa en recorrer todo el arreglo en busqueda de algun aspecto o atributo es que este tiene una complejidad de O(n) ya que dependiendo de la cantidad de datos son los pasos que tardará en recorrer todo el arreglo hasta encontrarlo.
