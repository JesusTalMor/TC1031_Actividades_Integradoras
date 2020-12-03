/*
 * Actividad Integral 6 Una nueva Estrucutra
 * Author: Jesus Talamantes Morales
 * Codigo recopilado de:
 *        https://www.geeksforgeeks.org/introduction-of-b-tree-2/
 *        https://www.geeksforgeeks.org/insert-operation-in-b-tree/
 *        https://www.geeksforgeeks.org/delete-operation-in-b-tree/
 * Creado en: 02/12/2020
 */

//Implementacion C++ de metodos searh() y tranverse()
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>

using namespace std;

class BTree; //Definimos clase BTree

//////////////////////////Definiendo NodoBTree/////////////////////////////////

//Nodo de un BTree
class NodoBTree {
private:
  int *llaves;  // Arreglo de llaves
  int t;      // Grado minimo (define la cantidad de llaves)
  NodoBTree **C; //Arreglo de apuntadores a hijos
  int n;     // Numero de llaves actuales
  bool hoja; // Bandera para saber si es una hoja
public:
  NodoBTree(int tt, bool thoja);   // Constructor

  // Una funcion que recorre todos los nodos en un subarbol conectado a este nodo
  void traverse(stringstream &aux);

  //Funcion de busqueda de llave en el subarbol conectado a este nodo
  NodoBTree *search(int valor);   // Retorna NULL si no se encuentra la llave

  // Funcion que retorna el indice de la primera llave que sea mayor o igual al
  // valor a buscar
  int findKey(int valor);

  // Funcion de utilidad para insertar una nueva llave en un subarbol raiz con
  // este nodo. Esto se basa en que el nodo debe no estar lleno cuando esta
  // funcion se llame.
  void insertNonFull(int valor);

  // Funcion de utilidad para dividir el hijo de este nodo. i es un index de y
  // donde el arreglo de hijos C[]. El hijo debe estar lleno para llamar esta
  // funcion
  void splitChild(int i, NodoBTree *y);

  // Una funcion conjunto para remover una llave de un subarbol con este nodo
  void remove(int valor);

  // Funcion auxiliar para remover una llave en una posicion idx-th en el nodo
  // que es una hoja
  void removeFromLeaf(int idx);

  // Funcion para remover una llave presente en una posicion idx-th en el nodo
  // que no es una hoja
  void removeFromNonLeaf(int idx);

  // Una funcion para conseguir el predecessor de una llave donde la llave
  // es presente en una posicion idx-th en el nodo
  int getPred(int idx);

  // Una funcion para conseguir el succesor de la llave donde la llave esta
  // presente en la posicion idx-th en el nodo
  int getSucc(int idx);

  // Funcion para llenar el array del nodo hijo de la posicion idx-th en el
  // caso que el array C[] del hijo quede vacio de llaves.
  void fill(int idx);

  // Una Funcion que toma prestado la llave del nodo hijo C[idx-1]-th y lo
  // coloca en el nodo hijo C[idx]th
  void borrowFromPrev(int idx);

  // Una Funcion que toma prestado la llave del nodo hijo C[idx+1]-th y lo
  // coloca en el nodo hijo C[idx]th
  void borrowFromNext(int idx);

  // Una funcion para combinar el hijo del nodo en la posicion idx-th con el
  // nodo hijo de la posicion (idx+1)
  void merge(int idx);

friend class BTree;
//Se hace a la clase amiga para que utilize los atributos privados
};

////////////////////Realizando metodos de clase NodoBTree//////////////////////

//Constructor para la clase NodoBTree
NodoBTree::NodoBTree(int tt, bool thoja){
  // Guarda los valores del nodo constructor
  t = tt;
  hoja = thoja;

  // Reserva la memoria para el maximo numero de llaves
  // y de apuntadores hijos
  llaves = new int[2*t-1];
  C = new NodoBTree *[2*t];

  // Inicializa el numero de llaves como 0
  n = 0;
}

// Funcion para recorrer todos los nodos de un subarbol que tiene como raiz
// el nodo
void NodoBTree::traverse(stringstream &aux){
  //Hay un numero de n llaves y n+1 hijos, recorre a traves de las n llaves
  // y los primeros n hijos
  int i;
  for (i = 0; i < n; i++){
    // Si no es una hoja, entonces antes de imprimir llaves[i], recorre el
    // subarbol raiz con hijos C[i]
    if (hoja == false)
      C[i]->traverse(aux);
      aux << " " << llaves[i];
  }

  // Imprime el subarbol raiz con el ultimo hijo
  if (hoja == false)
    C[i]->traverse(aux);
}

// Funcion para buscar una llave k en un subarbol raiz con este nodo
NodoBTree *NodoBTree::search(int valor){
  //Encuentra la primera llave mayor o igual a k
  int i = 0;
  while (i < n && valor > llaves[i])
      i++;

  //Si el nodo acutal de llaves es igual al valor llave regresa este nodo
  if (llaves[i] == valor)
      return this;

  //Si la llave no es encontrada y el nodo es una hoja retornar NULL
  if (hoja == true)
      return NULL;

  //Avanza al siguiente hijo
  return C[i]->search(valor);
}

// Funcion que retorna el indice de la primera llave que sea mayor o igual al
// valor a buscar
int NodoBTree::findKey(int valor)
{
    int idx=0;
    while (idx<n && llaves[idx] < valor)
        ++idx;
    return idx;
}

// Funcion de utilidad para insertar una nueva llave en un subarbol raiz con
// este nodo. Esto se basa en que el nodo debe no estar lleno cuando esta
// funcion se llame.
void NodoBTree::insertNonFull(int valor)
{
  // Inicializa el indice al valor mas proximo a la derecha
  int i = n-1;

  // Si se trata de un nodo hoja
  if (hoja == true) {

    // El siguiente ciclo hace dos cosas
    // a) Encuentra la localizacion para insertar la nueva llave
    // b) Desplaza las llaves mayores al valor adelante
    while (i >= 0 && llaves[i] > valor) {
      llaves[i+1] = llaves[i];
      i--;
    }

    // Inserta la nueva llave a la localizacion
    llaves[i+1] = valor;
    n = n+1;
    }
    else { // Si no se trata de un nodo hoja

      // Encuentra al hijo donde se colocara la nueva llave
      while (i >= 0 && llaves[i] > valor)
        i--;

      // Revisar si el nodo hijo esta lleno
      if (C[i+1]->n == 2*t-1) {
        // Si se encuentra lleno, aplicar una separacion
        splitChild(i+1, C[i+1]);

        // Despues de la separacion, la llave intermedia de C[i]
        // sube un nivel y C[i] es dividido en 2.
        if (llaves[i+1] < valor)
          i++;
      }
      C[i+1]->insertNonFull(valor);
    }
}

// Funcion de utilidad para dividir el hijo de este nodo. i es un index de y
// donde el arreglo de hijos C[]. El hijo debe estar lleno para llamar esta
// funcion
void NodoBTree::splitChild(int i, NodoBTree *y)
{
  // Crea un nuevo nodo en el que guardaran (t-1) llaves de y
  NodoBTree *z = new NodoBTree(y->t, y->hoja);
  z->n = t - 1;

  //Copia el ultimo (t-1) llave de y en z
  for (int j = 0; j < t-1; j++)
      z->llaves[j] = y->llaves[j+t];

  //Copia el ultimo t hijo de y a z
  if (y->hoja == false) {
    for (int j = 0; j < t; j++)
        z->C[j] = y->C[j+t];
  }

  //Reduce el numero de llaves en y
  y->n = t - 1;

  // Ya que este nodo va a tener un hijo, se aparta el espacio en la memoria
  // para el hijo
  for (int j = n; j >= i+1; j--)
    C[j+1] = C[j];

  // Link del nuevo hijo al nodo
  C[i+1] = z;

  // Una llave de y se movera a este nodo. Encuentra la localizacion de la
  // nueva llave y mueve todas la llaves mayores un espacio a la derecha
  for (int j = n-1; j >= i; j--)
    llaves[j+1] = llaves[j];

  // Copia la llave intermedia de y a este nodo
  llaves[i] = y->llaves[t-1];

  // Incrementa el contador de llaves de este nodo
  n = n + 1;
}

// Una funcion conjunto para remover una llave de un subarbol con este nodo
void NodoBTree::remove(int valor) {
  int idx = findKey(valor);

  // La llave a remover esta presente en este nodo
  if (idx < n && llaves[idx] == valor) {

    // Si el nodo es una hoja - se aplica removeFromLeaf
    // en el caso contrario se aplica removeFromNonLeaf
    if (hoja)
      removeFromLeaf(idx);
    else
      removeFromNonLeaf(idx);
  }
  else  {

    // Si el nodo es una hoja, entonces la llave no esta presente en el arbol
    if (hoja) {
      cout << "La llave "<< valor <<" no existe dentro del arbol\n";
      return;
    }

    // Si la llave a remover esta presente en un subarbol raiz con este nodo
    // entonces la bandera indicara ya sea que la llave este presente en el
    // subarbol raiz con el ultimo hijo de este nodo
    bool bandera = ( (idx==n)? true : false );

    // Si el hijo donde debe estar la llave tiene menos que el grado minimo de
    // llaves entonces se rellena este hijo
    if (C[idx]->n < t)
      fill(idx);

    // Si el ultimo hijo fue fusionado, este debe ser combinado con el hijo
    // previo para hacer recursividad con (idx-1)th su hijo. De otro forma
    // solo se recursa (idx)th en el hijo que ahora tiene t llaves.
    if (bandera && idx > n)
      C[idx-1]->remove(valor);
    else
      C[idx]->remove(valor);
  }
  return;
}

// Funcion auxiliar para remover una llave en una posicion idx-th en el nodo
// que es una hoja
void NodoBTree::removeFromLeaf (int idx){

  // Mover todas las llaves posteriores al idx a la izquierda
  for (int i=idx+1; i<n; ++i)
    llaves[i-1] = llaves[i];

  //Reduce la cuenta de llaves
  n--;

  return;
}

// Funcion para remover una llave presente en una posicion idx-th en el nodo
// que no es una hoja
void NodoBTree::removeFromNonLeaf(int idx)
{

    int valor = llaves[idx];

    // Si el hijo que precede valor (C[idx]) tiene almenos t llaves, encontrar
    // al predecessor 'pred' del valor en el subarbol raiz en C[idx].
    // Remplazar valor por pred. De manera recursiva borrar pred en C[idx]
    if (C[idx]->n >= t)
    {
        int pred = getPred(idx);
        llaves[idx] = pred;
        C[idx]->remove(pred);
    }

    // Si el hijo en C[idx] tiene menos de t llaves, examinar C[idx+1].
    // Si C[idx+1] tiene almenos t llaves, encontrar al succesor 'succ' del
    // valor en el subarbol raiz de C[idx+1]. Remplazar valor por succ.
    // De manera recursiva borrar succ en C[idx+1]
    else if  (C[idx+1]->n >= t)
    {
        int succ = getSucc(idx);
        llaves[idx] = succ;
        C[idx+1]->remove(succ);
    }

    // Si ambos C[idx] y C[idx+1] tiene menos de las llaves minimas, fusionar
    // valor y todos los valores en C[idx+1] a C[idx].
    // Ahora C[idx] contiene 2t-1 llaves
    //Liberar C[idx+1] y de manera recursiva borrar el valor de C[idx]
    else
    {
        merge(idx);
        C[idx]->remove(valor);
    }
    return;
}

// Funcion para conseguir el predecessor de llaves[idx]
int NodoBTree::getPred(int idx){

  // Seguir avanzando a la derecha hasta topar con una nodo hoja
  NodoBTree *cur=C[idx];
  while (!cur->hoja)
    cur = cur->C[cur->n];

  // Retorna la ultima llave del nodo hoja
  return cur->llaves[cur->n-1];
}

// Funcion para conseguir el sucessor de llaves[idx]
int NodoBTree::getSucc(int idx){

  // Seguir avanzando desde [idx+1] a la izquierda hasta topar con un nodo hoja
  NodoBTree *cur = C[idx+1];
  while (!cur->hoja)
    cur = cur->C[0];

  // Retorna la primera llave del nodo hoja
  return cur->llaves[0];
}

// Funcion para llenar hijos de C[idx] que tienen menos de t-1 llaves
void NodoBTree::fill(int idx){

  // Si el hijo previo (C[idx-1]) tiene mas de t-1 llaves, tomar una llave
  // del hijo
  if (idx!=0 && C[idx-1]->n>=t)
    borrowFromPrev(idx);

  // Si el proximo hijo(C[idx+1]) tiene mas de t-1 llaves, tomar una llave
  // de ese hijo
  else if (idx!=n && C[idx+1]->n>=t)
    borrowFromNext(idx);

  // Fusionar C[idx] con su sobrino
  // Si C[idx] es el ultimo hijo, fusionarlo su sobrino previo
  // De otra forma fusionarlo con su proximo sobrino
  else {
    if (idx != n)
      merge(idx);
    else
      merge(idx-1);
  }
  return;
}

// Funcion que toma la llave de C[idx-1] y la inserta en C[idx]
void NodoBTree::borrowFromPrev(int idx){

  NodoBTree *hijo=C[idx];
  NodoBTree *sobrino=C[idx-1];

  // La ultima llave de C[idx-1] sube de nivel para ser el padre de llave[idx-1]
  // del padre es insertado como la primera llave de C[idx]. Por lo tanto
  // el primo pierde una llave y el hijo gana un llave

  // Moviendo todas las llaves de C[idx] un paso adelante
  for (int i=hijo->n-1; i>=0; --i)
    hijo->llaves[i+1] = hijo->llaves[i];

  // Si C[idx] no es una hoja, mover todos los apuntadores de hijos un paso adelante
  if (!hijo->hoja){
    for(int i=hijo->n; i>=0; --i)
      hijo->C[i+1] = hijo->C[i];
  }

  // Montando la primera llave del hijo igual a la llave de [idx-1] del nodo
  hijo->llaves[0] = llaves[idx-1];

  // Moviendo el ultimo hijo de sobrino como el primer hijo de C[idx]
  if(!hijo->hoja)
    hijo->C[0] = sobrino->C[sobrino->n];

  // Moviendo la llave de sobrino al padre
  // Esto reduce el numero de llaves de sobrino
  llaves[idx-1] = sobrino->llaves[sobrino->n-1];

  // Aumentando y Decreciendo el contador de la llave de C[idx] y C[idx+1]
  // respectivamente
  hijo->n += 1;
  sobrino->n -= 1;

  return;
}

// Funcion que toma la llave de C[idx+1] y lo coloca en C[idx]
void NodoBTree::borrowFromNext(int idx){

  NodoBTree *hijo=C[idx];
  NodoBTree *sobrino=C[idx+1];

  // llaves[idx] es insertada como la ultima llave de C[idx]
  hijo->llaves[(hijo->n)] = llaves[idx];

  // El primer hijo de sobrino es insertado en el ultimo hijo de C[idx]
  if (!(hijo->hoja))
    hijo->C[(hijo->n)+1] = sobrino->C[0];

  // La primera llave de sobrino es insertada a llaves[idx]
  llaves[idx] = sobrino->llaves[0];

  //Moviendo todas la llaves en sobrino un paso atras
  for (int i=1; i<sobrino->n; ++i)
    sobrino->llaves[i-1] = sobrino->llaves[i];

  // Moviendo todos los apuntadores a hijos un paso atras
  if (!sobrino->hoja){
    for(int i=1; i<=sobrino->n; ++i)
      sobrino->C[i-1] = sobrino->C[i];
  }

  // Aumentando y Decreciendo el contador de la llave de C[idx] y C[idx+1]
  // respectivamente
  hijo->n += 1;
  sobrino->n -= 1;

  return;
}

// Una funcion para combinar el hijo del nodo en la posicion idx-th con el
// nodo hijo de la posicion (idx+1)
void NodoBTree::merge(int idx) {
  NodoBTree *hijo = C[idx];
  NodoBTree *sobrino = C[idx+1];

  // Tomando la llave del nodo actual e insertandola a la posicion (t-1)th
  // de C[idx]
  hijo->llaves[t-1] = llaves[idx];

  // Copiando las llaves de C[idx+1] a C[idx] al final
  for (int i=0; i<sobrino->n; ++i)
    hijo->llaves[i+t] = sobrino->llaves[i];

  // Copiando apuntadores de hijo de C[idx+1] a C[idx]
  if (!hijo->hoja){
    for(int i=0; i<=sobrino->n; ++i)
      hijo->C[i+t] = sobrino->C[i];
  }

  // Moviendo todas la llaves despues de idx en el nodo actual un paso atras
  // para llenar el vacio creado por mover la llave[idx] a C[idx]
  for (int i=idx+1; i<n; ++i)
    llaves[i-1] = llaves[i];

  // Moviendo los apuntadores hijos despues (idx+1) en el nodo actual un paso
  // atras
  for (int i=idx+2; i<=n; ++i)
    C[i-1] = C[i];

  // Actualizando el contador de llave del hijo del nodo actual
  hijo->n += sobrino->n+1;
  n--;

  // Liberando memoria ocupada por sobrino
  delete(sobrino);
  return;
}

////////////////////Definiendo clase BTree/////////////////////////////////////

// Declaración de BTree
class BTree {
private:
  NodoBTree *raiz; // Apuntador a la raiz del arbol
  int t;  // Grado minimo de llaves
public:
  // Constructor (Inicializa con la raiz apuntando a nulo)
  BTree(int tt)
  {  raiz = NULL;  t = tt; }

  // Funcion para recorrer el arbol
  string traverse();

  // Funcion para buscar una llave en el arbol
  NodoBTree* search(int k)
  {  return (raiz == NULL)? NULL : raiz->search(k); }

  // Funcion principal para insertar una nueva llave en el BTree
  void insert(int valor);

  // Funcion principal para el borrado de un llave dentro del BTree
  void remove(int valor);
};

/////////////////////////Definiendo metodos de clase BTree/////////////////////

//Funcion para imprimir el arbol completo BTree
string BTree::traverse() {
  stringstream aux;
  aux << "[";

  if(raiz != NULL)
    raiz->traverse(aux);

  aux << "]";
  return aux.str();
}

// Funcion principal para insertar una nueva llave en el BTree
void BTree::insert(int valor) {
  // Si el arbol esta vacio
  if (raiz == NULL){
    // Reservar memoria para la raiz
    raiz = new NodoBTree(t, true);
    raiz->llaves[0] = valor;  // Inserta valor de la llave
    raiz->n = 1;  // Actualiza el valor de la cantidad de llaves
  }
  else { // Si el arbol no esta vacio
    // Si la raiz esta llena el arbol crece en profundidad
    if (raiz->n == 2*t-1) {
      // Reserva espacio de memoria para nueva raiz
      NodoBTree *secundario = new NodoBTree(t, false);
      // Hace que la vieja raiz pase a ser hijo de la nueva raiz
      secundario->C[0] = raiz;

      // Separa la vieja raiz y mueve 1 llave a la raiz
      secundario->splitChild(0, raiz);

      // Nueva raiz tiene 2 hijos ahora. Decision de cual de los 2 hijos
      // sera la nueva llave
      int i = 0;
      if (secundario->llaves[0] < valor)
        i++;

      secundario->C[i]->insertNonFull(valor);

      // Cambio a la raiz
      raiz = secundario;
    }
    else  // Si la raiz no esta llena llamar funcion insertNonFull()
    raiz->insertNonFull(valor);
  }
}

void BTree::remove(int valor) {
  if (!raiz) { // Verificar si el arbol esta vacio
    cout << "Arbol vacio\n";
    return;
  }
  // LLama la funcion principal de borrado
  raiz->remove(valor);
  // Si el nodo raiz tiene 0 llaves, definir a su hijo como la nueva raiz, de
  // otra forma definir el arbol vacio con Raiz == NULL
  if (raiz->n==0) {
    NodoBTree *tmp = raiz;
    if (raiz->hoja)
      raiz = NULL;
    else
      raiz = raiz->C[0];

    // Free the old root
    delete tmp;
  }
  return;
}
