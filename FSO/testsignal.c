#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	pid_t x;
	x = fork();
	sleep(5);
	if(x==0){
		printf("Sou o filho, pid = %d, e pai %d\n");
		pid_t p;
		p = fork();
		while(1){
			printf("HEHEHEHE\n");
			sleep(2);
		}
		return 3;
	}else{
		sleep(5);
		printf("Sou pai, com filho=%d, e meu pai é %d\n",x,getppid());
		int s;
		//wait(%s);
		//printf("Meu filho devolveu: %d\n", WEXITSTATUS(s));
		sleep(3);
	}
}
