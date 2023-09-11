#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int countAlrm = 0;

void treat_signal(int s){
  if(s == SIGUSR1){
    printf("SIGUSR1 eh para aproveitar mais um pouco\n");
  } else if(s == SIGALRM){
    countAlrm++;
    if(countAlrm == 3){
      printf("Os incomodados que se mudem, tchau\n");
      exit(0);
    } else {
      printf("Ai que sono, quero dormir mais um pouco\n");
    }
  }
}

int main(void){
  signal(SIGUSR1, treat_signal);
  signal(SIGALRM, treat_signal);

  while(1){
    pause();
  }
}