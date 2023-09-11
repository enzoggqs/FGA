#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *v, int size){
  for(int i = 0; i < size; i++){
    int min = i;
    for(int j = i; j < size; j++){
      if(v[j] < v[min]){
        min = j;
      }
    }

    int aux = v[i];
    v[i] = v[min];
    v[min] = aux;
  }
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

  selectionSort(vet, tam - 1);

  for(int i=0; i<tam-1; i++){
    if (i == tam - 2){
      printf("%d\n", vet[i]);
      break;
    }
    printf("%d ", vet[i]);
  }

  return 0;
}