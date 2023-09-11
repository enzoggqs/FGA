#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  int count = argc;
  char **values = argv;
  for (int i = 1; i < count; i++){
    if (i < count - 1){
      for (int j = i + 1; j < count; j++){
        // printf("%s %s\n", values[i], values[j]);
        int aux1 = 0;
        long file_one_size, file_two_size, k = 0;
        FILE *file_one, *file_two;
        char aux2, aux3;

        file_one = fopen(values[i], "r");
        if (file_one == NULL){
          printf("Entrou no exit\n");
          break;
        }

        file_two = fopen(values[j], "r");
        if (file_two == NULL){
          printf("Entrou no exit\n");
          break;
        }
        
        fseek(file_one, 0, SEEK_END);
        file_one_size = ftell(file_one);
        rewind(file_one);

        fseek(file_two, 0, SEEK_END);
        file_two_size = ftell(file_two);
        rewind(file_two);

        if (file_one_size != file_two_size){
          fclose(file_one);
          fclose(file_two);
          // printf("Entrou na diferença de tamanho\n");
          printf("%s %s diferentes\n", values[i], values[j]);
          aux1 = 1;
          continue;
        }
        for (k = 0; k < file_one_size; k++){
            fread(&aux2, 1, 1, file_one);
            fread(&aux3, 1, 1, file_two);
            
            if (aux2 != aux3){
              aux1 = 1;
              
              // printf("Entrou na diferença dos elementos do arquivo\n");
              // printf("%s %s diferentes\n", values[i], values[j]);
              continue;
            }
        }

        fclose(file_one);
        fclose(file_two);
        if(aux1 == 0)
          printf("%s %s iguais\n", values[i], values[j]);
        else
          printf("%s %s diferentes\n", values[i], values[j]);
      }
    }
  }

  return 0;
}