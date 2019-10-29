#ifndef PrimAlgorithm_h
#define PrimAlgorithm_h
#include <iostream>
#include <limits.h>
using namespace std;
template<typename Type>
class PrimMST{
private:
  Graph<Type> * g;
  int * key, * prevVertexArray;
  bool * checkVertex;
  int extractMin(int *, bool *);
  void mstPrim(Graph<Type> *, int);
public:
  PrimMST(Graph<Type> *, int);
  void mstPrimMap();
};


template<typename Type>
PrimMST<Type>::PrimMST(Graph<Type> * g, int source){
  this->g = g;
  key = new int[g->getOrder()+1];
  prevVertexArray = new int[g->getOrder()+1];
  checkVertex = new bool[g->getOrder()+1];
  mstPrim(g,source);
}

template<typename Type>
int PrimMST<Type>::extractMin(int * key, bool * checkVertex){
  int min = INT_MAX, minIndex;
  for(int i = 1; i <= g->getOrder(); i++){
    if(checkVertex[i] == false && key[i] < min){
      min = key[i];
      minIndex = i;
    }
  }
  return minIndex;
}

template<typename Type>
void PrimMST<Type>::mstPrim(Graph<Type> * g, int source){
  for(int i = 1; i <= g->getOrder(); i++){
    key[i] = INT_MAX;
    prevVertexArray[i] = 0;
    checkVertex[i] = false;
  }
  key[source] = 0;
  prevVertexArray[source] = 0;
  for(int i = 1; i <= g->getOrder(); i++){
    int u = extractMin(key, checkVertex);
    checkVertex[u] = true;
    for(int j = 1; j <= g->getOrder(); j++){
      if(checkVertex[j] == false && g->getMatrix()[u][j].getWeight() < key[j]){
        if(g->getMatrix()[u][j].getWeight() != 0){
          prevVertexArray[j] = u;
          key[j] = g->getMatrix()[u][j].getWeight();
        }
      }
    }
  }
}

template<typename Type>
void PrimMST<Type>::mstPrimMap(){
  cout << "<<PRIM (MST)>>\nPrevious Vertex Array = [ ";
  for(int i = 1 ; i <= g->getOrder(); i++)  cout << prevVertexArray[i] << " ";
  cout << "]" << endl;
  cout << "Key Array (weights) = [ ";
  for(int i = 1; i <= g->getOrder(); i++) cout << key[i] << " ";
  cout << "]" << endl;
}

#endif
