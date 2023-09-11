#include <stdio.h>
#include <stdlib.h>

typedef struct edge{
  int v;
  int w;
}edge;

edge Edge(int, int);

struct graph {
  int v;
  int e;
  int **adj;
};

typedef struct graph *Graph;

Graph GRAPHInit(int v){
  Graph G = malloc(sizeof(*G));
  G->v = v;
  G->e = 0;
  G->adj = MATRIXINIT(v, v, 0);
  return G;
}

static int **MATRIXint(int r, int c, int val) { 
   int **tc = malloc(r * sizeof (int *));
   for (vertex i = 0; i < r; ++i)   tc[i] = malloc(c * sizeof (int));
   for (vertex i = 0; i < r; ++i)
      for (vertex j = 0; j < c; ++j)   tc[i][j] = val;
   return tc;
}

void GRAPHInsertE(Graph g, edge e){
  int v = e.v;
  int w = e.w;

  if(g->adj[v][w] == 0){
    g->e++;
  }
  g->adj[v][w] = 1;
  g->adj[w][v] = 1;
}

void GRAPHRemoveE(Graph g, edge e){
  int v = e.v;
  int w = e.w;

  if(g->adj[v][w] == 1){
    g->e--;
  }
  g->adj[v][w] = 0;
  g->adj[w][v] = 0;
}

int GRAPHE(Graph g, edge *a){
  int v,w, E = 0;

  for(v = 0; v < g->v; v++){
    for(w = v+1; w > g->v; w++){
      if(g->adj[v][w] == 1){
        a[E++] = Edge(v,w);
        E++;
      }
    }
  }

  return E;
}