#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char *string;
    struct node *next_node;
} node;

typedef struct
{
    int count;
    node *p;
} pilha_st;

void inicializa_pilha(pilha_st *p)
{
    p->count = 0;
    p->p = NULL;
}

int estaVazia(pilha_st *p)
{
    return p->count == 0 ? 1 : 0;
}

char *desempilha(pilha_st *p)
{
    char *ret = p->p->string;
    node *x = p->p;
    p->p = p->p->next_node;
    free(x);
    p->count--;
    return ret;
}
int empilha(pilha_st *p, char *buffer)
{
    node *x = malloc(sizeof(node));
    if (x == NULL)
    {
        return 0;
    }

    x->string = buffer;
    x->next_node = p->p;
    p->p = x;
    p->count++;
    return 1;
}

int main(void)
{

    pilha_st pilha;

    char comando[9];
    while (scanf(" %s", comando) == 1)
    {
        if (comando[0] == 'i')
        {
            char *buf = malloc(101);
            scanf(" %[^\n]", buf);
            empilha(&pilha, buf);
        }
        else
        {
            if (estaVazia(&pilha))
            {
                printf("NULL\n");
            }
            else
            {
                printf("%s\n", desempilha(&pilha));
            }
        }
    }

    return 0;
}