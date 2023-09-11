#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, key, maiorKey, posMaior;
  n = 1;

  for(;;) {
    scanf("%d", &n);
    if(n == 0) break;
    
    int *v;
    v = calloc(n, sizeof(int) * n);

    maiorKey = 0;
    posMaior = 0;

    for(int i = 0; i < n; i++) {
      scanf("%d", &key);

      v[key]++;

      if(maiorKey < v[key]) {
        maiorKey = v[key];
        posMaior = key;
      }
    }
    
    printf("%d\n", posMaior);
    
    free(v);
  }

  return 0;
}