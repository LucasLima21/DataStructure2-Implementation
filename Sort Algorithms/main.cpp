#include<iostream>
#include "HeapSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "ShellSort.h"
#include "CountingSort.h"
using namespace std;
int main(){
  const int EXTENT = 5;
  int * array = new int[EXTENT];
  int * arrayCounting = new int[EXTENT];
  int maxValue;
  array[0] = -1;
  for(int i = 1; i <= EXTENT; i++){
    cin >> array[i];
  }
  maxValue = array[1];
  for(int i = 1; i <= EXTENT; i++){
    if(maxValue <= array[i]){
      maxValue = array[i];
    }
  }

  // todos esses vetores preciso prrencher a posição inicial ! ela não conta. nao me pergunte o pq hehe jaja resolvo !!
  // quickSort(array,0,EXTENT);
  // mergeSort(array,1,EXTENT);
  heapSort(array,EXTENT+1);
  // shellSort(array,EXTENT+1);
  countingSort(array,arrayCounting,maxValue,EXTENT);

  // array counting
  for(int i = 1 ; i <= EXTENT; i++){
    cout << arrayCounting[i] << " ";
  }
  cout << endl;
  // array outras ordenações
  for(int i = 1 ; i <= EXTENT; i++){
    cout << array[i] << " ";
  }
  cout << endl;
  delete [] array;
  delete [] arrayCounting;
  return 0;
}
