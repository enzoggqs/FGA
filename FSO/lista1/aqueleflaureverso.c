#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void trataSinais(int s){
    int r;
    char string[11];
    r = scanf(" %s", string);
    if(r == EOF){
      exit(0);
    }
		if(s == SIGUSR1 && string[3] == 'r'){
			printf("Certo\n");
		} else if (s == SIGUSR2 && string[3] == 'a'){
			printf("Certo\n");
		} else if (s == SIGINT && string[3] == '1'){
			printf("Certo\n");
		} else if (s == SIGTERM && string[3] == '2'){
			printf("Certo\n"); 
		} else if (s == SIGALRM && string[3] == 'e'){
			printf("Certo\n");
		} else {
      kill(getppid(), SIGALRM);
      printf("Erro\n");
		}
}

int main() {

    signal(SIGUSR1, trataSinais);
    signal(SIGUSR2, trataSinais);
    signal(SIGINT, trataSinais);
    signal(SIGTERM, trataSinais);
    signal(SIGALRM, trataSinais);
    while(1){
        pause();
    }
    return 0;
}