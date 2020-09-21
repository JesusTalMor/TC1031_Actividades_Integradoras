/*
* Proyecto Integrador Conceptos Basicos y Algoritmos Fundamentales
* Autor: Jesus David Talamantes Morales
* Matricula: A01706335
* Fecha de Creacion: 20/09/2020
*/
#include <iostream>

#include "Tienda.h"

using namespace std;

int main(){
  //Generando pruebas original y copia
  Tienda *original = new Tienda();
  original->cargarLista();

  Tienda *copia = new Tienda();
  copia->cargarLista();

  int opcionMaestra = 0;

  cout<<"Bienvenido a la tiendo de objetos de League of Legends"<<endl;
  cout<<"Que accion desea realizar ?"<<endl;

  do{
    cout<<"\n";
    cout<<"*************OBJETOS MAGICOS****************"<<endl;
    cout<<"1. Mostrar objetos sin ordenar"<<endl;
    cout<<"2. Ordenar la lista de objetos por atributo"<<endl;
    cout<<"3. Buscar objetos por atributo"<<endl;
    cout<<"4. Guardar el conjunto de objetos"<<endl;
    cout<<"5. Salir del Programa"<<endl;
    cout<<"*******************************************"<<endl;
    cout<<"Eliga una opcion: "; cin>>opcionMaestra; cout<<endl;

    switch(opcionMaestra) {
      case 1: {
        original->mostrarLista(); break;
      }
      case 2: {
        int opcion1 = 0;
        do{
          cout<<"---------------------------------------"<<endl;
          cout<<"Bienvenido al sistema de ordenamieno"<<endl;
          cout<<"Porfavor seleccione alguna opcion"<<endl;
          cout<<"---------------------------------------"<<endl;
          cout<<"Ordenar Lista de Objetos por:"<<endl;
          cout<<"1. Nombre"<<endl;
          cout<<"2. Costo"<<endl;
          cout<<"3. Poder de Habilidad"<<endl;
          cout<<"4. Vida Obtenida"<<endl;
          cout<<"5. Mana Obtenido"<<endl;
          cout<<"6. Reduccion de Enfriamiento"<<endl;
          cout<<"7. Resistencia Magica"<<endl;
          cout<<"8. Armadura"<<endl;
          cout<<"9. Salir"<<endl;
          cout<<"---------------------------------------"<<endl;
          cout<<"Eliga una opcion: "; cin>>opcion1; cout<<endl;

          switch (opcion1) {
            case 1: {
              copia->ordenSelecNombre();
              copia->mostrarLista();
              break;
            }
            case 2: {
              copia->ordenSelecCosto();
              copia->mostrarLista();
              break;
            }
            case 3: {
              copia->ordenSelecPoderA();
              copia->mostrarLista();
              break;
            }
            case 4: {
              copia->ordenSelecVida();
              copia->mostrarLista();
              break;
            }
            case 5: {
              copia->ordenBurbMana();
              copia->mostrarLista();
              break;
            }
            case 6: {
              copia->ordenBurbRE();
              copia->mostrarLista();
              break;
            }
            case 7: {
              copia->ordenBurbRM();
              copia->mostrarLista();
              break;
            }
            case 8: {
              copia->ordenBurbAR();
              copia->mostrarLista();
              break;
            }
          }
        }while(opcion1 != 9);
        break;
      }
      case 3: {
        int opcion2 = 0;
        do{
          cout<<"-----------------------------------------------------"<<endl;
          cout<<"Bienvenido que atributo desea buscar?"<<endl;
          cout<<"-----------------------------------------------------"<<endl;
          cout<<"1. Vida  2. Mana   3.Reduccion de enfiramiento"<<endl;
          cout<<"4. Resistencia Magica  5. Armadura  6. Salir"<<endl;
          cout<<"-----------------------------------------------------"<<endl;
          cout<<"Eliga una opcion: "; cin>>opcion2; cout<<endl;
          copia->busqSeqAtri(opcion2);
        }while(opcion2 != 6);
        break;
      }
      case 4: {
        cout<<"Esta apunto de generar un archivo .txt"<<endl;
        cout<<"Este archivo tendra la ultima lista que uso"<<endl;
        copia->guardarLista();
        break;
      }
    }
  }while(opcionMaestra != 5);

  cout<<"Gracias por usar el programa. :D"<<endl;
  cout<<"Cerrando programa"<<endl;

  return 0;
}
