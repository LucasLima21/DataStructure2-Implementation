#include <iostream>
#include "AdjacentMatrix.h"
#include "PrimAlgorithm.h"
#include "KruskalAlgorithm.h"
#include "DijkstraAlgorithm.h"
using namespace std;

int main(){
  Graph<int> * g = new Graph<int>(4);
  
  g->insertEdge(1, 2, 1);
  g->insertEdge(1, 3, 3);
  g->insertEdge(1, 4, 7);
  g->insertEdge(2, 3, 1);
  g->insertEdge(3, 4, 2);
  g->printGraph();


  cout << endl;
  PrimMST<int> * p = new PrimMST<int>(g,1);
  p->mstPrimMap();

  cout << endl;
  KruskalMST<int> * k = new KruskalMST<int>(g);

  cout << endl;
  Dijkstra<int> * d = new Dijkstra<int>(g,1);
  d->dijkstraMap();

  g->destroyGraph();
  delete g;
  delete p;
  delete k;
  delete d;
  return 0;
}
