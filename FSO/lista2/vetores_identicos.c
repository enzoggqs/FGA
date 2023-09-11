#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int v1[10000000], v2[10000000], n;

int compara(int *v1, int *v2, int n);
int comparador (const void * p1, const void * p2);
void *thread1_calc(void *a);
void *thread2_calc(void *a);

int main() {

  pthread_t tid1, tid2;

  scanf("%d", &n);

  for(int i = 0; i < n; i++) scanf(" %d", &v1[i]);
  for(int i = 0; i < n; i++) scanf(" %d", &v2[i]);

  pthread_create(&tid1, NULL, &thread1_calc, NULL);
  pthread_create(&tid2, NULL, &thread2_calc, NULL);
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);

  if (compara(v1, v2, n)) printf("Mesmos elementos\n");
  else printf("Diferentes\n");
  
  return 0;
}

int compara(int *v1, int *v2, int n) {
  for(int i = 0; i < n; i++) {
    if(v1[i] != v2[i]) return 0;
  }
  return 1;
}

int comparador (const void * p1, const void * p2) {
  return (*(int*)p1 - *(int*)p2);
}

void *thread1_calc(void *a) {
  qsort(v1, n, sizeof(int), comparador);
}

void *thread2_calc(void *a) {
  qsort(v2, n, sizeof(int), comparador);
}