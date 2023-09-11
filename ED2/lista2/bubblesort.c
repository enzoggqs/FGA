#include <stdio.h>
#include <stdlib.h>

void bubblesort(int *vet, int size){
  int aux;

  for (int i = 0; i < size; i++){
    for (int j = 0; j < size - 1; j++){
      if (vet[i] < vet[j]){
        aux = vet[j];
        vet[j] = vet[i];
        vet[i] = aux;
      }
    }
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

  bubblesort(vet, tam - 1);

  for(int i=0; i<tam-1; i++){
    if (i == tam - 2){
      printf("%d\n", vet[i]);
      break;
    }
    printf("%d ", vet[i]);
  }

  return 0;
}