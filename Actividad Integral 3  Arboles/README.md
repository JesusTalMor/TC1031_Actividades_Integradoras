# Actividad Integradora 2 Estructura de Datos Lineales

## Tienda de objetos de League of Legends

El programa aqui presentado es en su mayoría un pequeño prototipo con el cual se puede observar un catalogo de objetos del juego MOBA de league of legends desarrollado por la empresa Riot Games. Dentro de este catalo de 30 objetos los cuales pertenecen a la clase de "Magos" ya que utilizan poder de habilidad o magia, dentro de los cuales se puede consultar el nombre de cada objeto, el costo del mismo, y las estadisticas que aporta como los son: vida, mana, poder de habilidad, resistencia magica, armadura etc.

Para esta tercera entrega se implemento una estructura de arbol minimo de heap, en  las cuales se tuvieron solo 3 funciones principales en el sistema, la primera se trata de la capacidad de cargar la lista de datos dependendiendo de la estrucutura que deseas que se muestre. Por ejemplo solo existen 2 casos para este primera opcion donde se quiere acomodar los objetos por nombre de manera alfabetica o si se quieren acomodar los datos por costo del item. Para la segunda opcion tenemos el mismo concepto pero ahora implementado para guardar la lista de objetos generada en un archivo txt a parte para guardarlos. Por ultimo tenemos la tercera función la cual despliega un pequeño menu que muestra casos de prueba para que el usuario pueda comparar si su programa esta funcionando de manera correcta.

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



### Metodo cargarLista()
En este metodo contamos con la ayuda de las siguiente funciones auxiliares, las cuales son los push para agregar a nuestro arreglo de objetos un nuevo objeto, usando 2 tipos de push dependiendo del atributo mediante el cual se quiera organizar el arbol heap. En terminos de complejdiad la primera sección que es la creacion del objeto y el alacenamiento de su informacion tiene una complejidad de O(1) ya que tarda solo un paso en almacenar la información pero por otro lado tenemos qube este proceso se repite para todos los objetos en el arreglo dadndo una complejidad de O(n), porsteriormente se utiliza la función auxiliar push() para insertar el objeto, lo cual hace que esta función realize comparaciones usando la función dad() para comparar a los hijos y los padres y en base en eso realizar swap() para poder mantener la estructura minima del arbol heap dando en este caso debido a que se va dividiendo el arbol por la mitad ya que solo se comparan los padres da una complejidad de O(log n) para esta parte, pero como se repite para todos los elementos, por lo tanto contamos con una complejidad final de O(nlog n).


### Metodo MostrarLista()
Para este metodo usamos la función pop() para la muestra en orden minimo de los objetos en el arbol por lo que se tiene que realizar un analisis a la parte de la función pop() la cual se comporta de la misma manera para ambos casos, en cuanto a complejidad la función pop tiene una complejidad de O(1) ya que directamente muestra el primer elemento del arreglo de objetos y posteriormente lo remplaza con el ultimo elemento agregado para posteriormente usar la función heapify() con este ultimo elemento para mantener la estructura del arbol heap. Ahora hablando de la complejidad de heapify() esta funciona de manera similar que push() ya que lo que se hace es realizar comparaciones entre padres e hijos y con esto se realizan swaps() para acomodar a los padres e hijos y mantener la estructura, dando de esta forma saltos que parten de manera constante el arbol en mitades dando una complejidad de O(log n), dando de manera final una complejidad para esta funcion mostrar lista para la primera parte O(1) cuando se realiza el pop y una complejidad de O(log n) cuando se realiza el heapify dando de manera promedio una complejidad de O(log n)



### Metodo GuardarLista()
Para esta ultima función la complejidad que presenta es una complejidad de O(n) ya que de manera sencilla, recorre todo el areglo de objetos tomando de ellos los datos en una complejidad de O(1), hasta llegar al ultimo objeto y con esto lo guarda en un archivo nuevo. Dando al final una complejidad de O(n) ya que tiene que recorrer todos los elementos para poder guardarlos en el archivo.
