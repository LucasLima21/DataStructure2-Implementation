#ifndef DepthFirstSearch_h
#define DepthFirstSearch_h
#include "AdjacentList.h"
#include <iostream>
using namespace std;

template<typename Type>
class DFS{
private:
  Graph<Type> * g;
  int * prevVertexArray, * discoveryTime, * finishTime;
  string * colorArray;
  int times;
  void dfsVisit(Graph<Type>*,int);
  int highestValue(int*,int);
public:
  DFS(int);
  void dfs(Graph<Type>*);
  void dfsMap(Graph<Type> *);
  LinkedList<Vertex<Type>> * topologicalSort(Graph<Type> *);
  Graph<Type> * getG();
  void setG(Graph<Type> * g);
  int * getPrevVertexArray();
  void setPrevVertexArray(int * prevVertexArray);
  int * getDiscoveryTime();
  void setDiscoveryTime(int * discoveryTime);
  int * getFinishTime();
  void setFinishTime(int * finishTime);
  string * getColorArray();
  void setColorArray(string * colorArray);
  int getTimes();
  void setTimes(int times);
};
template<typename Type>
Graph<Type> * DFS<Type>::getG(){
  return g;
}
template<typename Type>
void DFS<Type>::setG(Graph<Type> * g){
  this->g = g;
}
template<typename Type>
int * DFS<Type>::getPrevVertexArray(){
  return prevVertexArray;
}
template<typename Type>
void DFS<Type>::setPrevVertexArray(int * prevVertexArray){
  this->prevVertexArray = prevVertexArray;
}
template<typename Type>
int * DFS<Type>::getDiscoveryTime(){
  return discoveryTime;
}
template<typename Type>
void DFS<Type>::setDiscoveryTime(int * discoveryTime){
  this->discoveryTime = discoveryTime;
}
template<typename Type>
int * DFS<Type>::getFinishTime(){
  return finishTime;
}
template<typename Type>
void DFS<Type>::setFinishTime(int * finishTime){
  this->finishTime = finishTime;
}
template<typename Type>
string * DFS<Type>::getColorArray(){
  return colorArray;
}
template<typename Type>
void DFS<Type>::setColorArray(string * colorArray){
  this->colorArray = colorArray;
}
template<typename Type>
int DFS<Type>::getTimes(){
  return times;
}
template<typename Type>
void DFS<Type>::setTimes(int times){
  this->times = times;
}

template<typename Type>
DFS<Type>::DFS(int order){
  g = new Graph<Type>(order);
  prevVertexArray = new int[g->getOrder()+1];
  colorArray = new string[g->getOrder()+1];
  discoveryTime = new int[g->getOrder()+1];
  finishTime = new int[g->getOrder()+1];
}

template<typename Type>
void DFS<Type>::dfs(Graph<Type> * g){
  for(int i = 1; i <= g->getOrder(); i++) colorArray[i] = "White";
  times=0;
  for(int i = 1; i<= g->getOrder(); i++){
    if(colorArray[i] == "White"){
      dfsVisit(g,i);
    }
  }
}

template<typename Type>
void DFS<Type>::dfsVisit(Graph<Type> * g, int i){
  times++;
  discoveryTime[i] = times;
  colorArray[i] = "Grey";

  Node<Vertex<Type>> * j = g->getAdjVertex()[i].getFirst()->getNext();
  while(j != NULL){
    int aux = j->getItem().getIndex();
    if(colorArray[aux] == "White"){
      prevVertexArray[aux] = i;
      dfsVisit(g,aux);
    }
    j = j->getNext();
  }
  colorArray[i] = "Black";
  times++;
  finishTime[i] = times;
}


template<typename Type>
void DFS<Type>::dfsMap(Graph<Type> * g){
  cout << "<<Depth First Search(DFS) >>" << endl;
  cout << "Previous = [ ";
  for(int i = 1; i <= g->getOrder(); i++) cout << prevVertexArray[i] << " ";
  cout << "]"<<endl;
  cout << "Colors = [ ";
  for(int i = 1; i <= g->getOrder(); i++) cout << colorArray[i] << " ";
  cout << "]"<<endl;
  cout << "Discovery Time = [ ";
  for(int i = 1; i <= g->getOrder(); i++) cout << discoveryTime[i] << " ";
  cout << "]"<<endl;
  cout << "Finish Time = [ ";
  for(int i = 1; i <= g->getOrder(); i++) cout << finishTime[i] << " ";
  cout << "]"<<endl;
}


template<typename Type>
int DFS<Type>::highestValue(int * array, int extent){
    int bigger = array[1], position = 0;
    for(int i = 1; i <= extent; i++){
      if(bigger <= array[i]){
        bigger = array[i];
        position = i;
      }
    }
    return position;
}


template<typename Type>
LinkedList<Vertex<Type>> * DFS<Type>::topologicalSort(Graph<Type> * g){
  LinkedList<Vertex<Type>> * list = new LinkedList<Vertex<Type>>[g->getOrder()+1];
  int savePosition = 0;
  dfs(g);
  for(int i = 1; i <= g->getOrder(); i++){
    savePosition = highestValue(finishTime,g->getOrder());
    finishTime[savePosition] = 0;
    Node<Vertex<Type>> * aux = g->getAdjVertex()[savePosition].getFirst()->getNext();
    while(aux!=NULL){
      list[i].insert(aux->getItem());
      aux = aux->getNext();
    }
    delete aux;
  }
  cout << "<<Vertex Linked List for Topological Sort>>"<< endl;
  for(int i = 1; i <= g->getOrder() ; i++){
    cout << i << " ";
    list[i].printList();
  }
  return list;
}
#endif
