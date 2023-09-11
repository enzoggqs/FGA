#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int exitdofilho = 0;
void treat_signal(int s){
  exitdofilho = s;
}

int main(){
  signal(SIGUSR1, treat_signal);
  signal(SIGUSR2, treat_signal);

  pause();
  if(fork() == 0)
    exit(0);
  pause();
  wait(NULL);
  pause();
  exit(0);
}