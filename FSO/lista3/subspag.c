#include <stdio.h>
#include <stdlib.h>

int main(void){
  int n, q, aux, isBelady = 0, maxPgF = 0, minPgs = 0;
  scanf("%d", &n);
  
  int *vet1 = malloc(n*sizeof(int));

  for(int i = 0; i < n; i++){
    scanf("%d", &aux);
    vet1[i] = aux;
  }

  while(scanf("%d", &q) != EOF){
    int *vet2 = malloc(sizeof(int) * q);
    int currentOut = 0;
    int totalPgF = 0;

    for(int i = 0; i < n; i++){
      int has = 0, pos;
      for(int j = 0; j < q; j++){
        if(vet1[i] == vet2[j]){
          has = 1;
          pos = j;
          break;
        }
      }
      if(has == 0){
        if(currentOut < q){
          vet2[currentOut] = vet1[i];
          totalPgF++;
          currentOut++;
        } else if (currentOut == q){
          currentOut = 0;
          vet2[currentOut] = vet1[i];
          currentOut++;
          totalPgF++;
        }
      }
    }
    printf("%d %d\n", q, totalPgF);

    if(maxPgF == 0){
      maxPgF = totalPgF;
      minPgs = q;
    } else {
      int hasMorePgF = totalPgF > maxPgF;
      if(hasMorePgF && q > minPgs){
        isBelady = 1;
      }
    }
  }

  if (isBelady)
        printf("Belady detectado\n");
    else
        printf("Sem anomalia\n");

  return 0;
}