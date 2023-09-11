#include <stdio.h>
#include <stdlib.h>

struct ht_st {
  int *b;
  int b_count;
};

void htinsert(struct ht_st *ht, int n, int pos){
  if(ht[n].b == NULL){
    ht[n].b = malloc(sizeof(int) * 1);
    ht[n].b[0] = 1;
    ht[n].b_count = 1;
  } else {
    ht[n].b = realloc(ht[n].b, sizeof(int) * (ht[n].b_count + 1));
    ht[n].b[ht[n].b_count] = pos;
    ht[n].b_count++;
  }
}

int htsearch(struct ht_st *ht, int k, int ni){
  if(ht[ni].b_count < k)
    return 0;
  return ht[ni].b[k-1];
}

int main(void){
  int n, m;
  scanf("%d %d", &n, &m);
  struct ht_st *ht = malloc(1000001 * sizeof(struct ht_st));

  for(int i = 0; i <= 1000000; i++){
    ht[i].b = NULL;
    ht[i].b_count = 0;
  }

  for(int i = 0; i < n; i++){
    int n;
    scanf("%d", &n);
    htinsert(ht, n, i);
  }

  for(int i = 0; i < m; i++){
    int k, n;
    scanf("%d %d", &k, &n);
    printf("%d\n", htsearch(ht, k, n));
  }

  return 0;
}