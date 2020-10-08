/*
* Proyecto Integrador Conceptos Basicos y Algoritmos Fundamentales
* Autor: Jesus David Talamantes Morales
* Matricula: A01706335
* Fecha de Creacion: 20/09/2020 Actualizado: 07/10/2020
* Este .h se dedica a la creacion de una lista ligada con objetos de la Clase
* item usando, lo cual resulta en una lista con aputadores los cuales apuntan
* a objetos de tipo item para la busqueda y manejo de estos.
*/

#ifndef TIENDA_H_
#define TIENDA_H_

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

#include"item.h" //Biblioteca con objetos de item

using namespace std;

class Tienda; //Se instancia para el uso de friend en la clase Nodo

class Nodo {
private:
  //Atributos
  Item objeto;
  Nodo *next;

  //Constructores
  Nodo(Item);
  Nodo(Item, Nodo*);

  friend class Tienda; //Se usa para que la clase Tienda pueda accder a la seccion
                       //privada de la clase Nodo
};

//Constructores dessarrollados
Nodo::Nodo(Item a) : objeto(a), next(0){}

Nodo::Nodo(Item a, Nodo* nxt) : objeto(a), next(nxt){}

class Tienda {
  private:
    //Atributos
    Nodo *head;
    int size;

  public:
    //Constructor
    Tienda();

    //Metodos principales
    void cargarLista();
    void mostrarLista();
    void buscarLista(int);
    void guardarLista();
    void guardarObjeto();

    //Metodos auxiliares de listas ligadas
    void addFirst(Item);
    bool vacio();
    void add(Item);

};

//Constructor desarrollado
Tienda::Tienda() : head(0), size(0){}

//Metodos con respecto a listas ligadas

/*Metodo vacio()
 *
 * Es un metodo auxiliar, su principal funcion es usarlo en conjunto con la
 * funcion addFirst() para revisar si la lista esta vacio por medio del uso
 * del apuntador head.
 */
bool Tienda::vacio(){
  return (head == 0);
}

/*Metodo addFirst()
 *
 * Esta fucion en es para iniciar el arreglo de objetos ligados, colocando el
 * primer objeto y conectandolo con el apuntador head.
 */
void Tienda::addFirst(Item a){
  Nodo *nodoN;
  nodoN = new Nodo(a);
  nodoN->next = head;
  head = nodoN;
  size ++;
}

/*Metodo add()
 *
 * Este metodo es el metodo general para añadir objetos a la lista ligada,
 * esta funcion utiliza las 2 funciones anteriormente instaciadas de addFirst
 * y vacio para determiinar donde agregar y ligar el objeto
 */
void Tienda::add(Item a){
  Nodo *nodoN, *aux;

  nodoN = new Nodo(a);
  if(vacio()){
    addFirst(a);
    return;
  }

  aux = head;
  while(aux->next != 0){
    aux = aux->next;
  }

  nodoN->next = 0;
  aux->next = nodoN;
  size++;
}

//Metodos principales

/*Metodo cargarLista()
 *
 * Esta funcion utiliza la funciones anteriores de add(), para primero sacar
 * del archivo .txt designado la informacion que coloca en objetos de tipo
 * item los cuales usando la funcion add que tiene como parametro un objeto
 * de tipo item va creando la lista ligada
*/
void Tienda::cargarLista(){
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
    Item a = Item(nombreItem,costo,poderA,vida,mana,redEn,resM,arma);

    //Usando funciones tipo add para crear la lista ligada
    add(a);
  }

  miarchivo.close(); //Cerrando el archivo para evitar que se corrompa

}

/*Metodo mostrarLista()
 *
 * Este metodo su principal funcion es mostrar el arreglo ligado de objetos
 * de manera general usando los apuntadores next y la funcion mostrarItem()
 * de la clase Item.
 */
void Tienda::mostrarLista(){
  cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<"\tMostrando Lista de Objetos Magicos"<<endl;
  cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  Nodo *aux;
  aux = head;
  while(aux != 0){
    aux->objeto.mostrarItem();
    aux = aux->next;
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
  Nodo *aux;

  archivo.open("ListaGuardada.txt"); //Reescribiendo o creando archivo
  aux = head;
  while(aux != 0){
    archivo<<aux->objeto.get_nomIt()<<","<<aux->objeto.get_cost()<<","<<
    aux->objeto.get_pa()<<","<<aux->objeto.get_vid()<<","<<aux->objeto.get_man()<<
    ","<<aux->objeto.get_RE()<<","<<aux->objeto.get_RM()<<","<<
    aux->objeto.get_AR()<<endl;
    aux = aux->next;
  }
  archivo.close(); //Cerrando archivo para evitar corrupción
}

/*Metodo buscarLista()
 *
 * Esta funcion lo que realiza son busquedas de objetos magicos por medio de
 * los atributos que se desee buscar dados en la función main los cuales por
 * medio de el int val modfican la busqueda que se hará
 */
void Tienda::buscarLista(int val){

  Nodo *aux;
  aux = head;
  switch(val){
    case 1: {
      cout<<"\t+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
      cout<<"\tMostrando Resultados de Busqueda para Vida "<<endl;
      cout<<"\t+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
      while(aux != 0){
        if(aux->objeto.get_vid() != 0){
          aux->objeto.mostrarItem();
        }
        aux = aux->next;
      }
      break;
    }
    case 2: {
      cout<<"\t+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
      cout<<"\tMostrando Resultados de Busqueda para Mana "<<endl;
      cout<<"\t+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
      while(aux != 0){
        if(aux->objeto.get_man() != 0){
          aux->objeto.mostrarItem();
        }
        aux = aux->next;
      }
      break;
    }
    case 3:{
      cout<<"\t+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
      cout<<"\tMostrando Resultados de Busqueda para"<<endl;
      cout<<"\t                         Reduccion de Enfriamiento "<<endl;
      cout<<"\t+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
      while(aux != 0){
        if(aux->objeto.get_RE() != 0){
          aux->objeto.mostrarItem();
        }
        aux = aux->next;
      }
      break;
    }
    case 4:{
      cout<<"\t+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
      cout<<"\tMostrando Resultados de Busqueda para"<<endl;
      cout<<"\t                                Resistencia Magica "<<endl;
      cout<<"\t+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
      while(aux != 0){
        if(aux->objeto.get_RM() != 0){
          aux->objeto.mostrarItem();
        }
        aux = aux->next;
      }
      break;
    }
    case 5:{
      cout<<"\t+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
      cout<<"\tMostrando Resultados de Busqueda para Armadura"<<endl;
      cout<<"\t+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
      while(aux != 0){
        if(aux->objeto.get_AR() != 0){
          aux->objeto.mostrarItem();
        }
        aux = aux->next;
      }
      break;
    }
  }
}

#endif // TIENDA_H_
