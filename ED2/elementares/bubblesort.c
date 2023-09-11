#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { Item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

void bubblesort(Item *v, int l, int r){
  for(int i = 0; i < r; i++){
    for(int j = l; j < r; j++){
      cmpexch(v[j], v[j+1]);
    }   
  }
}

int main(){
  Item vetor[10000];
  for(int i = 0; i < 10000; i++) vetor[i] = rand() % 10000;

  bubblesort(vetor, 0, 9999);
  
  for(int i = 0; i < 10000; i++) printf("%d ", vetor[i]);

  return 0;
}