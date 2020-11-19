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
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <list>

#include"item.h" //Biblioteca con objetos de item

using namespace std;


class Tienda {
private:
  //Atributos para Grafo
  Item *objeto[41];
  int nodos;
  vector<int> *adjList;
  void addEdgeAdjList(string);
  void sortAdjList();
public:
  //Constructor principal
  Tienda();

  //Funciones principales
  void cargarLista();
  void mostrarLista(int,int);

  //Funciones auxiliares de Grafos
  void loadGraphList(string);
  void printAdjList(int,int);
  string printAdjMat();
  void BFS(int);
  void BFSHelper(int current, queue<int> &qu, bool visited[], int paths[], vector<int> &visitedOrder);
  void printVisited(vector<int> &visitedOrder);
};

/*Constructor desarrollado*/
Tienda::Tienda() {
   nodos = 0;
 }

 /*loadGraphList carga el archivo de texto y usando la función auxiliar de  addEdgeAdjList()
  * inserta los valores del txt a un vector para su uso
  */
 void Tienda::loadGraphList(string file){
 	adjList = new vector<int>[nodos]; //Crea un vector donde guardara todos los nodos
 	// Metodo para abrir y leer un archivo
 	string linea;
 	ifstream lee(file);
 	if (lee.is_open()){
 		while (getline(lee, linea)){
 			addEdgeAdjList(linea); //Llama la función auxiliar para sacar los datos
 		}
 		lee.close(); // Cierra el archivo para evitar corrupcion
 	} else {
 		cout << "El archivo no pudo abrirse";
 	}
 }

 /*Metodo para insertar los datos del txt al arreglo adyacente*/
 void Tienda::addEdgeAdjList(string linea){
  string tu = ""; string tv = "";
 	int u, v;
  stringstream ss(linea);
 	// Toma los caracteres en la posicion 1 y 4 que son los numeros y los guarda en V y U
  getline(ss,tu,',');
  u = stoi(tu);
  getline(ss,tv,'\n');
  v = stoi(tv);
 	adjList[u].push_back(v); // Añade la conexion a v en la posicion u
 	//Esto se realiza debido a que es una lista direccionada
 }

 /*Funcion para imprimir la lista de adyacencia*/
 void Tienda::printAdjList(int inicio, int final){
 	sortAdjList(); //Utiliza una función auxiliar para arreglar y acomodar la lista
  //Se pueden posiblemente mover al menu
  cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<"\tMostrando Lista de Objetos para Magos y sus Evoluciones"<<endl;
  cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  if(inicio == 0 && final == 0){
    //Imprime todos los objetos
    for (int i = 0; i < nodos; i++){
      if(adjList[i].size() != 0){ //Chequeo para evitar imprimir nodos sin conexiones
        cout << objeto[i]->get_nomIt() << " : "; //Imprime el vertice y el numero que este tiene
        for (int j = 0; j < adjList[i].size();j++){
          cout <<"\n";
     			cout << "\t* "<< objeto[adjList[i][j]]->get_nomIt() << " ";
     			//Imprime cada una de la conexiones del vertice anterior
     		}
        cout <<"\n\n";
      }
   	}
  } else {
    for (int i = inicio; i < final; i++){
      if(adjList[i].size() != 0){ //Chequeo para evitar imprimir nodos sin conexiones
        cout << objeto[i]->get_nomIt() << " : "; //Imprime el vertice y el numero que este tiene
        for (int j = 0; j < adjList[i].size();j++){
          cout <<"\n";
     			cout << "\t* "<< objeto[adjList[i][j]]->get_nomIt() << " ";
     			//Imprime cada una de la conexiones del vertice anterior
     		}
        cout <<"\n\n";
      }
   	}
  }
 }

 /*Funcion auxiliar de vector la cual organiza en todo el vector*/
 void Tienda::sortAdjList(){
 	for (int i = 0; i < nodos; i++){
 		sort(adjList[i].begin(), adjList[i].end());
 	}
 }

/*Funcion BFS con la cual realizamos un Breath First Search o una busqueda de
  amplitud para buscar caminos entre los nodos*/
void Tienda::BFS(int inicio){
  queue <int> qu; //Usa una queue para ubicar el siguiente elemento
	bool visited[nodos]; //Crea un arreglo boleano para revisar los nodos visitados
	vector<int> visitedOrder; //Usa un vector para guardar el orden de visita
	int path[nodos]; //Utilizamos un array para guardar el camino de cada nodo
	for (int i = 0; i < nodos; i++){
		visited[i] = false; //Define cada nodo como no visitado
		path[i] = -1; //Define cada padre como -1
	}
	qu.push(inicio); //añade el nodo raiz a la cola Qu
	BFSHelper(inicio, qu, visited, path, visitedOrder); // Llama la funcion auxiliar
	printVisited(visitedOrder);
	//Imprime los nodos visitados y el camino que se siguio para encontrar el nodo meta
};

/*Funcion auxiliar de BFS usando recursividad para recorrer todo el arreglo*/
void Tienda::BFSHelper(int current, queue<int> &qu, bool visited[], int paths[], vector<int> &visitedOrder){
  if(qu.empty()){
    return;
  } else {
    current = qu.front(); // Define current como el primer elemento de qu
    qu.pop(); //Elimina el primer elemento en qu
    visited[current] = true; //Define el nodo current como visitado
    visitedOrder.push_back(current); // Añade el nodo current al vector visitedOrder
    //Checa todos los elementos conectados al nodo
    for (int i = 0; i < adjList[current].size(); i++){
      if (visited[adjList[current][i]] == false){
        qu.push(adjList[current][i]);
        //Empuja al queue cada nodo conectado si es que estos no han sido visitados
        if (paths[adjList[current][i]] == -1){
          paths[adjList[current][i]] = current;
          //Revisa si los nodos estan en posicion de -1 en path si es asi cambia el
          //valor por current
        }
      }
    }
      BFSHelper(current, qu, visited, paths, visitedOrder); // Funcion recursiva
  }
}

/*Funcion auxiliar para imprimir los resultados en este caso el orden de visita*/
void Tienda::printVisited(vector<int> &visitedOrder){
	cout << "\t  Objetos Relacionados"<<endl;
  cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl<<endl;
  cout<<"\tMostrando Lista de Objetos y sus Relaciones"<<endl;
  cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	for (int i = 0; i < visitedOrder.size(); i++){
    cout<<"\t++++++++++++  -"<<visitedOrder[i]<<"-  ++++++++++++"<<endl;
    objeto[visitedOrder[i]]->mostrarItem(); //Imprime cada nodo visitado al string
	}
}

/*Metodo cargarLista()
 *
 * Esta función al igual que en entregas anteriores su principal funcion es el tomar
 * los datos de un txt e insertarlos en un objeto de tipo Item e ir llenando el arreglo
 * auxiliar de objetos para el uso de un grafo
 */
void Tienda::cargarLista(){
  ifstream miarchivo("ObjetosActualizados.txt"); //Archivo a leer
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
    string tempres = "";
    string temparma = "";
    string tempaceH = "";
    string temppenM = "";

    int costo = 0, poderA = 0, vida = 0, mana = 0, resM = 0, arma = 0, aceHab = 0, penM = 0;

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
    getline(ss,tempres,',');
    resM = stoi(tempres);
    getline(ss,temparma,',');
    arma = stoi(temparma);
    getline(ss,tempaceH,',');
    aceHab = stoi(tempaceH);
    getline(ss,temppenM,',');
    penM = stoi(temppenM);

    //Creando objeto tipo item con el constructor del mismo
    Item *a = new Item(nombreItem,costo,poderA,vida,mana,resM,arma,aceHab,penM);

    objeto[nodos] = a;
    nodos++;
  }

  miarchivo.close(); //Cerrando el archivo para evitar que se corrompa

}

/*Metodo mostrarLista()
 *
 * Muestra la lista sin cambios dependiendo del index que se quiera mostrar
 * ya que con esto se dividen los tipos de items
 */
void Tienda::mostrarLista(int inicio, int final){
  if(inicio == 0 && final == 0){
    for(int i = 0; i < nodos; i++){
      cout<<"\t++++++++++++  -"<<i<<"-  ++++++++++++"<<endl;
      objeto[i]->mostrarItem();
    }
  } else {
    for(int i = inicio; i < final; i++){
      cout<<"\t++++++++++++  -"<<i<<"-  ++++++++++++"<<endl;
      objeto[i]->mostrarItem();
    }
  }
}

#endif // TIENDA_H_
