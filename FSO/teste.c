#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
  for(int i = 0; i < 4; i++){
    pid_t p = fork();
  }

  printf("FSO\n");
}