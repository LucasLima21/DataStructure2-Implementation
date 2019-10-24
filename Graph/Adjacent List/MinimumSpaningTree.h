#ifndef MinimumSpaningTree_h
#define MinimumSpaningTree_h
#include "AdjacentList.h"
#include <iostream>
using namespace std;

template<typename Type>
class MST{
private:
  Graph<Type> * g;
  int * key, * minimumPriorityArray, * prevVertexArray;
  bool * checkVertex;
public:
  MST(int);
  void mstPrim(Graph<Type> *, int);
  void mstMap(Graph<Type> *);
  int extractMin(int * key, bool * checkVertex){
    int min = INT_MAX, minIndex;
    for(int i = 1; i <= g->getOrder(); i++){
      if(checkVertex[i] == false && key[i] < min){
        min = key[i], minIndex = i;
      }
    }
    return minIndex;
  }

};
template<typename Type>
MST<Type>::MST(int order){
  g = new Graph<Type>(order);
  key = new int[g->getOrder()+1];
  prevVertexArray = new int[g->getOrder()+1];
  minimumPriorityArray = new int[g->getOrder()+1];
  checkVertex = new bool[g->getOrder()+1];
}

template<typename Type>
void MST<Type>::mstPrim(Graph<Type> * g, int r){
  for(int i = 1; i <= g->getOrder(); i++){
    key[i] = INT_MAX;
    prevVertexArray[i] = 0;
    checkVertex[i] = false;
  }
  key[r] = 0;
  for(int i = 1; i <= g->getOrder(); i++){
    int u = extractMin(key,checkVertex);
    checkVertex[u] = true;
    Node<Vertex<Type>> * v = g->getAdjVertex()[u].getFirst()->getNext(); 
    while(v!= NULL){
      int j = v->getItem().getIndex();
      int k = g->weightUV(u,j);
      if(checkVertex[j] == false && k < key[j]){
        prevVertexArray[j] = u;
        key[j] = k;
      }
      v = v->getNext();
    }
  }

}

template<typename Type>
void MST<Type>::mstMap(Graph<Type> * g){
  cout << "<<Minimum Spaning Tree (MST)>>\nPrevious Vertex Array = [ ";
  for(int i = 1 ; i <= g->getOrder(); i++)  cout << prevVertexArray[i] << " ";
  cout << "]" << endl;
  cout << "Key Array (weights) = [ ";
  for(int i = 1; i <= g->getOrder(); i++) cout << key[i] << " ";
  cout << "]" << endl;
}
#endif
