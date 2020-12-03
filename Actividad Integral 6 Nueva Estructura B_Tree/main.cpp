/*
 * main.cpp de Actividad Integral 6
 * Creado en: 02/12/2020
 * Author: Jesus David Talamantes Morales
 * Codigo recopilado de:
 *        https://www.geeksforgeeks.org/introduction-of-b-tree-2/
 *        https://www.geeksforgeeks.org/insert-operation-in-b-tree/
 *        https://www.geeksforgeeks.org/delete-operation-in-b-tree/
*/

#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include "Btree.h"

using namespace std;

void CasosPrueba();

int main() {
  int opcionMaestra = 0;
  do{
    cout << "///////////////Bienvenido///////////////////"<<endl;
    cout << "1. Trabajar con la estructura B-Tree"<<endl;
    cout << "2. Mostrar casos de prueba"<<endl;
    cout << "3. Salir del programa"<<endl;
    cout << "///////////////////////////////////////////"<<endl;
    cout << "Eliga una opcion: "; cin>>opcionMaestra; cout<<endl;

    switch(opcionMaestra){
      case 1: {
        int opcion1 = 0;
        int variable = 0;
        cout << "Inserte el numero de llaves minimo en cada nodo: ";
        cin >> variable; cout<<endl;
        cout << "Creando B Tree" << endl;
        BTree t(variable);
        do {
          cout<<"-----------------------------------------------------"<<endl;
          cout<<"Bienvenido, Como desea continuar ?"<<endl;
          cout<<"-----------------------------------------------------"<<endl;
          cout<<"1. Insertar"<<endl;
          cout<<"2. Buscar"<<endl;
          cout<<"3. Mostrar"<<endl;
          cout<<"4. Borrar"<<endl;
          cout<<"5. Salir"<<endl;
          cout<<"-----------------------------------------------------"<<endl;
          cout<<"Eliga una opcion: "; cin>>opcion1; cout<<endl;

          switch(opcion1){
            case 1: {
              int variable1 = 0;
              cout << "Inserte el valor de la llave que desea insertar: ";
              cin >> variable1; cout<<endl;
              t.insert(variable1);
              cout << t.traverse() <<"\n";
              break;
            }
            case 2: {
              int variable1 = 0;
              cout << "Inserte el valor que desea buscar: ";
              cin >> variable1; cout<<endl;
              (t.search(variable1) != NULL)? cout << "Encontrado\n" : cout << "No Encontrado\n";
              break;
            }
            case 3: {
              cout << "Mostrando estructura B Tree" << endl;
              cout << t.traverse() <<"\n";
              break;
            }
            case 4: {
              int variable1 = 0;
              cout << "Inserte el valor que desea remover: ";
              cin >> variable1; cout<<endl;
              t.remove(variable1);
              cout << t.traverse() <<"\n";
              break;
            }
          }
        }while(opcion1 != 5);
        opcionMaestra = 3;
        break;
      }
      case 2: {
        CasosPrueba();
        opcionMaestra = 3;
        break;
      }
    }
  }while(opcionMaestra != 3);

  cout << "Terminando programa que tenga buen dia :D" << endl;

  return 0;
}

void CasosPrueba() {
  BTree t(3); // A B-Tree with minium degree 3
  string ans;

  t.insert(1);
  t.insert(3);
  t.insert(7);
  t.insert(10);
  t.insert(11);
  t.insert(13);
  t.insert(14);
  t.insert(15);
  t.insert(18);
  t.insert(16);
  t.insert(19);
  t.insert(24);
  t.insert(25);
  t.insert(26);
  t.insert(21);
  t.insert(4);
  t.insert(5);
  t.insert(20);
  t.insert(22);
  t.insert(2);
  t.insert(17);
  t.insert(12);
  t.insert(6);

  cout << "Iniciado casos de prueba...\n";
  cout << "Imprimiendo B Tree\n";
  ans = "[ 1 2 3 4 5 6 7 10 11 12 13 14 15 16 17 18 19 20 21 22 24 25 26]";
  cout << t.traverse() <<"\n";
  cout << " 1 " <<	(!ans.compare(t.traverse()) ? "success\n" : "fail\n");


  cout << "Removiendo 6 e imprimiendo B Tree\n";
  ans = "[ 1 2 3 4 5 7 10 11 12 13 14 15 16 17 18 19 20 21 22 24 25 26]";
  t.remove(6);
  cout << t.traverse() <<"\n";
  cout << " 2 " <<	(!ans.compare(t.traverse()) ? "success\n" : "fail\n");


  cout << "Removiendo 13 e imprimiendo B Tree\n";
  ans = "[ 1 2 3 4 5 7 10 11 12 14 15 16 17 18 19 20 21 22 24 25 26]";
  t.remove(13);
  cout << t.traverse() <<"\n";
  cout << " 3 " <<	(!ans.compare(t.traverse()) ? "success\n" : "fail\n");


  cout << "Removiendo 7 e imprimiendo B Tree\n";
  ans = "[ 1 2 3 4 5 10 11 12 14 15 16 17 18 19 20 21 22 24 25 26]";
  t.remove(7);
  cout << t.traverse() <<"\n";
  cout << " 4 " <<	(!ans.compare(t.traverse()) ? "success\n" : "fail\n");


  cout << "Removiendo 4 e imprimiendo B Tree\n";
  ans = "[ 1 2 3 5 10 11 12 14 15 16 17 18 19 20 21 22 24 25 26]";
  t.remove(4);
  cout << t.traverse() <<"\n";
  cout << " 5 " <<	(!ans.compare(t.traverse()) ? "success\n" : "fail\n");


  cout << "Removiendo 2 e imprimiendo B Tree\n";
  ans = "[ 1 3 5 10 11 12 14 15 16 17 18 19 20 21 22 24 25 26]";
  t.remove(2);
  cout << t.traverse() <<"\n";
  cout << " 6 " <<	(!ans.compare(t.traverse()) ? "success\n" : "fail\n");


  cout << "Removiendo 16 e imprimiendo B Tree\n";
  ans = "[ 1 3 5 10 11 12 14 15 17 18 19 20 21 22 24 25 26]";
  t.remove(16);
  cout << t.traverse() <<"\n";
  cout << " 7 " <<	(!ans.compare(t.traverse()) ? "success\n" : "fail\n");

  cout << "Bucando 22 en el B Tree\n";
  cout << " 8 "; (t.search(22) != NULL)? cout << "Encontrado\n" : cout << "No Encontrado\n";

  cout << "Bucando 5 en el B Tree\n";
  cout << " 9 "; (t.search(5) != NULL)? cout << "Encontrado\n" : cout << "No Encontrado\n";

  cout << "Bucando 17 en el B Tree\n";
  cout << " 10 "; (t.search(17) != NULL)? cout << "Encontrado\n" : cout << "No Encontrado\n";

  cout << "Bucando 12 en el B Tree\n";
  cout << " 11 "; (t.search(12) != NULL)? cout << "Encontrado\n" : cout << "No Encontrado\n";

  cout << "Bucando 34 en el B Tree\n";
  cout << " 12 "; (t.search(34) != NULL)? cout << "Encontrado\n" : cout << "No Encontrado\n";

  cout << "Bucando 2 en el B Tree\n";
  cout << " 13 "; (t.search(2) != NULL)? cout << "Encontrado\n" : cout << "No Encontrado\n";

  cout << "Bucando 16 en el B Tree\n";
  cout << " 14 "; (t.search(16) != NULL)? cout << "Encontrado\n" : cout << "No Encontrado\n";

  cout << "Bucando 23 en el B Tree\n";
  cout << " 15 "; (t.search(23) != NULL)? cout << "Encontrado\n" : cout << "No Encontrado\n";
}
