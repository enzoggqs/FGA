#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

void fazoqueofilhofaz();

void fazoqueopaifaz(){
	printf("%d: Sou o pai\n", getpid());
	pid_t p;
	p = fork();
	if(p==0)
		fazoqueofilhofaz();
	int ret;
	p=wait(&ret);
	printf("Filho %d terminou com %d, também vou\n", p, WEXITSTATUS(ret));
	sleep(2);
	p=wait(&ret);
	printf("Filho %d terminou com %d, também vou\n", p, WEXITSTATUS(ret));
	exit(1);
}

void fazoqueofilhofaz(){
	printf("%d: Sou o filho e meu pai eh %d\n", getpid(), getppid());
	sleep(2);
	printf("%d: Sou o filho e meu pai eh %d\n", getpid(), getppid());
	exit(3);
}

int main(void) {
	pid_t p;
	p=fork();
	if(p > 0){
		fazoqueopaifaz();
	}else if(p == 0){
		fazoqueofilhofaz();
	}else{
		printf("Fork falhou");
	}
	sleep(50);
}
