#ifndef ShellSort_h
#define ShellSort_h
#include <iostream>
using namespace std;

template <typename Type>
void trade1(Type & item1, Type & item2){
  Type aux = item1;
  item1 = item2;
  item2 = aux;
}

template <typename Type>
void shellSort(Type * array, int EXTENT){
  int h = 1;
  while(h < int(EXTENT/3))  h = 3*h+1;
  while(h>=1){
    for(int i = h; i < EXTENT; i++){
      int j = i;
      while( j>=h && array[j] < array[j-h]){
        trade1(array[j],array[j-h]);
        j-=h;
      }
    }
    h/=3;
  }
}

#endif
