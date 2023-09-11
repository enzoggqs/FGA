#include <stdio.h>
#include <stdlib.h>

#define less(A,B) (A < B)
#define eq(A,B) (A == B)
#define lesseq(A,B) (A <= B)

typedef struct Item{
  int qtd;
  int cod;
} Item;

Item resultado[1000];

void merge(Item *v, int l, int m, int r) {
  int l1 = l;
  int l2 = m + 1;

  Item *aux = malloc(sizeof(Item) * (r - l + 1));

  int ci = 0, rc = r - l;

  while(l1 <= m && l2 <= r) {
    int diff;
    if(eq(v[l1].qtd, v[l2].qtd)){
      diff =lesseq(v[l1].cod, v[l2].cod);
    } else {
      diff =lesseq(v[l1].qtd, v[l2].qtd);
    }
    if(diff) {
      aux[ci++] = v[l1++];
    } else {
      aux[ci++] = v[l2++];
    }
  }

  while(l1 <= m) {
    aux[ci++] = v[l1++];
  }

  while(l2 <= r) {
    aux[ci++] = v[l2++];
  }
  l1 = l;

  for(ci = 0; ci <= rc; ci++) {
    v[l1++] = aux[ci];
  }

  free(aux);
}

void mergeSort(Item *v, int l, int r){
  if(l >= r) return;
  
  int meio = (l+r)/2;
  mergeSort(v, l, meio);
  mergeSort(v, meio+1, r);
  merge(v, l, meio, r);
}

void start(Item *v) {
  for(int i = 0; i < 1000; i++) {
    v[i].qtd = 0;
  }
}

int main() {
  
  char palavra[1001];

  while(scanf(" %s", palavra) == 1) {
    int indexSequencia = 0, contaSequencia = 0, index = 0, indexResultado = 0;
    start(resultado);

    while(palavra[index] != '\0') {
      int chave = palavra[index];
      resultado[chave].cod = palavra[index];
      resultado[chave].qtd++;

      index++;
    }
    mergeSort(resultado, 0, 1000 - 1);

    for(int i = 0; i < 1000; i++) {
      if(resultado[i].qtd) {
        printf("%d %d\n", resultado[i].cod, resultado[i].qtd);
      }
    }
    printf("\n");
  }

  return 0;
}