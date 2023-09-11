#include <stdio.h>
#include <stdlib.h>

#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { int t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

int separa(int *v, int l, int r){
  int c = v[r];
  int j = l;
  for(int k = l; k < r; k++){
    if(v[k] < c){
      int aux = v[j];
      v[j] = v[k];
      v[k] = aux;
      j++;
    }
  }
  int aux = v[j];
  v[j] = v[r];
  v[r] = aux;
  return j;
}

void quicksort(int *v, int l, int r){
  int j;
  if(r <= l) return;

  cmpexch(v[(l+r)/2], v[r]); 
  cmpexch(v[l], v[(l+r)/2]);
  cmpexch(v[r], v[(l+r)/2]);

  j = separa(v,l,r);
  quicksort(v,l,j-1);
  quicksort(v,j+1,r);
}

int main(){
  int n;
  scanf("%d", &n);

  int *v = (int*)malloc(n*sizeof(int));
  for(int i = 0; i < n; i++){
    scanf("%d", &v[i]);
  }

  quicksort(v, 0, n-1);
  for(int i = 0; i < n; i++){
    printf("%d ", v[i]);
  }
  printf("\n");
  free(v);
  return 0;
}