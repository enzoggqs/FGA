#include <stdio.h>
#include <string.h>

#define Key(A) (A.jpn)
#define less(A, B) (strcmp(Key(A), Key(B)) < 0)
#define exch(A,B) {Item t = A; A = B; B = A;}
#define cmpexch(A,B) {if(less(B,A)) exch(A,B);}

typedef struct Item
{
    char jpn[81];
    char ptbr[81];
} Item;

Item dicionario[1000000];

int busca(Item *v, int l, int r, char *x) {
    while(l <= r) {
        int k = (r - l) / 2 + l;

        if(strcmp(v[k].jpn, x) == 0) return k;

        if(strcmp(v[k].jpn, x) < 0) {
            l = k + 1;
        } else {
            r = k - 1;
        }
    }
    return -1;
}

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

void quicksort(Item *v, int l, int r){
  int j;
  if(r <= l) return;

  cmpexch(v[(l+r)/2], v[r]); 
  cmpexch(v[l], v[(l+r)/2]);
  cmpexch(v[r], v[(l+r)/2]);

  j = separa(v,l,r);
  quicksort(v,l,j-1);
  quicksort(v,j+1,r);
}

void traduz()
{
    int M, N;

    scanf("%d %d", &M, &N);

    for (int i = 0; i < M; i++)
    {
        scanf(" %s", dicionario[i].jpn);
        scanf(" %[^\n]", dicionario[i].ptbr);
    }

    quicksort(dicionario, 0, M - 1);

    for (int i = 0; i < N; i++)
    {
        char b[81], p;

        while (scanf(" %s%c", b, &p) == 1)
        {
            int j = busca(dicionario, 0, M - 1, b);

            if (j < 0)
                printf("%s", b);
            else
                printf("%s", dicionario[j].ptbr);

            printf("%c", p);

            if (p == '\n')
                break;
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        traduz();
        printf("\n");
    }

    return 0;
}