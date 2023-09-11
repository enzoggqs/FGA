#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  int t;
  int *b = NULL;
  int instancia = 1;

  while(scanf("%d", &t) != EOF){
    if(!b){
      b = malloc(sizeof(int) * t);
    } else {
      b = realloc(b, sizeof(int) * t);
    }
    char arr[t][20];

    for(int i =0; i < t; i++){
      scanf("%s", arr[i]);
      scanf("%d", &b[i]);
    }

    int menor = b[0];
    int menorIndex = 0;

    for(int j = 0; j < t; j++){
      if(b[j] < menor){
        menor = b[j];
        menorIndex = j;
      } else if(b[j] == menor){
        if(strcmp(arr[j], arr[menorIndex]) > 0){
          menor = b[j];
          menorIndex = j;
        }
      }
    }

    printf("Instancia %d\n", instancia);
    printf("%s\n", arr[menorIndex]);

    instancia++;
  }

  return 0;
}