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
  int *julPlaces;
};

typedef struct graph *Graph;

static int **MATRIXINIT(int r, int c, int val) { 
   int **tc = malloc(r * sizeof (int *));
   for (int i = 0; i < r; ++i)   tc[i] = malloc(c * sizeof (int));
   for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j){
        tc[i][j] = val;  
      }   
   return tc;
}

Graph GRAPHInit(int v){
  Graph G = malloc(sizeof(*G));
  G->v = v;
  G->e = 0;
  G->adj = MATRIXINIT(v, v, 0);
  G->julPlaces = malloc(v * sizeof(int));
  for(int i = 0; i < v; i++){
    G->julPlaces[i] = 0;
  }
  return G;
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

void setJulPlaces(Graph g, int v){
  g->julPlaces[v] = 1;
  int w;
  for(w = 0; w < g->v; w++){
    if(g->adj[v][w] == 1 || g-> adj[w][v] == 1){
      g->julPlaces[w] = 1;
    }
  }
}

int main(){
  int nLoc, nLocJul, nLocVer;
  scanf("%d %d %d", &nLoc, &nLocJul, &nLocVer);

  int *v = malloc(nLocJul * sizeof(int));

  Graph G = GRAPHInit(nLoc);

  for(int i = 0; i < nLoc; i++){
    int nvizinhos;
    scanf("%d", &nvizinhos);

    for(int j = 0; j < nvizinhos; j++){
      int vizinho;
      scanf("%d", &vizinho);
      edge e;
      e.v = i;
      e.w = vizinho;
      GRAPHInsertE(G, e);
    }
  }
  int localJul;

  for(int i = 0; i < nLocJul; i++){
    scanf("%d", &localJul);
    setJulPlaces(G, localJul);
  }

  int verificaLocal;
  for(int i = 0; i < nLocVer; i++){
    scanf("%d", &verificaLocal);
    if(G->julPlaces[verificaLocal] == 1){
      printf("Eu vou estar la\n");
    } else {
      printf("Nao vou estar la\n");
    }
  }

  return 0;
}