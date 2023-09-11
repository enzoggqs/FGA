#include <stdio.h>
#include <stdlib.h>

typedef struct ED
{
  char *prev;
  char *next;
  struct node *next_node;
} ED;

int sanidade(unsigned long PTR1, unsigned long PTR2, ED *lista)
{
  pilha_t p;
  inicializa_pilha(&p);

  unsigned long aux = PTR1;
  
  while(aux != PTR2)
  {
    empilha(&p, aux);
    unsigned long prox = buscaproximo(lista, aux);
    aux = prox;
  }
  if (aux == PTR2) empilha(&p, aux);
  else return 0;

  while(aux != 0 && aux != PTR1){
    if(aux != desempilha(&p)) return 0;
    unsigned long ant = buscaanterior(lista, aux);
    aux = ant;
  }
  if( aux != desempilha(&p)) return 0;
  if(esta_vazia(&p)) return 1;
  else return 0;
}

int main(){
    unsigned long PTR1, PTR2, PTR3;
    ED *lista;
    scanf("%lu %lu %lu", &PTR1, &PTR2, &PTR3);
    lista = (ED *)malloc(sizeof(ED));
    lista->next = NULL;
    lista->prev = NULL;
    lista->PTR1 = PTR1;
    lista->PTR2 = PTR2;
    lista->PTR3 = PTR3;
    if (sanidade(PTR1, PTR2, lista) == 0)
    {
        printf("0");
    }
    else
    {
        printf("1");
    }
    return 0;

  return 0;
}