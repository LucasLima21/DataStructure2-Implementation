#ifndef SelectionSort_h
#define SelectionSort_h
#include <iostream>
using namespace std;

template <typename Type>
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

template <typename Type>
Type * selectionSort(Type * array){
  int min;
  for(int i = 0; i < array.size(); i++){
    min = i;
    for(int j = i + 1; j < array.size(); j++){
      if(array[j] < array[min]){
        min = j;
      }
    }
    Type aux = array[i];
    array[i] = array[min];
    array[min] = aux;
  }
  return array;
}
#endif
