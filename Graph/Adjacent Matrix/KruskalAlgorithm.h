#ifndef KruskalAlgorithm_h
#define KruskalAlgorithm_h
#include <iostream>
using namespace std;
template<typename Type>
class KruskalMST{
private:
  Graph<Type> * g;
  int * key, * prevVertexArray;
  int find(int);
  void unionFind(int, int);
  void mstKruskal(Graph<Type> *);
public:
  KruskalMST(Graph<Type> *);
};

template<typename Type>
KruskalMST<Type>::KruskalMST(Graph<Type> * g){
  this->g = g;
  key = new int[g->getOrder()+1];
  prevVertexArray = new int[g->getOrder()+1];
  mstKruskal(g);
}

template<typename Type>
int KruskalMST<Type>::find(int position){
  while(prevVertexArray[position] != position){
    position = prevVertexArray[position];
  }
  return position;
}

template<typename Type>
void KruskalMST<Type>::unionFind(int i, int j){
  int aux1 = find(i);
  int aux2 = find(j);
  prevVertexArray[aux1] = aux2;
}

template<typename Type>
void KruskalMST<Type>::mstKruskal(Graph<Type> * g){
  for(int i = 1; i <= g->getOrder(); i++) prevVertexArray[i] = i;
  int countEdges = 1;
  cout << "<<KRUSKAL (MST)>>" << endl;
  while(countEdges < g->getOrder()){
    int min = INT_MAX, aux1 = 0, aux2 = 0;
    for(int i = 1; i <= g->getOrder(); i++){
      for(int j = 1; j <= g->getOrder(); j++){
        if(find(i) != find(j) && g->getMatrix()[i][j].getWeight() < min){
          if(g->getMatrix()[i][j].getWeight() != 0){
            min = g->getMatrix()[i][j].getWeight();
            aux1 = i;
            aux2 = j;
          }
        }
      }
    }
    cout << aux1 << " " << " "<< aux2 << " - " << min << endl;
    unionFind(aux1,aux2);
    countEdges++;
  }
}


#endif
