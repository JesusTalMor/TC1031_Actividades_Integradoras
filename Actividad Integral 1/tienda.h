/*
* Proyecto Integrador Conceptos Basicos y Algoritmos Fundamentales
* Autor: Jesus David Talamantes Morales
* Matricula: A01706335
* Fecha de Creacion: 20/09/2020
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
    Item *itemMagico[100];
    int contador;
  public:
    //Constructor
    Tienda(): contador(0){};

    //Metodos principales
    void cargarLista();
    void mostrarLista();
    void guardarLista();
    void ordenSelecNombre();
    void ordenSelecCosto();
    void ordenSelecPoderA();
    void ordenSelecVida();
    void ordenBurbMana();
    void ordenBurbRE();
    void ordenBurbRM();
    void ordenBurbAR();
    void busqSeqAtri(int);
    //Metodos auxiliares
    void swap(int,int);
};
//Metodos auxiliares
void Tienda::swap(int i,int j){
  //Puede exisitir un error
  Item *aux[0];
  aux[0] = itemMagico[i];
  itemMagico[i] = itemMagico[j];
  itemMagico[j] = aux[0];

}
//Metodos principales
void Tienda::cargarLista(){
  ifstream miarchivo("Objetos.txt"); //Archivo a leer
  //Chequeo para evitar que el archivo este corrompido
  if(!miarchivo.is_open()){
    cout<<"Error al abrir el Archivo"<<endl;
  }

  string line;
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
    itemMagico[contador] = new Item(nombreItem,costo,poderA,vida,mana,redEn,resM,arma);
    //Objeto creado

    contador ++;
  }

  miarchivo.close(); //Cerrando el archivo para evitar que se corrompa

}
void Tienda::mostrarLista(){
  cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<"\tMostrando Lista de Objetos Magicos"<<endl;
  cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  for(int i = 0;i<contador;i++){
    itemMagico[i]->mostrarItem();
    cout<<"\t--------------------------------"<<endl;
  }
}
void Tienda::guardarLista(){
  ofstream archivo;
  archivo.open("ListaGuarda.txt"); //Reescribiendo o creando archivo
  for(int i=0;i<contador;i++){
    archivo<<itemMagico[i]->get_nomIt()<<","<<itemMagico[i]->get_cost()<<","<<
    itemMagico[i]->get_pa()<<","<<itemMagico[i]->get_vid()<<","<<itemMagico[i]->
    get_man()<<","<<itemMagico[i]->get_RE()<<","<<itemMagico[i]->get_RM()<<","<<
    itemMagico[i]->get_AR()<<endl;
  }
  archivo.close(); //Cerrando archivo para evitar corrupción
}
void Tienda::ordenSelecNombre(){
  int pos;

  for (int i = 0; i <= contador - 1; i ++){ //Contador para repara el arreglo
    pos = i;
    for(int j = i + 1; j <= contador - 1; j++){
      if(itemMagico[pos]->get_nomIt().substr(0,1) > itemMagico[j]->get_nomIt().substr(0,1)){
        pos = j;
      }
    }
      swap(i, pos);
  }
}

void Tienda::ordenSelecCosto(){
  int pos;

  for (int i = 0; i <= contador - 1; i ++){ //Contador para repara el arreglo
    pos = i;
    for(int j = i + 1; j <= contador - 1; j++){
      if(itemMagico[pos]->get_cost() > itemMagico[j]->get_cost()){
        pos = j;
      }
    }
      swap(i, pos);
  }
}

void Tienda::ordenSelecPoderA(){
  int pos;

  for (int i = 0; i <= contador - 1; i ++){ //Contador para repara el arreglo
    pos = i;
    for(int j = i + 1; j <= contador - 1; j++){
      if(itemMagico[pos]->get_pa() > itemMagico[j]->get_pa()){
        pos = j;
      }
    }
      swap(i, pos);
  }
}

void Tienda::ordenSelecVida(){
  int pos;

  for (int i = 0; i <= contador - 1; i ++){ //Contador para repara el arreglo
    pos = i;
    for(int j = i + 1; j <= contador - 1; j++){
      if(itemMagico[pos]->get_vid() > itemMagico[j]->get_vid()){
        pos = j;
      }
    }
      swap(i, pos);
  }
}

void Tienda::ordenBurbMana(){
  for(int i = contador - 1; i > 0; i--){
    for(int j = 0; j < i; j++){
      if(itemMagico[j]->get_man() > itemMagico[j + 1]->get_man()){
        swap(j, j + 1);
      }
    }
  }
}

void Tienda::ordenBurbRE(){
  for(int i = contador - 1; i > 0; i--){
    for(int j = 0; j < i; j++){
      if(itemMagico[j]->get_RE() > itemMagico[j + 1]->get_RE()){
        swap(j, j + 1);
      }
    }
  }
}

void Tienda::ordenBurbRM(){
  for(int i = contador - 1; i > 0; i--){
    for(int j = 0; j < i; j++){
      if(itemMagico[j]->get_RM() > itemMagico[j + 1]->get_RM()){
        swap(j, j + 1);
      }
    }
  }
}

void Tienda::ordenBurbAR(){
  for(int i = contador - 1; i > 0; i--){
    for(int j = 0; j < i; j++){
      if(itemMagico[j]->get_AR() > itemMagico[j + 1]->get_AR()){
        swap(j, j + 1);
      }
    }
  }
}

void Tienda::busqSeqAtri(int val){

  switch(val){
    case 1: {
      cout<<"\t+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
      cout<<"\tMostrando Resultados de Busqueda para Vida "<<endl;
      cout<<"\t+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
      for(int i=0;i<contador;i++){
        if(itemMagico[i]->get_vid() != 0){
          itemMagico[i]->mostrarItem();
        }
      }
      break;
    }
    case 2: {
      cout<<"\t+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
      cout<<"\tMostrando Resultados de Busqueda para Mana "<<endl;
      cout<<"\t+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
      for(int i=0;i<contador;i++){
        if(itemMagico[i]->get_man() != 0){
          itemMagico[i]->mostrarItem();
        }
      }
      break;
    }
    case 3:{
      cout<<"\t+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
      cout<<"\tMostrando Resultados de Busqueda para"<<endl;
      cout<<"\t                         Reduccion de Enfriamiento "<<endl;
      cout<<"\t+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
      for(int i=0;i<contador;i++){
        if(itemMagico[i]->get_RE() != 0){
          itemMagico[i]->mostrarItem();
        }
      }
      break;
    }
    case 4:{
      cout<<"\t+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
      cout<<"\tMostrando Resultados de Busqueda para"<<endl;
      cout<<"\t                                Resistencia Magica "<<endl;
      cout<<"\t+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
      for(int i=0;i<contador;i++){
        if(itemMagico[i]->get_RM() != 0){
          itemMagico[i]->mostrarItem();
        }
      }
      break;
    }
    case 5:{
      cout<<"\t+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
      cout<<"\tMostrando Resultados de Busqueda para Armadura"<<endl;
      cout<<"\t+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
      for(int i=0;i<contador;i++){
        if(itemMagico[i]->get_AR() != 0){
          itemMagico[i]->mostrarItem();
        }
      }
      break;
    }
  }
}

#endif // TIENDA_H_
