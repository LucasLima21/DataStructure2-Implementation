#include<iostream>
#include "CountingSort.h"
#define MAX 5
using namespace std;

int main(){
  int * u = new int[7];

  int v[] = {-1,2,5,3,0,2,3,0,3};

  countingSort(v,u,MAX,8);

  for(int i = 1 ; i <= 8; i ++){
    cout << u[i] << " ";
  }
  cout << endl;

  return 0;
}
