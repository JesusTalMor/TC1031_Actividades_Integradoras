# Actividad Integradora 6 Integrando Nueva Estructura B Tree

## Sobre la Estuctura B Tree

El B-Tree forma parte de la familia de los arboles de busqueda que se autobalancean como lo es el caso de (AVL y el Arbol Rojo-Negro) en los cuales todos se maneja en la memoria principal del ordenador. La importancia del B Tree radica en el caso de que una gran cantidad de datos no logren entrar en la memoria principal. Aqui es donde el B Tree entra en acción ya que cuando tenemos un concentración alta de llaves o datos en el arbol, la información es dividida en bloques de memoria del disco. Donde tiempo de acceso al disco es muy alto a comparacion con el tiempo de acceso a la memoria principal. 
El mayor potencial de usar un B Tree radica en disminuir la cantidad de accesos a la memoria del disco.
La mayoria de las operaciones del B Tree (*search,insert,delete*) requiere O(h) numero de accesos al disco donde h es la profundida del B Tree.
Para controlar la profundidad del B Tree es necesario agregar un numero maximo de llaves o valores posibles en cada nodo del B Tree. 

### Caracteristicas de la Estructura B Tree

1. Todas las hojas se encuentran a la misma profundidad
2. Un B-Tree es definido por una grado minimo de llaves 't' en el codigo. Donde el valor del bloque de informacion en el disco depende directamente de esta variable.
3. Cada nodo exceptuando el nodo raiz debe tener por lo menos un "Techo" ([t-1]/2) llaves o valores. La raiz puede contener minimo una llave o un valor.
4. Todos los nodos incluyendo la raíz deben seguira la regla de tener t-1 llaves o valores.
5. Para definir la cantidad de hijos de un nodo esta se da por la cantidad de llaves o valores con las que cuenta el nodo +1 [n+1]. Donde n significa la cantidad de llaves o valores del nodo
6.Todas las llaves son insertadas y ordenadas en orden ascendente en donde el caso de que se tenga en un nodo los valores "10 15". Los hijos de ese nodo podran ser: valores menores a 10, valores mayores a 15 o valores intermedios mayores a 10 pero menores a 15.
7. A diferencia de los Arboles de busqueda binaria ("Binary Search Tree") el B-Tree crece y se encoje en profundidad con base en la raiz. Comparado con el arbol BST que crece desde sus nodos hojas y tambien se encoje desde sus nodos hojas.
8. Al igual que todos los demas arboles binarios de busqueda los tiempo promedios para insertar o borrar elementos son de O(log n).

### Caracteristicas de la Estructura B Tree

Una de las mayores aplicaciones de los B Tree son para la implementación de bases de datos o la creacion de busquedas por indices, ya que en el caso de la busqueda por indices, al irlo insertando en el B-Tree este empezara a generar la estructura hacia arriba de todos los indices que se coloquen dando al final una jerarquia organizada por el B-Tree, dando al final una lista de indices con niveles de importancia.

### Diferenciacion con B-Tree y B+ Tree
El principal cambio que se presenta en el B+ Tree a diferencia del B Tree es la estructura de los nodos hojas ya que a diferencia de El B-Tree donde los nodos hoja simplemente contienden las llaves de la menor jerarquia en el B+ Tree los nodos hojas contienen en si todas las llaves contenidas en el arbol ya que se van creando copias de las llaves de jerarquia mayor en los nodos hoja, y al finalizar la inserción de B+ Tree tendras como resultado en los nodos hoja, todas la llaves del arbol conectadas entre si como un lista ligada.

## Especificaciones de uso

En el respositorio presentado se encuentran todos los archivos necesarios para correr el programa los cuales son:
* main.cpp
* Btree.h
Para un uso mucho mas practico y eficaz es recomendable contar con los 4 archivos en una sola carpeta a la hora de copilar todos los archivos.

El programa cuenta con multiples menus con los que se facilita el uso y manejo del programa.

## Casos de Prueba / Funcionalidad del Programa

Los casos de prueba ahora fueron implementados como prueba y error donde en este caso al mostrar los casos de prueba se mostrara una lista de operaciones con su respectivo success o fail en el caso de que funcione o no. Para la sección de busqueda se cambio este aspecto a la palabra encontrado o no encontrado, para los casos de prueba los primero 4 casos de busqueda devuelven Encontrado y los siguientes casos de busqueda devuelven No Encontrado.

## Análisis de Complejidad
### Funciones Principales

### Metodo insert()
La funcion de Insert() al igual que en otros casos de BST balanceados como en el AVL cumple con una complejidad de O(log n).
Esta función cuenta con 2 funciones auxiliares para trabajar las cuales son splitChild() en el caso que un nodo supere la cantidad permitida de llaves y insertNonFull() donde la función se usa para insertar una nueva llave en un nodo que no supere su cantidad maxima de llaves.
insertNonFull() esta función lo que hace recorrer todo el arbol de manera binaria descartando pedazos grandes del arbol hasta llegar al nodo objetivo donde se quiere insertar la nueva llave, aqui se presentan 2 el primero en el que el nodo es una hoja y el segundo en donde el nodo no es una hoja, en esto se basa esta función recursiva para seguir avanzando ya que tiene que llega a un nodo hoja e insertar la llave en el nodo o separar el nodo con splitChild() en el caso de que el nodo este lleno, en cualquier caso se va dividiendo el arbol en 2 cada que se hace un movimiento dando una complejidad progresiva de O(n/2)
splitChild() esta es la función encargada de el control de profundidad del B Tree tambien es la encgargada de hacer que este crezca en profundidad. Lo que hace esta función es que recibe una poscision dentro de un nodo para sacar la llave intermedia y subirla un nivel y dividir ese unico nodo en 2 nuevos nodos. Dando una complejidad dada por "t" la cantidad maxima de llaves en un nodo y "n" la cantidad de llaves actuales en un nodo. 

### Metodo remove()
Esta función presenta un complejidad de O(log n) ya que es una busqueda por algun valor presentando la misma complejidad que search y borrando en un paso la llave que se desea eliminar. Ya posterior a eso se realizan cambios usando las funciones auxiliares de remove.

### Metodo traverse()
Esta función presenta una complejidad de O(n) donde n es la cantidad total de llaves presentadas en el arbol, ya que tiene que recorrer todo el arbol en forma similar a la función recursiva inorder() presentada en los BST.

### Metodo search()
Funciona de la misma manera que cualquier otro search en un Arbol Binario de Busqueda. Presenta una complejidad de O(log n) ya que va dividiendo en cada paso el arbol por la mitad eliminando de esta manera un gran cantidad de datos hasta llegar a la posicion donde deberia estar el dato que busca.

## Referencias y fuentes consultadas
https://www.geeksforgeeks.org/introduction-of-b-tree-2/
https://www.geeksforgeeks.org/insert-operation-in-b-tree/
https://www.geeksforgeeks.org/delete-operation-in-b-tree/
https://www.youtube.com/watch?v=aZjYr87r1b8&list=WL&index=13&t=666s
https://www.youtube.com/watch?v=c7hXEFs69Jw&feature=youtu.be

