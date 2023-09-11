#include <stdio.h>
#include <stdlib.h>

void is_different(char *pFname1, char *pFname2){
    FILE *pFile1, *pFile2;
    long lSize1, lSize2; // file length
    long i = 0;
    char tmp1, tmp2;

    pFile1 = fopen(pFname1, "r");
    if (pFile1 == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
    pFile2 = fopen(pFname2, "r");
    if (pFile2 == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }

    // obtain file size:
    fseek(pFile1, 0, SEEK_END);
    lSize1 = ftell(pFile1);
    rewind(pFile1);

    // obtain file size:
    fseek(pFile2, 0, SEEK_END);
    lSize2 = ftell(pFile2);
    rewind(pFile2);

    if (lSize1 != lSize2)
    {
        fclose(pFile1);
        fclose(pFile2);
        printf("entrou na dif de tamanho\n");
        printf("%s %s diferentes\n", pFname1, pFname2);
        return;
    }
    for (i = 0; i < lSize1; i++)
    {
        fread(&tmp1, 1, 1, pFile1);
        fread(&tmp2, 1, 1, pFile2);
        if (tmp1 != tmp2)
        {
        printf("entrou na dif do arquivo mesmo\n");

            printf("%s %s diferentes\n", pFname1, pFname2);
            return;
        }
    }

    fclose(pFile1);
    fclose(pFile2);
    printf("%s %s iguais\n", pFname1, pFname2);
    return;
}

int main(int argc, char *argv[])
{
    for (int pos_arq = 1; pos_arq < argc; pos_arq++)
    {
        if (pos_arq < argc - 1)
        {
            for (int pos_outros_arq = pos_arq + 1; pos_outros_arq < argc; pos_outros_arq++)
            {
                is_different(argv[pos_arq], argv[pos_outros_arq]);
                //     printf("%s %s diferentes\n", argv[pos_arq], argv[pos_outros_arq]);
                // else
                //     printf("%s %s iguais\n", argv[pos_arq], argv[pos_outros_arq]);
            }
        }
    }

    return 0;
}