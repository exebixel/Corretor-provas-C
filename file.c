#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

void file()
{
    DIR *diretorio = opendir("History");

    int cont = 0;
    while (readdir(diretorio))
    {
        cont++;
    }
    printf("Número de arquivos: %d \n", cont-2);
    closedir(diretorio);
    
    FILE *arquivo;
    char nome[40];
    sprintf(nome, "History/provas-%i", cont-1);
    arquivo = fopen(nome, "w");
    printf("Nome do arquivo criado: %s \n", nome);
    printf("Arquivo criado com sucesso!!! \n");
    fclose(arquivo);
    
}

int main()
{
    file();
}