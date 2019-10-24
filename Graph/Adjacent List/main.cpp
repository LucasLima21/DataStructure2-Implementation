
#include<iostream>
#include "AdjacentList.h"
#include "MinimumSpaningTree.h"
#include "BreadthFirstSearch.h"
#include "DepthFirstSearch.h"
using namespace std;

int main(){
  Graph<int> * g = new Graph<int>(5);
  g->insertEdge(1, 2,4);
  g->insertEdge(2, 3,5);
  g->insertEdge(3, 4,3);
  g->insertEdge(4, 5,6);
  g->insertEdge(5, 1,7);
  g->insertEdge(5, 2,2);
  g->insertEdge(2, 4,1);


  g->printGraph();
  cout << g->getOrder() << " " << g->getExtentGraph() << endl;
  cout << endl;

  DFS<int> * d = new DFS<int>(5);

  d->dfs(g);
  d->dfsMap(g);
  cout << endl;

  cout << "After TopologicalSort" << endl;
  d->topologicalSort(g);
  cout << endl;

  cout << "Discovery time consumed" << endl;
  d->dfsMap(g);


  cout << endl;
  BFS<int> * b = new BFS<int>(5);
  b->bfs(g,1);
  b->bfsMap(g);

  cout << endl;
  MST<int> * m = new MST<int>(5);
  m->mstPrim(g,1);

  m->mstMap(g);


  g->destroyGraph();
  delete g;
  delete m;
  delete d;
  delete b;
  return 0;
}
