#ifndef CountingSort_h
#define CountingSort_h
using namespace std;
template<typename Type>
void countingSort(Type * array1, Type *& array2, Type key, int extent){
  Type * array3 = new Type[key+1];
  for(int i = 0; i <= key; i++)  array3[i] = 0;
  for(int i = 1 ; i <= extent; i++)  array3[array1[i]]++;
  for(int i = 0 ; i <= key; i++)  array3[i]+=array3[i-1];
  for(int i = extent; i >= 0; i--){
    array2[array3[array1[i]]] = array1[i];
    array3[array1[i]]--;
  }
}

#endif
