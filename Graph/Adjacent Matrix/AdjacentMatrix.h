#ifndef AjacentMatrix_h
#define AdjacentMatrix_h
#include <iostream>
#include <iomanip>
#include <limits.h>
using namespace std;

template<typename Type>
class Vertex{
private:
  Type itemVertex;
  int weight;
public:
  Vertex();
  Vertex(Type,int);
  Type getItemVertex();
  void setItemVertex(Type itemVertex);
  int getWeight();
  void setWeight(int weight);

};
template<typename Type>
int Vertex<Type>::getWeight(){
  return weight;
}
template<typename Type>
void Vertex<Type>::setWeight(int weight){
  this->weight = weight;
}
template<typename Type>
Type Vertex<Type>::getItemVertex(){
  return itemVertex;
}
template<typename Type>
void Vertex<Type>::setItemVertex(Type itemVertex){
  this->itemVertex = itemVertex;
}

template<typename Type>
Vertex<Type>::Vertex(Type itemVertex, int weight){
  this->weight = weight;
  this->itemVertex = itemVertex;
}
template<typename Type>
Vertex<Type>::Vertex(){
  weight = 0;
}


template<typename Type>
class Graph{
private:
  Vertex<Type> ** matrix;
  int order, extentGraph;

public:
  Graph(int);
  void initialize(int);
  void insertEdge(int, int, int);
  void printGraph();
  void destroyGraph();
  void setOrder(int);
  int getOrder();
  void setMatrix(Vertex<Type> **);
  Vertex<Type> ** getMatrix();
  int weightUV(int,int);
};

template<typename Type>
void Graph<Type>::setMatrix(Vertex<Type> ** matrix){
  this->matrix = matrix;
}
template<typename Type>
Vertex<Type> ** Graph<Type>::getMatrix(){
  return matrix;
}

template<typename Type>
void Graph<Type>::setOrder(int order){
  this->order = order;
}
template<typename Type>
int Graph<Type>::getOrder(){
  return order;
}

template<typename Type>
Graph<Type>::Graph(int order){
  this->order = order;
  matrix = new Vertex<Type>*[order+1];
  for(int i = 0; i < order+1; i++){
    matrix[i] = new Vertex<Type>[order+1];
  }
  initialize(order);
}

template<typename Type>
void Graph<Type>::initialize(int order){
  for(int i = 0; i < order+1; i++){
    for(int j = 0; j < order+1; j++){
      matrix[i][j].setWeight(0);
    }
  }
}


template<typename Type>
void Graph<Type>::insertEdge(int u, int v, int weight){
  matrix[u][v].setWeight(weight);
  matrix[v][u].setWeight(weight);
  extentGraph++;
}


template<typename Type>
void Graph<Type>::destroyGraph(){
  for(int i = 0; i < order+1; i++){
    delete [] matrix[i];
  }
  delete [] matrix;
}

template<typename Type>
void Graph<Type>::printGraph(){
  int k = 3;
  cout << " ";
  for(int i = 1 ; i < order + 1; i++) cout <<  setw(k) << i;
  cout << endl;
  for(int j = 1 ; j < order + 1; j++)  cout << "----";
  cout << endl;
  for(int i = 1 ; i < order + 1; i++){
    cout << setw(1) << i << " |";
    for(int j = 1 ; j < order + 1; j++) cout << setw(k) << matrix[i][j].getWeight();
    cout << endl;
  }
}

#endif
