/*
* Proyecto Integrador Conceptos Basicos y Algoritmos Fundamentales
* Autor: Jesus David Talamantes Morales
* Matricula: A01706335
* Fecha de Creacion: 20/09/2020 Actualizado: 01/11/2020
* Esta clase es la encargada de definir los objetos del MOBA League of Legends
* por medio de sus atributos como los son vida,mana,costo,nombre,etc.
*/

#ifndef ITEM_H_
#define ITEM_H_

#include <iostream>

using namespace std;

class Item {

  private:
    string nombreItem;
    int costo,poderA,vida,mana,redEn,resM,arma;
    /* Atributos
    *  C: Costo, PA: Poder de Habilidad, V: Vida, M: Mana
    *  RE: Reduccion de Enfriamiento, RM: Resistencia Magica
    *  AR: Armadura
    */
  public:
    //Constructor
    Item(string,int,int,int,int,int,int,int);
    //Getters
    string get_nomIt() {return nombreItem;}
    int get_cost() {return costo;}
    int get_pa() {return poderA;}
    int get_vid() {return vida;}
    int get_man() {return mana;}
    int get_RE() {return redEn;}
    int get_RM() {return resM;}
    int get_AR() {return arma;}
    //Metodo
    void mostrarItem();

};
//Constructor principal de la clase
Item::Item(string nomI,int cost,int pod,int vid,int man,int red,int res,int arm){
  nombreItem = nomI; costo = cost; poderA = pod; vida = vid; mana = man;
  redEn = red; resM = res; arma = arm;
}

/*Metodo mostrarItem()
 *
 * Esta funcion muestra en pantalla todos los atributos de algun objeto
 * seleccionado excluyendo aquellos que no tengan valor (0).
 */
void Item::mostrarItem(){
  cout<<"\t\t"<<nombreItem<<endl;
  cout<<"\t\t\t"<<costo<<endl<<endl;
  cout<<"\tPoder de Habilidad: "<<poderA<<endl;
  //condicionales para evitar mostrar valores en 0
  if(vida != 0){
    cout<<"\tVida: "<<vida<<endl;
  }
  if(mana != 0){
    cout<<"\tMana: "<<mana<<endl;
  }
  if(redEn != 0){
    cout<<"\tReduccion de Enfriamiento: "<<redEn<<endl;
  }
  if(resM != 0){
    cout<<"\tResistencia Magica: "<<resM<<endl;
  }
  if(arma != 0){
    cout<<"\tArmadura: "<<arma<<endl;
  }
  cout<<endl;
}

#endif // ITEM_H_
