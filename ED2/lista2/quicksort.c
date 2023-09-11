#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { Item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

void quicksort(Item *V,int l, int r)
{
  if (r<=l) return;
  int j=separa(V,l,r);
  quicksort(V,l,j-1);
  quicksort(V,j+1,r);
}

int separaCORMEM(Item *V,int l,int r)
{
  Item c=V[r];
  int j=l;
  for(int k=l;k<r;k++)
    if(less(V[k],c))
    {
      exch(V[k],V[j]);
      j++;
    }
  exch(V[j],V[r]);
  return j;
}

int main(){
  int *vet = malloc(sizeof(int));
  int val;
  int tam = 1;

  while(scanf("%d", &val) != EOF){
    vet = realloc(vet, tam * sizeof(int));
    vet[tam - 1] = val;
    tam++;
  }

  return 0;
} 