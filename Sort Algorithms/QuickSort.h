#ifndef QuickSort_h
#define QuickSort_h
#include <iostream>
using namespace std;

template <typename Type>
int partition(Type * array, int p, int r){
  Type x = array[p], temp = array[r+1];
  array[r+1] = x;
  int i,j;
  i = p;
  j = r+1;
  while(true){
      do{
        i++;
      }while(array[i] < x);
      do{
        j--;
      }while(array[j] > x);
      if(i<j){
        Type t = array[i];
        array[i] = array[j];
        array[j] = t;
      }
      else{
        Type u = array[p];
        array[p] = array[j];
        array[j] = u;
        array[r+1] = temp;
        break;
      }
  }
  return j;
}

template <typename Type>
void quickSort(Type * array, int p, int r){
  int q;
  if(p < r){
    q = partition(array,p,r);
    quickSort(array,p,q-1);
    quickSort(array,q+1,r);
  }
}

#endif
