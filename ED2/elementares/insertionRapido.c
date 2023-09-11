#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { Item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

// Vai ordenando o array conforme vai sendo passado sua chave pelo algoritmo.

void insertionSort(Item *v, int l, int r){
  for(int i = r; i > l; i--){
    cmpexch(v[i-1], v[i]);
  }

  for(int i = l + 2; i <= r; i++){
    int j = i; 
    Item tmp = v[j];
    while(less(tmp, v[j-1])){
      v[j] = v[j-1];
      j--;
    }
    v[j] = tmp;
  }
}

int main(){
  Item vetor[10000];
  for(int i = 0; i < 10000; i++) vetor[i] = rand() % 10000;

  insertionSort(vetor, 0, 9999);
  
  for(int i = 0; i < 10000; i++) printf("%d ", vetor[i]);
  return 0;
}