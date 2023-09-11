#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { Item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

void insertionsortslow(Item *v,int l,int r)
{
  for(int i=l+1;i<r;i++){
    for(int j=i;j>l;j--){
      cmpexch(v[j-1],v[j]);
    }
  }
}

int main(){
  int vet[1000];
  int val;
  int tam = 0;

  while(scanf("%d", &val) != EOF){
    vet[tam] = val;
    tam++;
  }

  insertionsortslow(vet, 0, tam);

  for(int i=0; i<tam; i++){
    if (i == tam - 1){
      printf("%d\n", vet[i]);
      break;
    }
    printf("%d ", vet[i]);
  }

  return 0;
}