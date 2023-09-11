#include <stdio.h>
#include <stdlib.h>

typedef struct Nota{
  long long int qtd;
} Nota;

int main() {
  long long int n, nota, maior, codMaior;
  maior = 0;
  codMaior = 0;

  scanf("%lld", &n);

  Nota arrNotas[10001];

  for( int i = 0; i < n; i++ ) {
    arrNotas[i].qtd = 0;
  }
  
  for(int i = 0; i < n; i++ ) {
    scanf( "%d", &nota);
    arrNotas[nota].qtd++;
    if(arrNotas[nota].qtd >= maior) {

      if(arrNotas[nota].qtd == maior) {
        if(nota > codMaior) {
          codMaior = nota;
        } else {
          codMaior = codMaior;
        }
      } else {
        codMaior = nota;
      }
      maior = arrNotas[nota].qtd;
    }
  }
  printf("%d\n", codMaior);
  return 0;
}