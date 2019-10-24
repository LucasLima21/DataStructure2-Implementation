#ifndef MergeSort_h
#define MergeSort_h
#include <iostream>
#include <limits.h>
using namespace std;

template <typename Type>
void merge(Type * array,int p,int q,int r){
  int extent1 = q-p+1, extent2 = r-q;
  Type * left, *right;
  left = new Type[extent1+2];
  right = new Type[extent2+2];
  for(int i = 1; i <= extent1; i++)  left[i] = array[p+i-1];
  for(int i = 1; i <= extent2; i++) right[i] = array[q+i];
  left[extent1+1] = INT_MAX;
  right[extent2+1] = INT_MAX;
  int i = 1, j = 1;
  for(int k = p; k <= r; k++){
    if(left[i] <= right[j]) {
      array[k] = left[i];
      i++;
    }
    else{
      array[k] = right[j];
      j++;
    }
  }
}

template <typename Type>
void mergeSort(Type * array, int p, int r){
  if(p<r){
    int q = (int)((p+r)/2);
      mergeSort(array,p,q);
      mergeSort(array,q+1,r);
      merge(array,p,q,r);
  }
}
#endif
