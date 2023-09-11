#include <stdio.h>
#include <stdlib.h>

#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { int t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

int separa(int *v, int l, int r){
  int c = v[r];
  int j = l;
  for(int k = l; k < r; k++){
    if(v[k] < c){
      int aux = v[j];
      v[j] = v[k];
      v[k] = aux;
      j++;
    }
  }
  int aux = v[j];
  v[j] = v[r];
  v[r] = aux;
  return j;
}

void quicksort(int *v, int l, int r){
  int j;
  if(r <= l) return;

  cmpexch(v[(l+r)/2], v[r]); 
  cmpexch(v[l], v[(l+r)/2]);
  cmpexch(v[r], v[(l+r)/2]);

  j = separa(v,l,r);
  quicksort(v,l,j-1);
  quicksort(v,j+1,r);
}

void quickselect(int *v, int l, int r, int k)
{
    int i;
    if (r <= l)
        return;
    i = separa(v, l, r);
    if (i > k)
        quickselect(v, l, i - 1, k);
    if (i < k)
        quickselect(v, i + 1, r, k);
}

void quickSelect(int *v, int p, int l, int r){
  int j = separa(v,l,r);
  if(j == p) return;

  if(j < p) quickSelect(v, p, j+1, r);
  else quickSelect(v, p, l, j-1);
}

int main() {
  int n, p, x;

  scanf("%d", &n);
  int *v = malloc(n * sizeof(int));

  scanf("%d %d", &p, &x);

  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  
  int j = p * x;
  quickselect(v, 0, n - 1, j);
  quicksort(v, j, n - 1);

  for (int i = 0; i < x && j < n; i++)
  {
      printf("%d\n", v[j++]);
  }

  return 0;
}