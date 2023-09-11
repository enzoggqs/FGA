#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(int *v, int l, int r, int val) {
  int i = (l + r) / 2;

  if (l > r)
    return -1;

  if(v[i] == val) return i;

  if(v[i] < val){
    return buscaBinaria(v, i+1, r, val); 
  } else {
    return buscaBinaria(v, l, i-1, val);
  }
}