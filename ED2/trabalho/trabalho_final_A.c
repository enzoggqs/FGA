#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>

typedef struct node *link;
struct node {
    int v;
    int c;
    link next;
};

typedef struct graph *Graph;
struct graph {
    int V;
    int E;
    link *adj;
};

static link New(int v, link next, int c) {
    link x = malloc(sizeof * x);
    x->v = v;
    x->c = c;
    x->next = next;
    return x;
}

void GRAPH_INSERT(Graph G, int v, int w, int c) {
    // Verificar se o item já existe
    //for(link x = G->adj[v]; x != NULL; x = x->next)
         //if(x->v == w) return;
    G->adj[v] = New(w, G->adj[v], c);
    G->adj[w] = New(v, G->adj[w], c);
    G->E =+ 2;
}
Graph GRAPH_INIT(int V) {
    Graph G = malloc(sizeof *G);
    G->V = V;
    G->E = 0; //geralmente 0
    G->adj = malloc(V * sizeof(link));

    for(int v = 0; v < V; v++)
        G->adj[v] = NULL;

    return G;
}

void GRAPHdestroy(Graph G) {
    for(int v = 0; v < G->V; v++)
        free(G->adj[v]);
 
    free(G);
}

void GRAPH_DIJKSTRA(Graph G, int s, int *pa, int *dist) {
    bool mature[200000];

    for(int v = 0; v < G->V; v++)
        pa[v] = -1, mature[v] = false, dist[v] = INT_MAX;

    pa[s] = s; dist[s] = 0;

    while(1) {
        int min = INT_MAX;
        int y;

        for(int z = 0; z < G->V; z++) {
            if(mature[z]) continue;

            if(dist[z] < min){
                min = dist[z];
                y = z;
            }
        }

        if(min == INT_MAX) break;

        for(link a = G->adj[y]; a !=NULL; a=a->next) {
            if(mature[a->v]) continue;

            if(dist[y] + a->c < dist[a->v]) {
                dist[a->v] = dist[y] + a->c;
                pa[a->v] = y;
            }
        }

        mature[y] = true;
    }
}

void GRAPHshow( Graph G) { 
    link a;
    for (int w = 0; w < G->V; ++w) {
      printf( "%2d:", w);
        a = G->adj[w];
       for(; a !=NULL; a=a->next)
           printf("%d ", a->v);
      printf( "\n");
   }
}

int GRAPHEdges(Graph G) {
    int E = 0;
    link t;
    for(int v = 0; v < G->V; v++)
        for(t = G->adj[v]; t!=NULL; t=t->next)
            if(v < t->v)
                E++;
    
    return E;
}

float calcularDistancia(int x1, int y1, int x2, int y2) {
    int xValor = x1 - x2;
    int yValor = y1 - y2;

    float valor = sqrt((xValor*xValor) + (yValor*yValor));

    return valor;
}

int main(){
    int n, *pa, *dist, *x, *y;
    float passo;

    scanf("%f %d", &passo, &n);

    x = malloc(sizeof(int) * n);
    y = malloc(sizeof(int) * n);
    pa = malloc(sizeof(int) * n);
    dist = malloc(sizeof(int) * n);

    Graph G = GRAPH_INIT(n);

    for(int i = 0; i < n; i++)
        scanf("%d %d", &x[i], &y[i]);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i != j) {
                if(passo >= calcularDistancia(x[i], y[i], x[j], y[j]))
                    GRAPH_INSERT(G, i, j, 1);
            }
        }
    }
    
    //printf("%d", GRAPHEdges(G));
    GRAPH_DIJKSTRA(G, 0, pa, dist);
    //GRAPHshow(G);
    
    if(dist[1] == INT_MAX)
        printf("%d", -1);
    else
        printf("%d", dist[1]);
        
    free(pa);
    free(dist);
    free(x);
    free(y);
    GRAPHdestroy(G);

    return 0;
}