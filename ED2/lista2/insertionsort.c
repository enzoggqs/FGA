#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { Item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

void insertionsort(Item *v,int l,int r)
{
  for(int i = r - 1; i > l; i--){
    cmpexch(v[i-1], v[i]);  
  }

  for(int i = l+2; i < r; i++){
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
  int vet[50000];
  int val;
  int tam = 0;

  while(scanf("%d", &val) != EOF){
    vet[tam] = val;
    tam++;
  }

  insertionsort(vet, 0, tam);

  for(int i=0; i<tam; i++){
    if (i == tam - 1){
      printf("%d\n", vet[i]);
      break;
    }
    printf("%d ", vet[i]);
  }

  return 0;
}