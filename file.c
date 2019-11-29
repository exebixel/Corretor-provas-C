#include <stdio.h>
#include <stdlib.h>

void file()
{
    FILE *arquivo;
    char nome[40];
    int num = 3;
    sprintf(nome, "History/provas-%i", num);
    printf("%s", nome);
    arquivo = fopen(nome, "w");
    printf("Arquivo criado com sucesso!!! \n");
    fclose(arquivo);
}

int main()
{
    file();
}