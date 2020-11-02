/*
* Proyecto Integrador Conceptos Basicos y Algoritmos Fundamentales
* Autor: Jesus David Talamantes Morales
* Matricula: A01706335
* Fecha de Creacion: 20/09/2020 Actualizado 01/11/2020
*/
#include <iostream>

#include "tienda.h"

using namespace std;

int main(){
  //Generando prueba original
  Tienda original;


  int opcionMaestra = 0;

  cout<<"Bienvenido a la tiendo de objetos de League of Legends"<<endl;
  cout<<"Que accion desea realizar ?"<<endl;

  do{
    cout<<"\n";
    cout<<"*************OBJETOS MAGICOS****************"<<endl;
    cout<<"1. Cargar lista de objetos"<<endl;
    cout<<"2. Guardar el conjunto de objetos"<<endl;
    cout<<"3. Mostrar casos de prueba"<<endl;
    cout<<"4. Salir del Programa"<<endl;
    cout<<"*******************************************"<<endl;
    cout<<"Eliga una opcion: "; cin>>opcionMaestra; cout<<endl;

    switch(opcionMaestra) {
      case 1: {
        int opcion2 = 0;
        do{
          cout<<"-----------------------------------------------------"<<endl;
          cout<<"Bienvenido, por que atributo desea cargar la lista?"<<endl;
          cout<<"-----------------------------------------------------"<<endl;
          cout<<"1. Nombre  2. Costo   3.Salir"<<endl;
          cout<<"-----------------------------------------------------"<<endl;
          cout<<"Eliga una opcion: "; cin>>opcion2; cout<<endl;
          original.cargarLista(opcion2);
          original.mostrarLista(opcion2);
        }while(opcion2 != 3);
        break;
      }
      case 2: {
        int opcion2 = 0;
        do{
          cout<<"-----------------------------------------------------"<<endl;
          cout<<"Bienvenido, Esta apunto de generar un archivo .txt"<<endl;
          cout<<"con base en el siguiente atributo"<<endl;
          cout<<"-----------------------------------------------------"<<endl;
          cout<<"1. Nombre  2. Costo   3.Salir"<<endl;
          cout<<"-----------------------------------------------------"<<endl;
          cout<<"Eliga una opcion: "; cin>>opcion2; cout<<endl;
          original.cargarLista(opcion2);
          original.guardarLista();
        }while(opcion2 != 3);
        break;
      }
      case 3: {
        int aux;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"Mostrando casos de prueba"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"Prueba 1"<<endl;
        cout<<"Comprobando correcta muestra de la lista por medio de las"<<endl;
        cout<<"funciones cargarLista() y mostrarLista()"<<endl;
        cout<<"Se deberia mostrar una lista de objetos ordenada por el"<<endl;
        cout<<"atributo nombre en orden Alfabetico"<<endl;
        cout<<"Presione un numero y enter: "; cin>>aux; cout<<endl;
        original.cargarLista(1);
        original.mostrarLista(1);
        cout<<"-----------------------------------------------------"<<endl<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"Prueba 2"<<endl;
        cout<<"Comprobando correcta muestra de la lista por medio de las"<<endl;
        cout<<"funciones cargarLista() y mostrarLista()"<<endl;
        cout<<"Se deberia mostrar una lista de objetos ordenada por el"<<endl;
        cout<<"atributo costo de menor a mayor"<<endl;
        cout<<"Presione un numero y enter: "; cin>>aux; cout<<endl;
        original.cargarLista(2);
        original.mostrarLista(2);
        cout<<"-----------------------------------------------------"<<endl<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"Prueba 4"<<endl;
        cout<<"Compobando creacion de archivo txt para guardar los objetos"<<endl;
        cout<<"funcion guardarLista()"<<endl;
        cout<<"Se deberia generar un archivo txt con el nombre ListaGuardada en"<<endl;
        cout<<"su misma carpeta donde se encuentran los demas archivos."<<endl;
        cout<<"Este archivo se guardara con la estructura en nombre."<<endl;
        cout<<"Presione un numero y enter: "; cin>>aux; cout<<endl;
        original.cargarLista(1);
        original.guardarLista();
        cout<<"-----------------------------------------------------"<<endl<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"Finalizando Casos de pruebas"<<endl;
        cout<<"Si todo se genero de manera correcta continue con el programa"<<endl;
        cout<<"-----------------------------------------------------"<<endl<<endl;
      }
    }
  }while(opcionMaestra != 4);

  cout<<"Gracias por usar el programa. :D"<<endl;
  cout<<"Cerrando programa"<<endl;
  return 0;
}
