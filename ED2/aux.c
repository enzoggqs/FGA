#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define vertex int

struct graph {
   int V; 
   int A; 
   int **adj; 
   int *flaged_adj;
};

typedef struct graph *Graph;

static int **MATRIXint(int r, int c, int val) { 
   int **tc = malloc(r * sizeof (int *));
   for (vertex i = 0; i < r; ++i)   tc[i] = malloc(c * sizeof (int));
   for (vertex i = 0; i < r; ++i)
      for (vertex j = 0; j < c; ++j)   tc[i][j] = val;
   return tc;
}

Graph GRAPHinit(int V) { 
   Graph G = malloc(sizeof *G);
   G->V = V; 
   G->A = 0;
   G->adj = MATRIXint(V, V, 0);
   G->flaged_adj = malloc(V * sizeof(int));
   return G;
}

void GRAPHinsertArc(Graph G, vertex v, vertex w) { 
   if (G->adj[v][w] == 0) {
      G->adj[v][w] = 1;
      G->adj[w][v] = 1; 
      G->A++;
   }
}

void GRAPHremoveArc(Graph G, vertex v, vertex w) { 
   if (G->adj[v][w] == 1) {
      G->adj[v][w] = 0;
      G->adj[w][v] = 0; 
      G->A--;
   }
}

void GRAPHmarkElements(Graph G, vertex v) {
      for (vertex w = 0; w < G->V; ++w) {
         if (G->adj[v][w] == 1) {G->flaged_adj[w] = 1;}
         if (G->adj[w][v] == 1) {G->flaged_adj[w] = 1;}
     }
}

bool GRAPHisElementMarked(Graph G, vertex v) {
  if(G->flaged_adj[v] == 1) return true;
  else   return false;
}

int main() {
  int n, m, j, a, temporary;

  scanf("%d %d %d", &n, &m, &j);
  Graph G = GRAPHinit(n);

  for(int i = 0; i < n; i++) {
    scanf("%d", &a);
    for(int j = 0; j < a; j++) {
      scanf(" %d", &temporary);
      GRAPHinsertArc(G, i, temporary);
    }
  }
  for(int i = 0; i < m; i++) {
    scanf("%d", &temporary);
    G->flaged_adj[temporary] = 1; 
    GRAPHmarkElements(G, temporary);
  }
  for(int i = 0; i < j; i++) {
    scanf("%d", &temporary);
    if(GRAPHisElementMarked(G, temporary)) {
      printf("Eu vou estar la\n");
    } else {
      printf("Nao vou estar la\n");
    }
  }
  return 0;
}