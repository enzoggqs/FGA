#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

#define NMAX 10

// cria os 2 semaforos com sem_t
sem_t semaforo;
sem_t tickets_livres;

// cria 2 variáveis globais, uma sendo um array que armazena os tickets, e a outra o número de tickets
int tickets_ls[NMAX], tickets_tot;

// Inicia o tickets, passando um for pelo número máimo e armazenando um ticket para cada posição
void init_tickets(void){
  for(int i = 0; i < NMAX; i++){
    tickets_ls[i] = 300+1;
  }
  tickets_tot = NMAX - 1;
}

// Função que pega tickets
int getticket(void){
  // Primeiro é mandado 2 sem_wait, para travar tickets_livres
  // e semaforo respectivamente
  sem_wait(&tickets_livres);
  sem_wait(&semaforo);
  // Em seguida, cria-se uma variável ret que captura o valor da última posição 
  // no array tickets_ls  ao mesmo tempo em que decrementa o valor de tickets_tot
  int ret = tickets_ls[tickets_tot--];
  // Depois o semaforo semaforo é liberado
  sem_post(&semaforo);
  // E por fim o valor de ret é retornado
  return ret;
}

// Função para retornar um ticket, tem como parâmetro um inteiro t, que é o ticket a ser retornado
void return_ticket(int t){
  // Primeiro é travado o semaforo semaforo
  sem_wait(&semaforo);
  // Depois o valor de tickets_toto é incrementado, e também é colocado no array de tickets inteiro t
  tickets_ls[++tickets_tot] = t;
  // Por fim, os semaforos semaforo e tickets_livres são liberados
  sem_post(&semaforo);
  sem_post(&tickets_livres);
}

void func_da_thread(){
  while(1){
    int t = getticket();
    printf("peguei %d\n", t);
    usleep(rand());
    return_ticket(t);
  }
}

int main(void){
  init_tickets();
  pthread_t tid[10];
  sem_init(&semaforo, 0, 1);
  sem_init(&tickets_livres, 0, tickets_tot);

  for(int i = 0; i < 10; i++){
    pthread_create(&tid[i], NULL, func_da_thread, NULL);
  }

  for(int i = 0; i < 10; i++){
    pthread_join(tid[i], NULL);
  }

  return 0;
}