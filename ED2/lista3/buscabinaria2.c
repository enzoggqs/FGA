#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Register{
  int value, id;
} Register;

void merge(Register *v, int l, int r1, int r2){
  Register *v2 = malloc(sizeof(Register) * (r2 - l + 1));
  int k = 0;
  int i = l;
  int j = r1 + 1;

  while (i <= r1 && j <= r2)
  {
    if (v[i].value < v[j].value)
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

void mergeSort(Register *v, int l, int r){
  if (l >= r)
    return;

  int meio = (l + r) / 2;

  mergeSort(v, l, meio);
  mergeSort(v, meio + 1, r);
  merge(v, l, meio, r);
}

int buscaBinaria(Register v[], int l, int r, int value){
  int i = (l + r) / 2;

  if (l > r)
    return -1;

  if (v[i].value == value)
    return i;

  if (v[i].value < value){
    return buscaBinaria(v, i + 1, r, value);
  } else {
    return buscaBinaria(v, l, i - 1, value);
  }
}

int main(){
  int n, m;

  scanf("%d %d", &n, &m);

  Register *v = malloc(n * sizeof(Register));

  for (int i = 0; i < n; i++){
    scanf("%d", &v[i].value);
    v[i].id = i;
  }

  mergeSort(v, 0, n - 1);

  for (int i = 0; i < m; i++){
    int val;
    scanf("%d", &val);  

    int index = buscaBinaria(v, 0, n - 1, val);

    if (index == -1)
      printf("-1\n");
    else
      printf("%d\n", v[index].id);
  }

  return 0;
}