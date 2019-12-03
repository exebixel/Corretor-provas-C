#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include "corretor.c"

int checklog();
void addlog();
void file();
void createlog();
int checkarchive();

int checklog()
{
    FILE *arquivolog;
    if ((arquivolog = fopen("History/.log", "r")) == NULL)
    {
        createlog();
        arquivolog = fopen("History/.log", "r");
    } 

    int num = 0;
    int maior = 0;

    while (!feof(arquivolog))
    {
        fscanf(arquivolog, "%i ;", &num);
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
    arquivolog = fopen("History/.log", "w");

    fprintf(arquivolog, "%i ;\n", numeroLog);

    fclose(arquivolog);
}

void createlog()
{
    DIR *pasta;
    pasta = opendir("History");
    struct dirent *ls;
    int num = 0;
    int maior = 0;

    while (ls = readdir(pasta))
    {
        sscanf(ls->d_name, "prova-%i", &num);
        
        if (num > maior)    
        {
            maior = num;
        }
        
    }
    closedir(pasta);
    
    addlog(maior);

}

int checkarchive(int numArquivo)
{
    FILE *arquivo;
    char nomeArquivo[40];
    sprintf(nomeArquivo, "History/prova-%i", numArquivo);
    if ((arquivo = fopen(nomeArquivo, "r")) != NULL)
    {
        fclose(arquivo);
        return 1;
    }
    return 0;    
}

void file()
{
    mkdir("History", 0755);
    
    int numeroArquivo = checklog();

    if (checkarchive(numeroArquivo +1))
    {
        createlog();
        file();
    }
    else
    {
        addlog(numeroArquivo + 1);

        corrigirProva(numeroArquivo + 1);
        
    }
    

    
}