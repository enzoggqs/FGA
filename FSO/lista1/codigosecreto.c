#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pass = 0;

void treat_signal(int sig){
  printf("Recebi %d\n", sig);
  if(sig == SIGINT){
    pass=1;
  } else if(pass == 1 && sig == SIGUSR2){
    pass = 2;
  } else if(pass==2 && sig == SIGTERM){
    pass = 3;
    printf("Senha acionada\n");
  } else if(pass == 3 && sig == SIGUSR1){
    printf("Tchau\n");
    exit(0);
  }
  else if(sig == SIGTERM || sig == SIGUSR1 || sig == SIGUSR2){
    pass = 0;
  }
}

int main(void){
  signal(SIGTERM, treat_signal);
  signal(SIGUSR1, treat_signal);
  signal(SIGUSR2, treat_signal);
  signal(SIGINT, treat_signal);
  while(1)
    pause();
}