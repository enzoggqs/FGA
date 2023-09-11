#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int check_semente(int* numbers, int size, unsigned int seed) {
  int i = 0, j, rand_mod_256, original_seed = seed;
  const int rounds = 10000;
  for (; i < size; i++) {
    for (j = 0; j < rounds-1; j++)
      rand_r(&seed);
    
    rand_mod_256 = rand_r(&seed) % 256;
    if (numbers[i] != rand_mod_256)
      return 0;
  }

  return 1;
}

int encontra_semente(int*numbers, int size, int min_seed, int max_seed) {
  unsigned int seed = min_seed;

  while (seed <= max_seed) {
    if (check_semente(numbers, size, seed))
      return seed;
    ++seed;
  }

  return -1;
}

int main() {
  int i, min_seed, max_seed, rand_number_mod_256;
  int size = 0, capacity = 1000;
  int* numbers = calloc(capacity, sizeof(int));

  scanf("%d %d", &min_seed, &max_seed);

  while (scanf("%d", &rand_number_mod_256) != EOF) {
    if (size+1 >= capacity) {
      capacity *= 2;
      numbers = realloc(numbers, capacity);
    }
    numbers[size++] = rand_number_mod_256;
  }

  unsigned int seed = encontra_semente(numbers, size, min_seed, max_seed);

  printf("%d\n", seed);

  free(numbers);
}