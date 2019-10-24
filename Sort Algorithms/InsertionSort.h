#ifndef InsertionSort_h
#define InsertionSort_h
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
Type * insertionSort(Type * array){
  int j = 0;
  for(int i = 1; i < array.size(); i++){
    Type x = array[i];
    j = i - 1;
    array[0] = x;
    while(x < array[j]){
      array[j+1] = array[j];
      j--;
    }
    array[j+1] = x;
  }
}

#endif
