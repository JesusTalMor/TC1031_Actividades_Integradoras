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
  //Generando prueba original
  Tienda original;
  original.cargarLista();

  int opcionMaestra = 0;

  cout<<"Bienvenido a la tiendo de objetos de League of Legends"<<endl;
  cout<<"Que accion desea realizar ?"<<endl;

  do{
    cout<<"\n";
    cout<<"*************OBJETOS MAGICOS****************"<<endl;
    cout<<"1. Mostrar lista de objetos"<<endl;
    cout<<"2. Buscar objetos por atributo"<<endl;
    cout<<"3. Guardar el conjunto de objetos"<<endl;
    cout<<"4. Mostrar casos de prueba"<<endl;
    cout<<"5. Salir del Programa"<<endl;
    cout<<"*******************************************"<<endl;
    cout<<"Eliga una opcion: "; cin>>opcionMaestra; cout<<endl;

    switch(opcionMaestra) {
      case 1: {
        original.mostrarLista(); break;
      }
      case 2: {
        int opcion2 = 0;
        do{
          cout<<"-----------------------------------------------------"<<endl;
          cout<<"Bienvenido que atributo desea buscar?"<<endl;
          cout<<"-----------------------------------------------------"<<endl;
          cout<<"1. Vida  2. Mana   3.Reduccion de enfiramiento"<<endl;
          cout<<"4. Resistencia Magica  5. Armadura  6. Salir"<<endl;
          cout<<"-----------------------------------------------------"<<endl;
          cout<<"Eliga una opcion: "; cin>>opcion2; cout<<endl;
          original.buscarLista(opcion2);
        }while(opcion2 != 6);
        break;
      }
      case 3: {
        cout<<"Esta apunto de generar un archivo .txt"<<endl;
        cout<<"Este archivo tendra la ultima lista que uso"<<endl;
        original.guardarLista();
        break;
      }
      case 4: {
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"Mostrando casos de prueba"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"Prueba 1"<<endl;
        cout<<"Comprobando correcta muestra de la lista por medio de la"<<endl;
        cout<<"funcion mostrarLista()"<<endl;
        cout<<"Se deberia mostrar una lista de objetos"<<endl;
        int aux;
        cout<<"Presione 1 para continuar: "; cin>>aux; cout<<endl;
        //Buscar alguna otra manera de frenar el programa
        original.mostrarLista();
        cout<<"-----------------------------------------------------"<<endl<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"Prueba 2"<<endl;
        cout<<"Comprobando busqueda de objetos por atributos"<<endl;
        cout<<"funcion buscarLista()"<<endl;
        cout<<"Se deberia mostrar una lista de objetos con la"<<endl;
        cout<<"caracteristica de armadura"<<endl;
        cout<<"Presione 1 para continuar: "; cin>>aux; cout<<endl;
        original.buscarLista(5);
        cout<<"-----------------------------------------------------"<<endl<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"Prueba 3"<<endl;
        cout<<"Se deberia mostrar una lista de objetos con la"<<endl;
        cout<<"caracteristica de vida"<<endl;
        cout<<"Presione 1 para continuar: "; cin>>aux; cout<<endl;
        original.buscarLista(1);
        cout<<"-----------------------------------------------------"<<endl<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"Prueba 4"<<endl;
        cout<<"Compobando creacion de archivo txt para guardar los objetos"<<endl;
        cout<<"funcion guardarLista()"<<endl;
        cout<<"Se deberia generar un archivo txt con el nombre ListaGuardada en"<<endl;
        cout<<"su misma carpeta donde se encuentran los demas archivos"<<endl;
        cout<<"Presione 1 para continuar: "; cin>>aux; cout<<endl;
        original.guardarLista();
        cout<<"-----------------------------------------------------"<<endl<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"Finalizando Casos de pruebas"<<endl;
        cout<<"Si todo se genero de manera correcta continue con el programa"<<endl;
        cout<<"-----------------------------------------------------"<<endl<<endl;
      }
    }
  }while(opcionMaestra != 5);

  cout<<"Gracias por usar el programa. :D"<<endl;
  cout<<"Cerrando programa"<<endl;
  return 0;
}
