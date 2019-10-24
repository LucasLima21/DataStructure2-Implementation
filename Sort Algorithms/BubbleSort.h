#ifndef BubbleSort_h
#define BubbleSort_h
#include <iostream>
using namespace std;
template<typename Type>
bool checkSorted(Type * array){
  Type * pointer;
  pointer = array;
  int sentinel = 0;
  while(pointer != NULL){
    if(array[pointer] > array[pointer+1]){
      sentinel = 1;
    }
  }
  return ((sentinel == 1)? false : true);
}

template<typename Type, typename U>
Type * bubbleSort(Type * array){
  for(int i = array.size() - 1, i >= 0; i++){
    for(int j = 0; j < i ; j++){
      if(array[j] > array[j+1]){
        Type aux = array[j];
        array[j] = array[j+1];
        array[j+1] = aux;
      }
    }
  }
  return array;
}
#endif
