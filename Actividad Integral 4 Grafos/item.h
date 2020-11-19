/*
* Proyecto Integrador Conceptos Basicos y Algoritmos Fundamentales
* Autor: Jesus David Talamantes Morales
* Matricula: A01706335
* Fecha de Creacion: 20/09/2020 Actualizado: 17/11/2020
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
    int costo,poderA,vida,mana,resM,arma,aceHab,penM;
    /* Atributos
    *  C: Costo, PA: Poder de Habilidad, V: Vida, M: Mana
    *  RE: Reduccion de Enfriamiento, RM: Resistencia Magica
    *  AR: Armadura
    */
  public:
    //Constructor
    Item(string,int,int,int,int,int,int,int,int);
    //Getters
    string get_nomIt() {return nombreItem;}
    int get_cost() {return costo;}
    int get_pa() {return poderA;}
    int get_vid() {return vida;}
    int get_man() {return mana;}
    int get_RM() {return resM;}
    int get_AR() {return arma;}
    int get_AH() {return aceHab;}
    int get_PEN() {return penM;}
    //Metodo
    void mostrarItem();

};
//Constructor principal de la clase
Item::Item(string nomI,int cost,int pod,int vid,int man,int arm,int res,int habAce,int magPen){
  nombreItem = nomI; costo = cost; poderA = pod; vida = vid; mana = man;
  arma = arm; resM = res; aceHab = habAce; penM = magPen;
}

/*Metodo mostrarItem()
 *
 * Esta funcion muestra en pantalla todos los atributos de algun objeto
 * seleccionado excluyendo aquellos que no tengan valor (0).
 */
void Item::mostrarItem(){
  cout<<"\t--------------------------------"<<endl;
  cout<<"\t"<<nombreItem<<endl;
  cout<<"\t"<<costo<<endl<<endl;
  //condicionales para evitar mostrar valores en 0
  if(poderA != 0){
    cout<<"\tPoder de Habilidad: "<<poderA<<endl;
  }
  if(vida != 0){
    cout<<"\tVida: "<<vida<<endl;
  }
  if(mana != 0){
    cout<<"\tMana: "<<mana<<endl;
  }
  if(arma != 0){
    cout<<"\tArmadura: "<<arma<<endl;
  }
  if(resM != 0){
    cout<<"\tResistencia Magica: "<<resM<<endl;
  }
  if(aceHab != 0){
    cout<<"\tAceleracion de Habilidad: "<<aceHab<<endl;
  }
  if(penM != 0){
    cout<<"\tPenetracion Magica: "<<penM<<endl;
  }
  cout<<"\t--------------------------------"<<endl;
  cout<<endl;
}

#endif // ITEM_H_
