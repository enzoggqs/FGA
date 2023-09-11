#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { Item t; t=A;A=B;B=t; }
#define exchstr(A,B) { char *t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

void insertionsort(Item *v, char **w, int l,int r)
{
  for(int i = r - 1; i > l; i--){
    if(less(v[i], v[i - 1])){
      exch(v[i], v[i - 1]);
      exchstr(w[i], w[i - 1]);
    }
  }

  for(int i = l+2; i < r; i++){
    int j = i;
    Item tmp = v[j];
    char *aux = w[j];
    while(less(tmp, v[j-1])){
      v[j] = v[j-1];
      w[j] = w[j-1];
      j--;
    }
    v[j] = tmp;
    w[j] = aux;
  }
}

int buscaBinaria (int x, int n, int v[]) { 
   int ini = 0;
   int fim = n - 1;
   int meio;

   while( ini <= fim){
    meio = (ini + fim)/2;
    if(n < v[meio]){
      fim = meio - 1;
    }
    else if(n > v[meio]){
      ini = meio + 1;
    }
    else{
      return meio;
    }
   }

   return -1;
}

int main(){
  int n;
  scanf("%d", &n);

  int codigos[n];
  char **funcoes = malloc(n * sizeof(char*));

  for(int i = 0; i < n; i++){
    scanf("%d", &codigos[i]);
    scanf("%s", funcoes[i]);
  }

  int *v = malloc(sizeof(int));
  int val, tam = 0;

  // while(scanf("%d", &val) != EOF){
  //   v = realloc(v, (tam + 1) * sizeof(int));
  //   v[tam] = val;
  //   tam++;
  // }

  for(int i = 0; i < 10; i++){
    int value;
    scanf("%d ", value);
    v = realloc(v, (tam + 1) * sizeof(int));
    v[i] = value;
  }
  // for(int i = 0; i < 10; i++){
  //   scanf("%d", &codigos[i]);
  //   scanf("%s", funcoes[i]);
  // }

  insertionsort(codigos, funcoes, 0, n);

  for(int i=0; i<tam; i++){
    buscaBinaria(v[])
  }

  return 0;
}