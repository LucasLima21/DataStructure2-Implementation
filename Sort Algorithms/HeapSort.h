#ifndef HeapSort_h
#define HeapSort_h
#include <iostream>
#include <math.h>
using namespace std;

int parent(int i){
  return floor(i/2);
}

int left(int i){
  return 2*i;
}

int right(int i){
  return 2*i+1;
}
template<typename Type>
void trade(Type & item1, Type & item2){
  Type aux = item1;
  item1 = item2;
  item2 = aux;
}

template <typename Type>
void heapfy(Type *& array, int EXTENT,int i){
  int l = left(i), r = right(i),maior = 1;
  if(l <= EXTENT && array[l] > array[i])  maior = l;
  else  maior = i;
  if(r<=EXTENT && array[r] > array[maior])  maior = r;
  if(maior != i){
    trade(array[i],array[maior]);
    heapfy(array,EXTENT,maior);
  }
}

template <typename Type>
void createHeap(Type *& array, int EXTENT, int & extentHeap){
  extentHeap = EXTENT - 1;
  for(int i = (floor(extentHeap/2)); i >= 1; i--) heapfy(array,extentHeap,i);
}

template <typename Type>
void heapSort(Type *& array,int EXTENT){
  int extentHeap = 0;
  createHeap(array,EXTENT,extentHeap);
  for(int i = EXTENT-1; i >= 2; i--){
    trade(array[i],array[1]);
    extentHeap--;
    heapfy(array,extentHeap,1);
  }
}

#endif
