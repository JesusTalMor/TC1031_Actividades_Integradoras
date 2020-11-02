/*
* Proyecto Integrador Conceptos Basicos y Algoritmos Fundamentales
* Autor: Jesus David Talamantes Morales
* Matricula: A01706335
* Fecha de Creacion: 20/09/2020 Actualizado: 01/11/2020
* Este .h se dedica a la creacion de un arbol heap minimo con objetos de la Clase
* item, lo cual resulta en una lista con aputadores los cuales apuntan
* a objetos de tipo item para el manejo de estos.
*/

#ifndef TIENDA_H_
#define TIENDA_H_

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

#include"item.h" //Biblioteca con objetos de item

using namespace std;

class Tienda {
private:
  //Atributos para arbol heap
  Item *objeto[100];
  unsigned int count;
  unsigned int dad(unsigned int) const;
  unsigned int left(unsigned int) const;
  unsigned int right(unsigned int) const;
  void heapify_nombre(unsigned int); //Funcion para el acomodo del arreglo por nombre
  void heapify_costo(unsigned int); //Funcion para el acomodo del arreglo por costo
  void swap(unsigned int, unsigned int); //Swap común.

public:
  //Constructor principal
  Tienda();

  //Funciones principales
  void cargarLista(int);
  void mostrarLista(int);
  void guardarLista();

  //Funciones auxiliares de arbol heap
  void push_nombre(Item*);  //Añadir nuevo item con nombre
  void pop_nombre(); //Quitar elemento menor con nombre
  void push_costo(Item*);  //Añadir nuevo item con costo
  void pop_costo(); //Quitar elemento menor con costo
};

/*Constructor desarrollado*/
Tienda::Tienda() {
   count = 0;
 }

/*dad obtiene la posicion del padre de algun objeto en el arreglo*/
unsigned int Tienda::dad(unsigned int pos) const{
  return (pos -1) / 2;
}

/*left obtiene la posicion del hijo izquierdo de algun objeto*/
unsigned int Tienda::left(unsigned int pos) const{
  return ((2 * pos) + 1);
}

/*right: obtiene la posicion del hijo derecho de algun objeto*/
unsigned int Tienda::right(unsigned int pos) const{
  return ((2 * pos) + 2);
}

/*Swap()
 *
 * Permite el intercambio de posicion de 2 objetos
 */
void Tienda::swap(unsigned int i, unsigned int j) {
  Item *aux = objeto[i];
  objeto[i] = objeto[j];
  objeto[j] = aux;
}

/* heapify_nombre()
 *
 * Parte de la estrucutura del arbol heap, este metodo se encarga de acomodar
 * el arbol de menor a mayor usando el atributo nombre como atributo clave
 */
void Tienda::heapify_nombre(unsigned int pos) {
  unsigned int le = left(pos);
	unsigned int ri = right(pos);
	unsigned int min = pos;
	if (le <= count && objeto[le]->get_nomIt().substr(0,1) < objeto[min]->get_nomIt().substr(0,1)) {
		min = le;
	}
	if (ri <= count && objeto[ri]->get_nomIt().substr(0,1) < objeto[min]->get_nomIt().substr(0,1)) {
		min = ri;
	}
	if (min != pos) {
		swap(pos, min);
		heapify_nombre(min);
	}
}

/* heapify_nombre()
 *
 * Parte de la estrucutura del arbol heap, este metodo se encarga de acomodar
 * el arbol de menor a mayor usando el atributo costo como atributo clave
 */
void Tienda::heapify_costo(unsigned int pos) {
  unsigned int le = left(pos);
	unsigned int ri = right(pos);
	unsigned int min = pos;
	if (le <= count && objeto[le]->get_cost() < objeto[min]->get_cost()) {
		min = le;
	}
	if (ri <= count && objeto[ri]->get_cost() < objeto[min]->get_cost()) {
		min = ri;
	}
	if (min != pos) {
		swap(pos, min);
		heapify_costo(min);
	}
}

/* push_nombre()
 *
 * Parte de la estrucutura del arbol heap, este metodo se encarga de insertar
 * un objeto manteniendo la estructura de menor a mayor usando el atributo
 * nombre como atributo clave para las comparaciones
 */
void Tienda::push_nombre(Item *val) {
  unsigned int pos;

  pos = count;
  count++;
  while (pos > 0 && val->get_nomIt().substr(0,1) < objeto[dad(pos)]->get_nomIt().substr(0,1)) {
    objeto[pos] = objeto[dad(pos)];
    pos = dad(pos);
  }
  objeto[pos] = val;
}

/* push_costo()
 *
 * Parte de la estrucutura del arbol heap, este metodo se encarga de insertar
 * un objeto manteniendo la estructura de menor a mayor usando el atributo
 * costo como atributo clave para las comparaciones
 */
void Tienda::push_costo(Item *val) {
  unsigned int pos;

  pos = count;
  count++;
  while (pos > 0 && val->get_cost() < objeto[dad(pos)]->get_cost()) {
    objeto[pos] = objeto[dad(pos)];
    pos = dad(pos);
  }
  objeto[pos] = val;
}

/* pop_nombre()
 *
 * Parte de la estrucutura del arbol heap, este metodo se encarga de sacar el
 * elemento en la parte superior del arbol, sacando el objeto a su vez mostrando
 * los datos del mismo y realizando una operacion heapify() con respecto al
 * atributo clave
 */
void Tienda::pop_nombre() {
  objeto[0]->mostrarItem();
  objeto[0] = objeto[--count]; //Ultimo dato agregado
  heapify_nombre(0);
}

/* pop_nombre()
 *
 * Parte de la estrucutura del arbol heap, este metodo se encarga de sacar el
 * elemento en la parte superior del arbol, sacando el objeto a su vez mostrando
 * los datos del mismo y realizando una operacion heapify() con respecto al
 * atributo clave
 */
void Tienda::pop_costo() {
  objeto[0]->mostrarItem();
  objeto[0] = objeto[--count]; //Ultimo dato agregado
  heapify_costo(0);
}

/*Metodo cargarLista()
 *
 * Usando el metodo auxiliar push() y dependiendo de la opcion del usuario
 * genera los objetos tomando los datos del txt y los inserta en el arreglo
 * usando el metodo push
 */
void Tienda::cargarLista(int opcion){
  ifstream miarchivo("Objetos.txt"); //Archivo a leer
  //Chequeo para evitar que el archivo este corrompido
  if(!miarchivo.is_open()){
    cout<<"Error al abrir el Archivo"<<endl;
  }

  string line;
  //Lectura del archivo por medio de un ciclo while que lee las lineas
  while(getline(miarchivo, line)){

    //Definición de variables y posterior modificacion
    string nombreItem = "";
    string tempcost = "";
    string temppoder = "";
    string tempvida = "";
    string tempmana = "";
    string tempred = "";
    string tempres = "";
    string temparma = "";

    int costo = 0, poderA = 0, vida = 0, mana = 0, redEn = 0, resM = 0, arma = 0;

    //Modificacion de varibles por medio de la funcion getline.
    stringstream ss(line);
    getline(ss,nombreItem,',');
    getline(ss,tempcost,',');
    costo = stoi(tempcost);
    getline(ss,temppoder,',');
    poderA = stoi(temppoder);
    getline(ss,tempvida,',');
    vida = stoi(tempvida);
    getline(ss,tempmana,',');
    mana = stoi(tempmana);
    getline(ss,tempred,',');
    redEn = stoi(tempred);
    getline(ss,tempres,',');
    resM = stoi(tempres);
    getline(ss,temparma,',');
    arma = stoi(temparma);

    //Creando objeto tipo item con el constructor del mismo
    Item *a = new Item(nombreItem,costo,poderA,vida,mana,redEn,resM,arma);

    //Usando funciones tipo push para crear el arbol heap
    if(opcion == 1) {
      push_nombre(a);
    }
    else if(opcion == 2){
      push_costo(a);
    }
  }

  miarchivo.close(); //Cerrando el archivo para evitar que se corrompa

}

/*Metodo mostrarLista()
 *
 * Usando el metodo auxiliar pop() se muestra el arreglo de objetos dependiendo
 * del atributo que se quiera arreglar primero
 */
void Tienda::mostrarLista(int opcion){
  cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<"\tMostrando Lista de Objetos Magicos"<<endl;
  cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  while(count != 0){
    if(opcion == 1){
      pop_nombre();
    }
    else if(opcion == 2){
      pop_costo();
    }
    cout<<"\t--------------------------------"<<endl;
  }
}

/*Metodo guardarLista()
 *
 * Este metodo su principal funcion es guardar el arreglo de objetos que se
 * usó en la sesión tomando toda la lista y guardandola en un nuevo archivo,
 * txt o rescribiendolo
 */
void Tienda::guardarLista(){
  ofstream archivo;

  archivo.open("ListaGuardada.txt"); //Reescribiendo o creando archivo
  for(int i = 0; i<count; i++){
    archivo<<objeto[i]->get_nomIt()<<","<<objeto[i]->get_cost()<<","<<
    objeto[i]->get_pa()<<","<<objeto[i]->get_vid()<<","<<objeto[i]->get_man()<<
    ","<<objeto[i]->get_RE()<<","<<objeto[i]->get_RM()<<","<<
    objeto[i]->get_AR()<<endl;
  }
  archivo.close(); //Cerrando archivo para evitar corrupción
}
#endif // TIENDA_H_
