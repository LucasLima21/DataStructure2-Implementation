#ifndef AdjacentList_h
#define AdjacentList_h
#include <iostream>
#include <limits.h>
using namespace std;

template <typename Type>
class Node{
private:
  Type item;
  Node<Type> * next;
public:
  Node();
  Node(Type);
  Type getItem();
  void setItem(Type);
  Node<Type> * getNext();
  void setNext(Node<Type> *);
};
template<typename Type>
Node<Type>::Node(){
  next = NULL;
}
template<typename Type>
Node<Type>::Node(Type item){
  this->item = item;
  next = NULL;
}
template<typename Type>
Node<Type> * Node<Type>::getNext(){
  return next;
}
template<typename Type>
void Node<Type>::setNext(Node<Type> * next){
  this->next = next;
}
template<typename Type>
Type Node<Type>::getItem(){
  return item;
}
template<typename Type>
void Node<Type>::setItem(Type item){
  this->item = item;
}

template<typename Type>
class LinkedList{
private:
  Node<Type> * first,*  last;
  int extentList;
public:
  LinkedList();
  Node<Type> * getFirst();
  void setPrim(Node<Type> *);
  Node<Type> * getLast();
  void setLast(Node<Type> *);
  int getExtentList();
  void setExtentList(int extentList);
  void insert(Type);
  Node<Type>* previous(Node<Type>*);
  bool emptyList();
  Node<Type>* search(Type);
  void remove(Node<Type>*);
  void destroy();
  void printList();
  Type minimum();
  Type extractMin();
  bool checkItemList(Type);
};
template<typename Type>
Node<Type> * LinkedList<Type>::getFirst(){
  return first;
}
template<typename Type>
void LinkedList<Type>::setPrim(Node<Type> * first){
  this->first = first;
}
template<typename Type>
Node<Type> * LinkedList<Type>::getLast(){
  return last;
}
template<typename Type>
void LinkedList<Type>::setLast(Node<Type> * last){
  this->last = last;
}
template<typename Type>
int LinkedList<Type>::getExtentList(){
  return extentList;
}
template<typename Type>
void LinkedList<Type>::setExtentList(int extentList){
  this->extentList = extentList;
}

template <typename Type>
bool LinkedList<Type>::checkItemList(Type item) {
  Node<Type> * aux = first->getNext();
  while(aux!= NULL){
    Type check = aux->getItem();
    if(check == item){
      return 1;
    }
    aux = aux->getNext();
  }
  return 0;

}
template <typename Type>
LinkedList<Type>::LinkedList() {
    first = new Node<Type>();
    first->setNext(NULL);
    last = first;
    extentList = 0;
}

template <typename Type>
void LinkedList<Type>::insert(Type x){
  last->setNext(new Node<Type>());
  last = last->getNext();
  last->setNext(NULL);
  last->setItem(x);
  extentList++;
}

template<typename Type>
Node<Type> * LinkedList<Type>::previous(Node<Type> * r){
    Node<Type>* p = first;
    while (p->getNext() != r) p = p->getNext();
    return p;
}

template<typename Type>
bool LinkedList<Type>::emptyList(){
  return first == last;
}

template<typename Type>
Node<Type> * LinkedList<Type>::search(Type x){
  Node<Type> * p = first->getNext();
  while(p != NULL && p->getItem() != x) p = p->getNext();
  return p;
}

template<typename Type>
void LinkedList<Type>::remove(Node<Type> * r){
  if(emptyList() || r == NULL || r == first)  cout << "Impossível Remover" << endl;
  else{
    Node<Type> * p = previous(r);
    p->setNext(r->getNext());
    if(p->getNext() == NULL) last = p;
    extentList--;
    delete r;
  }
}

template<typename Type>
void LinkedList<Type>::printList(){
  Node<Type> * p = first->getNext();
  while(p!=NULL){
    cout << " -> ["<< p->getItem().getIndex() << "]";
    p = p->getNext();
  }
  cout << endl;
}

template <typename Type>
void LinkedList<Type>::destroy(){
  Node<Type> * aux;
  aux = first;
  while(aux != NULL){
    delete aux;
    aux = aux->getNext();
  }
}


template<typename Type>
class DynamicQueue{
private:
  Node<Type> *front, *back;
public:
  DynamicQueue();
  Node<Type> * getFront();
  void setFront(Node<Type> * front);
  Node<Type> * getBack();
  void setBack(Node<Type> * back);
  bool emptyQueue();
  void enqueue(Type);
  void dequeue();
  void showQueue();
};
template<typename Type>
Node<Type> * DynamicQueue<Type>::getFront(){
  return front;
}
template<typename Type>
void DynamicQueue<Type>::setFront(Node<Type> * front){
  this->frete = front;
}
template<typename Type>
Node<Type> * DynamicQueue<Type>::getBack(){
  return back;
}
template<typename Type>
void DynamicQueue<Type>::setBack(Node<Type> * back){
  this->back = back;
}
template<typename Type>
bool DynamicQueue<Type>::emptyQueue(){
  return front == back;
}
template<typename Type>
DynamicQueue<Type>::DynamicQueue(){
  front = new Node<Type>();
  front->setNext(NULL);
  back = front;
}

template<typename Type>
void DynamicQueue <Type>::enqueue(Type x){
  back->setNext(new Node<Type>());
  back = back->getNext();
  back->setItem(x);
  back->setNext(NULL);
}

template<typename Type>
void DynamicQueue <Type>::dequeue(){
  Node<Type> * aux  = front;
  if(front!=back){
    front = front->getNext();
    delete aux;
  }else cout << "Fila Vazia" << endl;
}

template<typename Type>
void DynamicQueue <Type>::showQueue(){
  Node<Type> * i  =  front->getNext();
  while(i!=NULL){
    cout << i->getItem() << endl;
    i = i->getNext();
  }
}


template<typename Type>
class Vertex{
private:
  Type itemVertex;
  int index;
  int weight;
public:
  Vertex();
  Vertex(int,int);
  int getIndex();
  void setIndex(int index);
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
int Vertex<Type>::getIndex(){
  return index;
}
template<typename Type>
void Vertex<Type>::setIndex(int index){
  this->index = index;
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
Vertex<Type>::Vertex(int index, int weight){
  this->index = index;
  this->weight = weight;
}
template<typename Type>
Vertex<Type>::Vertex(){
  index = 0;
  weight = 0;
}


template <typename Type>
class Graph{
private:
  LinkedList<Vertex<Type>> * adjVertex;
  int order, extentGraph;
  void destroy();
public:
  Graph();
  Graph(int);
  LinkedList<Vertex<Type>> * getAdjVertex();
  void setAdjVertex(LinkedList<Vertex<Type>> * adjVertex);
  int getOrder();
  void setOrder(int order);
  int getExtentGraph();
  void setExtentGraph(int extentGraph);
  void insertEdge(int,int,int);
  void initialize(int);
  void printGraph();
  void destroyGraph();
  int weightUV(int u, int v);
};
template<typename Type>
LinkedList<Vertex<Type>> * Graph<Type>::getAdjVertex(){
  return adjVertex;
}
template<typename Type>
void Graph<Type>::setAdjVertex(LinkedList<Vertex<Type>> * adjVertex){
  this->adjVertex = adjVertex;
}
template<typename Type>
int Graph<Type>::getOrder(){
  return order;
}
template<typename Type>
void Graph<Type>::setOrder(int order){
  this->order = order;
}
template<typename Type>
int Graph<Type>::getExtentGraph(){
  return extentGraph;
}
template<typename Type>
void Graph<Type>::setExtentGraph(int extentGraph){
  this->extentGraph = extentGraph;
}

template<typename Type>
Graph<Type>::Graph(){
  setOrder(0);
  extentGraph = 0;
  initialize(order);
}
template <typename Type>
Graph<Type>::Graph(int order){
  this->order = 0;
  extentGraph = 0;
  initialize(order);
}

template <typename Type>
void Graph<Type>::initialize(int order){
  if(this->order != 0)  destroyGraph();
  this->order = order;
  adjVertex = new LinkedList<Vertex<Type>>[order+1];
}

template <typename Type>
void Graph<Type>::insertEdge(int u, int v, int w){
  Vertex<Type> vertex(v,w);
  adjVertex[u].insert(vertex);
  vertex.setIndex(u);
  vertex.setWeight(w);
  adjVertex[v].insert(vertex);
  extentGraph++;
}

template <typename Type>
void Graph<Type>::printGraph(){
  cout << "<<Adjacent List>>" << endl;
  for(int i = 1; i<= getOrder(); i++){
    cout << "Vertex[" << i << "]" ;
    adjVertex[i].printList();
  }
}

template <typename Type>
void Graph<Type>::destroyGraph(){
  for(int i = 0 ; i <= getOrder(); i++){
    adjVertex[i].destroy();
  }
  delete [] adjVertex;
  order = 0;
  extentGraph = 0;
}

template<typename Type>
int Graph<Type>::weightUV(int u, int v){
    for(int i=1; i<=getOrder(); i++){
        if(i==u){
            Node<Vertex<Type>> * p = adjVertex[i].getFirst()->getNext();
            while(p!=NULL){
                if(p->getItem().getIndex()==v){
                    return p->getItem().getWeight();
                }
                p = p->getNext();
            }
        }
    }
    return INT_MAX;
}

#endif
