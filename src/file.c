#include "include/file.h"
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include "include/corretor.h"

int checklog()
{
    FILE *arquivolog;
    // testa se o log existe
    char nameArchive[100];
    sprintf(nameArchive, "%s/.log", DIRNAME);
    if ((arquivolog = fopen(nameArchive, "r")) == NULL)
    {
        // se não existir cria o log
        createlog();
        // abre arquivo log
        arquivolog = fopen(nameArchive, "r");
    } 

    int num = 0;
    int maior = 0;
    // pega o numero do arquivo log
    fscanf(arquivolog, "%i ;", &num);
    // testa se o número é o maior número do log
    if (num > maior)
    {
        maior = num;
    }

    fclose(arquivolog);
    // retorna o maior número encontrado no log
    return maior;
}

void addlog(int numeroLog)
{
    FILE *arquivolog;
    // abre o arquivo log
    char nameArchive[50];
    sprintf(nameArchive, "%s/.log", DIRNAME);
    arquivolog = fopen(nameArchive, "w");
    // salva no arquivo o numero passado pelo parametro
    fprintf(arquivolog, "%i ;\n", numeroLog);
    // fecha arquivo
    fclose(arquivolog);
}

void createlog()
{
    DIR *pasta;
    // abre o o diretorio
    pasta = opendir(DIRNAME);
    struct dirent *ls;
    int num = 0;
    int maior = 0;

    // lê todos os arquivos do diretorio
    while (ls = readdir(pasta))
    {
        // pega o numero do arquivo de prova
        sscanf(ls->d_name, "prova-%i", &num);
        // testa se o numero é o maior
        if (num > maior)    
        {
            maior = num;
        }
        
    }
    closedir(pasta);
    
    // adiciona no log o maior número de prova
    addlog(maior);

}

int checkarchive(int numArquivo)
{
    FILE *arquivo;
    char nomeArquivo[40];
    // define o nome do arquivo que sera aberto
    sprintf(nomeArquivo, "%s/prova-%i", DIRNAME, numArquivo);
    // tenta abrir o arquivo
    if ((arquivo = fopen(nomeArquivo, "r")) != NULL)
    {
        // se o arquivo existir
        fclose(arquivo);
        return 1;
    }
    // se o arquivo não existir
    return 0;    
}

int printarq(int numarq)
{
    FILE *arquivo;
    char nomeArquivo[40];
    // define o nome do arquivo que será lido
    sprintf(nomeArquivo, "%s/prova-%i", DIRNAME, numarq);

    // abre o arquivoDI
    if (arquivo = fopen(nomeArquivo, "r")){

        char c;
        // le o arquivo enquanto não chegar no final dele
        while (!feof(arquivo))
        {
            // imprimi no terminal letra por letra
            fscanf(arquivo, "%c", &c);
            printf("%c", c);
        }
        
        fclose(arquivo);
        // se o arquivo foi lido com sucesso
        return 1;
    }
    else
    {
        // se o arquivo não existir
        return 0;
    }
}

int file()
{
    // checa se a pasta DIRNAME existe se não existir cria
    mkdir(DIRNAME, 0755);
    
    // checa arquivo de log para saber qual o numero do arquivo de prova
    int numeroArquivo = checklog();

    // checa se o arquivo de prova já existe
    if (checkarchive(numeroArquivo +1))
    {
        // se existir cria novo log
        createlog();
        // retona para o começo da função
        file();
    }
    else
    {
        // se não existir adiciona o numero no arquivo log
        addlog(numeroArquivo + 1);
        // retona o numero do arquivo a ser criado
        return numeroArquivo +1;
    }    
}