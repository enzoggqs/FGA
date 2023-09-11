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

void merge(int *v, int l, int r1, int r2){
  int *v2 = malloc(sizeof(int) * (r2 - l + 1));
  int k = 0;
  int i = l;
  int j = r1 + 1;

  while(i <= r1 && j <= r2){
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
  for(i = l; i <= r2; i++)
    v[i] = v2[k++];
  
  free(v2);
}

void mergeSort(int *v, int l, int r){
  if(l >= r)
    return;
  
  int meio = (l + r) / 2;
  
  mergeSort(v, l, meio);
  mergeSort(v, meio + 1, r);
  merge(v, l, meio, r);
}

int main(){
  int proibidos[140000];
  int proibidos_ct;
  int tam = 0, x;
  scanf("%d", &proibidos_ct);
  for(int i = 0; i < proibidos_ct; i++){
    scanf("%d", &proibidos[i]);
    tam++;
  }

  mergeSort(proibidos, 0, tam-1);

  while(scanf("%d", &x) != EOF){
    int idx = buscaBinaria(proibidos, 0, tam, x);
    if(idx == -1)
      printf("nao\n");
    else
      printf("sim\n");
  }

  return 0;
}