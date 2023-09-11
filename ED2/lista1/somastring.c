#include <stdio.h>
#include <stdlib.h>

void somaeimprime();

int main(){
  int t;
  scanf("%d", &t);
  char b[101];

  for(int i = 0; i<t; i++){
    // printf("entrou com i %d", i);
    somaeimprime();
  }
  return 0;
}

void somaeimprime(){
  char b[101];
  scanf("%s", b);
  int i = 0, soma = 0;
  while(b[i] != '\0'){
    if(b[i] > '0' && b[i] <= '9')
      soma+=b[i]-'0';
    i++;
  }
  printf("%d\n", soma);
}