#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { Item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

int merge(Item *v, int l, int r1, int r2){
  Item *v2 = malloc(sizeof(Item) * (r2-l+1));
  
  int k = 0;
  int i = l;
  int j = r1+1;
  while(i <= r1 && j<= r2){
    if(v[i] < v[j])
      v2[k++] = v[i++];
    else
      v2[k++] = v[j++];
  }

  while(i <= r1)
    v2[k++] = v[i++];
  while(j <= r2)
    v2[k++] = v[j++];

  k = 0;
  for(int i = l; i <= r2; i++)
    v[i] = v2[k++];

  free(v2);
}

void mergeSort(Item *v, int l, int r){
  if(l>=r) return;
  int meio = (l+r)/2;
  mergeSort(v,l,meio);
  mergeSort(v,meio+1,r);
  merge(v, l, meio, r);
}

int main(){
  Item vetor[100000];
  for(int i = 0; i < 100000; i++) vetor[i] = rand() % 100000;

  mergeSort(vetor, 0, 99999);
  
  return 0;
}