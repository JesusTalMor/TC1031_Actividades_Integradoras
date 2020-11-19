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
  Tienda prueba;
  prueba.cargarLista();

  int opcionMaestra = 0;

  cout<<"Bienvenido a la Nueva y Renovada Tienda de League of Legends"<<endl;
  cout<<"En esta pequeña tienda se observan los objetos para los Magos"<<endl;
  cout<<"Que accion desea realizar ?"<<endl;

  do{
    cout<<"\n";
    cout<<"*************OBJETOS PARA MAGO****************"<<endl;
    cout<<"1. Cargar y Mostrar Lista de Objetos"<<endl;
    cout<<"2. Buscar Complementos de un Objeto"<<endl;
    cout<<"3. Mostrar casos de prueba"<<endl;
    cout<<"4. Salir del Programa"<<endl;
    cout<<"*********************************************"<<endl;
    cout<<"Eliga una opcion: "; cin>>opcionMaestra; cout<<endl;

    switch(opcionMaestra) {
      case 1: {
        int opcion2 = 0;
        do{
          cout<<"-----------------------------------------------------"<<endl;
          cout<<"Bienvenido, Como desea continuar ?"<<endl;
          cout<<"-----------------------------------------------------"<<endl;
          cout<<"1. Mostrar Lista por Completo"<<endl;
          cout<<"2. Mostrar por Rareza de Objeto"<<endl;
          cout<<"3. Salir"<<endl;
          cout<<"-----------------------------------------------------"<<endl;
          cout<<"Eliga una opcion: "; cin>>opcion2; cout<<endl;

          switch(opcion2){
            case 1: {
              cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
              cout<<"  Mostrando Lista de Objetos para Magos Completa"<<endl;
              cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
              cout<<endl;
              cout<<"             OBJETOS INICIALES Y BASICOS "<<endl;
              cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
              prueba.mostrarLista(0,10);
              cout<<endl;
              cout<<"                  OBJETOS EPICOS "<<endl;
              cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
              prueba.mostrarLista(10,22);
              cout<<endl;
              cout<<"               OBJETOS LEGENDARIOS "<<endl;
              cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
              prueba.mostrarLista(22,35);
              cout<<endl;
              cout<<"                  OBJETOS MITICOS "<<endl;
              cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
              prueba.mostrarLista(35,41);
              break;
            }
            case 2: {
              int opcion3 = 0;
              do{
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"Bienvenido, Que Objetos desea mostrar ?"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"1. Objetos Iniciales y Basicos"<<endl;
                cout<<"2. Objetos Epicos"<<endl;
                cout<<"3. Objetos Legendarios"<<endl;
                cout<<"4. Objetos Miticos"<<endl;
                cout<<"5. Salir"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"Eliga una opcion: "; cin>>opcion3; cout<<endl;
                switch(opcion3){
                  case 1:{
                    cout<<endl;
                    cout<<"             OBJETOS INICIALES Y BASICOS "<<endl;
                    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
                    prueba.mostrarLista(0,10);
                    break;
                  }
                  case 2: {
                    cout<<endl;
                    cout<<"                  OBJETOS EPICOS "<<endl;
                    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
                    prueba.mostrarLista(10,22);
                    break;
                  }
                  case 3: {
                    cout<<endl;
                    cout<<"               OBJETOS LEGENDARIOS "<<endl;
                    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
                    prueba.mostrarLista(22,35);
                    break;
                  }
                  case 4: {
                    cout<<endl;
                    cout<<"                  OBJETOS MITICOS "<<endl;
                    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
                    prueba.mostrarLista(35,41);
                    break;
                  }
                }
              }while (opcion3 != 5);
              break;
              }
            }
          }while(opcion2 != 3);
        break;
      }
      case 2: {
        int opcion4 = 0;
        do{
          cout<<"-----------------------------------------------------"<<endl;
          cout<<"Bienvenido, Como desea continuar ?"<<endl;
          cout<<"-----------------------------------------------------"<<endl;
          cout<<"1. Generar objetos por medio de evoluciones"<<endl;
          cout<<"2. Generar objetos por medio de complementos"<<endl;
          cout<<"3. Salir"<<endl;
          cout<<"-----------------------------------------------------"<<endl;
          cout<<"Eliga una opcion: "; cin>>opcion4; cout<<endl;
          switch (opcion4) {
            case 1:{
              prueba.loadGraphList("ConexionesAscendentes.txt");
              cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
              cout<<"Mostrando Objetos para Buscar sus Evoluciones"<<endl;
              cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
              cout<<endl;
              cout<<"             OBJETOS INICIALES Y BASICOS "<<endl;
              cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
              prueba.mostrarLista(0,10);
              cout<<endl;
              cout<<"                  OBJETOS EPICOS "<<endl;
              cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
              prueba.mostrarLista(10,22);
              int opcion5 = 0;
              cout<<"-----------------------------------------------------"<<endl;
              cout<<"Para mostrar todos los elementos presione 99"<<endl;
              cout<<"-----------------------------------------------------"<<endl;
              cout<<"Eliga una objeto con base a su numero: "; cin>>opcion5; cout<<endl;
              if(opcion5 == 99){
                cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
                cout<<"  Mostrando Objetos y sus Evoluciones"<<endl;
                cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
                cout<<endl;
                cout<<"             OBJETOS INICIALES Y BASICOS "<<endl;
                cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
                prueba.printAdjList(0,10);
                cout<<endl;
                cout<<"                  OBJETOS EPICOS "<<endl;
                cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
                prueba.printAdjList(10,22);
              } else {prueba.BFS(opcion5);}
              break;
            }
            case 2:{
              prueba.loadGraphList("ConexionesDescendentes.txt");
              cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
              cout<<"Mostrando Objetos para Buscar sus Complementos"<<endl;
              cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
              cout<<endl;
              cout<<"               OBJETOS LEGENDARIOS "<<endl;
              cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
              prueba.mostrarLista(22,35);
              cout<<endl;
              cout<<"                  OBJETOS MITICOS "<<endl;
              cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
              prueba.mostrarLista(35,41);
              int opcion5 = 0;
              cout<<"-----------------------------------------------------"<<endl;
              cout<<"Para mostrar todos los elementos presione 99"<<endl;
              cout<<"-----------------------------------------------------"<<endl;
              cout<<"Eliga una objeto con base a su numero: "; cin>>opcion5; cout<<endl;
              if(opcion5 == 99){
                cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
                cout<<"  Mostrando Objetos y sus Complementos"<<endl;
                cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
                cout<<endl;
                cout<<"               OBJETOS LEGENDARIOS "<<endl;
                cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
                prueba.printAdjList(22,35);
                cout<<endl;
                cout<<"                  OBJETOS MITICOS "<<endl;
                cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
                prueba.printAdjList(35,41);
              } else {prueba.BFS(opcion5);}
              break;
            }
          }
        }while(opcion4 != 3);
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
        cout<<"rareza del objeto dividiendolos en categorias"<<endl;
        cout<<"Presione un numero y enter: "; cin>>aux; cout<<endl;
        cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        cout<<"  Mostrando Lista de Objetos para Magos Completa"<<endl;
        cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        cout<<endl;
        cout<<"             OBJETOS INICIALES Y BASICOS "<<endl;
        cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        prueba.mostrarLista(0,10);
        cout<<endl;
        cout<<"                  OBJETOS EPICOS "<<endl;
        cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        prueba.mostrarLista(10,22);
        cout<<endl;
        cout<<"               OBJETOS LEGENDARIOS "<<endl;
        cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        prueba.mostrarLista(22,35);
        cout<<endl;
        cout<<"                  OBJETOS MITICOS "<<endl;
        cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        prueba.mostrarLista(35,41);
        cout<<"-----------------------------------------------------"<<endl<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"Prueba 2"<<endl;
        cout<<"Comprobando correcta muestra de la lista de adyacencia"<<endl;
        cout<<"haciendo uso de las funciones loadGraphList() y printAdjList"<<endl;
        cout<<"Se deberia mostrar una lista de objetos ordenada por el"<<endl;
        cout<<"rareza y se muestra las posibles evoluciones de los objetos"<<endl;
        cout<<"Presione un numero y enter: "; cin>>aux; cout<<endl;
        prueba.loadGraphList("ConexionesAscendentes.txt");
        cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        cout<<"  Mostrando Objetos y sus Evoluciones"<<endl;
        cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        cout<<endl;
        cout<<"             OBJETOS INICIALES Y BASICOS "<<endl;
        cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        prueba.printAdjList(0,10);
        cout<<endl;
        cout<<"                  OBJETOS EPICOS "<<endl;
        cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        prueba.printAdjList(10,22);
        cout<<"-----------------------------------------------------"<<endl<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"Prueba 4"<<endl;
        cout<<"Comprobando creacion de correcto funcionamiento de la funcion BFS"<<endl;
        cout<<"para la busqueda de los complementos de un objeto en especifico"<<endl;
        cout<<"Se deberia de mostrar en pantalla el objeto numero 40 y"<<endl;
        cout<<"posteriormente los complementos que crean este objeto"<<endl;
        cout<<"Presione un numero y enter: "; cin>>aux; cout<<endl;
        prueba.loadGraphList("ConexionesDescendentes.txt");
        prueba.BFS(40);
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
