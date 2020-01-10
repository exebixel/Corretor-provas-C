#include <stdio.h> 
#include <stdlib.h>
#include "mysql-connect.h"

#define cleanBuffer while(getchar() != '\n')

// adiciona um aluno no bando de dados
// retorna 1 se for bem sucedido
// retorna 0 se for mal sucedido
int addAlunoDB(char *name);

int addAluno()
{
    
    char alunoName[40];
    printf("ADCIONAR ALUNO: \n");
    printf("Digite o nome do aluno: ");
    scanf("%40[^\n]", alunoName);

    printf("\n");
    if (addAlunoDB(alunoName))
    {
        printf("Cadastro de aluno feito com sucesso!!! \n");
    }
    else
    {
        printf("Erro ao efetuar cadastro!!! \n");
    }
    
    cleanBuffer;
    getchar();
    return 1;
}

int addAlunoDB(char *name)
{
    char sql[255];
    sprintf(sql, "INSERT INTO alunos VALUES(NULL, '%s')",
                name);

    if (MyCrud(sql))
    {
        return 1;
    } 
    else
    {
        return 0;
    }
    
    
}