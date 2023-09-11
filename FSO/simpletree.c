#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void seguraarvore(void){
  sleep(20);
  exit(0);
}

int main(void){
  pid_t b=fork();
  if(b==0)
    seguraarvore();
  pid_t c=fork();
  if(c==0){
    pid_t e = fork();
    if(e==0){
      seguraarvore();
    }
    seguraarvore();
  } else {
    pid_t d=fork();
    if(d==0){
      pid_t f, g;
      f=fork();
      if(f == 0){
        seguraarvore();
      }
      g = fork();
      if(g==0){
        seguraarvore();
      }
    }
  }
  seguraarvore();
}