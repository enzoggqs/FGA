#include <stdio.h>
#include <stdlib.h>

int buscaBinaria (int *v, int l, int r, int val) {
  int i = (l+r)/2;
  if(v[i] == val) return i;
  if(v[i] < val){
    if(v[i+1] > val) return i+1;
    return buscaBinaria(v, i+1, r, val); 
  } else {
    if(v[i+1] < val) return i - 1;
    return buscaBinaria(v, l, i-1, val);
  }
}

int main(){
  int n, m;
  scanf("%d %d", &n, &m);

  int *v = malloc(sizeof(int) * n);

  for (int i = 0; i < n; i++){
    scanf("%d", &v[i]);
  }

  for(int i = 0; i < m; i++){
    int val;
    scanf("%d", &val);
    if(val > v[n-1]) printf("%d\n", n);

    if(val <= v[0]) printf("0\n");

    if(val <= v[n-1] && val > v[0]){
      int index = buscaBinaria(v, 0, n-1, val);

      printf("%d\n", index);
    }
  }

  return 0;
}