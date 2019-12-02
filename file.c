#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include "corretor.c"


int checklog()
{
    FILE *arquivolog;
    if ((arquivolog = fopen("History/.log", "r")) == NULL)
    {
        // arquivo não existe
        arquivolog = fopen("History/.log", "w");
        fclose(arquivolog);
        return 0;
    } 

    int num;
    int maior = 0;

    while (!feof(arquivolog))
    {
        fscanf(arquivolog, "%d ;", &num);
        if (num > maior)
        {
            maior = num;
        }
        
    }
    
    fclose(arquivolog);

    return maior;
}

void addlog(int numeroLog)
{
    FILE *arquivolog;
    arquivolog = fopen("History/.log", "a");

    fprintf(arquivolog, "%i ;\n", numeroLog);

    fclose(arquivolog);
}

void file()
{
    mkdir("History", 0755);
    
    int numeroArquivo = checklog();

    addlog(numeroArquivo + 1);

    corrigirProva(numeroArquivo + 1);
    
}