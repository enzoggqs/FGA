#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { Item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

// Ordena um vetor por posição, ou seja coloca o menor na primeira posição, o segundo menor na segunda, etc.

void selectionSort(Item *v,int l,int r)
{
  if(l>=r) return;

  int min=l;
  for(int j=l+1;j<=r;j++)
    if(less(v[j],v[min]))
      min=j;
  exch(v[l],v[min]);
  selectionSort(v,l+1,r);
}

int main(){
  Item vetor[100000];
  for(int i = 0; i < 100000; i++) vetor[i] = rand() % 100000;

  selectionSort(vetor, 0, 99999);
  
  return 0;
}