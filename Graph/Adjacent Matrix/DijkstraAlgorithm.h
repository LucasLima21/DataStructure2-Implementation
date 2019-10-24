#ifndef DijkstraAlgorithm_h
#define DijkstraAlgorithm_h
#include <iostream>
#include <limits.h>
#include <math.h>
using namespace std;

template<typename Type>
class Dijkstra{
private:
    Graph<Type> * g;
    int * key, * prevVertexArray, * distanceToSource;
    bool * checkVertex;
    int extractMin(int *, bool *);
    void dijkstra(Graph<Type> *, int);
public:
    Dijkstra(Graph<Type> *, int);
    void dijkstraMap();
};

template<typename Type>
Dijkstra<Type>::Dijkstra(Graph<Type> * g, int source){
    this->g = g;
    key = new int[g->getOrder()+1];
    prevVertexArray = new int[g->getOrder()+1];
    distanceToSource = new int[g->getOrder()+1];
    checkVertex = new bool[g->getOrder()+1];
    dijkstra(g,source);
}

template<typename Type>
int Dijkstra<Type>::extractMin(int * distanceToSource, bool * checkVertex){
    int min = INT_MAX, minIndex;
    for(int i = 1; i <= g->getOrder(); i++){
        if(checkVertex[i] == false && distanceToSource[i] < min){
        min = distanceToSource[i];
        minIndex = i;
        }
    }
    return minIndex;
}

template<typename Type>
void Dijkstra<Type>::dijkstra(Graph<Type> *g, int source){
    for(int i = 1; i<= g->getOrder(); i++){
        distanceToSource[i] = INT_MAX, checkVertex[i] = false;
    }
    distanceToSource[source] = 0;
    for(int i = 1; i<= g->getOrder(); i++){
        int u = extractMin(distanceToSource,checkVertex);
        checkVertex[u] = true;
        for(int j = 1; j <= g->getOrder(); j++){
            if(checkVertex[j] == false && distanceToSource[u] != INT_MAX){
                if(distanceToSource[u] + g->getMatrix()[u][j].getWeight() < distanceToSource[j]){
                    if(g->getMatrix()[u][j].getWeight() != 0){
                        distanceToSource[j] = distanceToSource[u] + g->getMatrix()[u][j].getWeight();
                        prevVertexArray[j] = u;
                        key[j] = g->getMatrix()[u][j].getWeight();
                    }
                }
            } 
        }
    }
}

template<typename Type>
void Dijkstra<Type>::dijkstraMap(){
  cout << "<<DIJKSTRA (ShortestWay)>>\nPrevious Vertex Array = [ ";
  for(int i = 1 ; i <= g->getOrder(); i++)  cout << prevVertexArray[i] << " ";
  cout << "]" << endl;
  cout << "Distance from Source = [ ";
  for(int i =1; i <= g->getOrder(); i++)  cout << distanceToSource[i] << " ";
  cout << "]" << endl;
  cout << "Key Array (weights) = [ ";
  for(int i = 1; i <= g->getOrder(); i++) cout << key[i] << " ";
  cout << "]" << endl;
}
#endif
