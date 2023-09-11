#include <stdio.h>
#include <stdlib.h>

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

void quickSelect(int *v, int p, int l, int r){
  int j = separa(v,l,r);
  if(j == p) return;

  if(j < p) quickSelect(v, p, j+1, r);
  else quickSelect(v, p, l, j-1);
}