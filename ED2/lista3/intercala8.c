#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int *v, int l, int r1, int r2){
  int *v2 = malloc(sizeof(int) * (r2 - l + 1));
  int k = 0;
  int i = l;
  int j = r1 + 1;

  while (i <= r1 && j <= r2){
    if (v[i] < v[j])
      v2[k++] = v[i++];
    else
      v2[k++] = v[j++];
  }

  while (i <= r1)
    v2[k++] = v[i++];

  while (j <= r2)
    v2[k++] = v[j++];

  k = 0;
  for (i = l; i <= r2; i++)
    v[i] = v2[k++];

  free(v2);
}

void mergeSort(int *v, int l, int r){
  if (l >= r)
    return;

  int middle = (l + r) / 2;

  mergeSort(v, l, middle);
  mergeSort(v, middle + 1, r);
  merge(v, l, middle, r);
}

int main(){
  int *v = malloc(sizeof(int));
  int tam = 0, n;

  for (int j = 8; j >= 1; j--){
    scanf("%d", &n);

    if (n != 0){
      v = realloc(v, sizeof(int) * (tam + n));

      for (int i = 0; i < n; i++){
        scanf("%d", &v[tam + i]);
        }
    }

    tam += n;
  }

  mergeSort(v, 0, tam - 1);

  for (int i = 0; i < tam; i++){
    printf("%d ", v[i]);
  }

  printf("\n");

  return 0;
}