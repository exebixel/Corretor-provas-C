#include <stdio.h>
#include <stdlib.h>
#include "global.c"

void corrigirProva()
{
    // Variaveis 
    int acertoTotal = 0;
    int mediaTotal = 0;
    float acertosPorQuestao[qtdQuestoes];

    // Estrutura de repetição que percorre os alunos
    for (int PercAlunos = 0; PercAlunos < qntAlunos; PercAlunos++)
    {
        //Variaveis de acerto e erro
        int acertos = 0;
        int erros = 0;
        printf("\n");
        printf("Nome %d° aluno(a): %s \n", PercAlunos+1, nomeAlunos[PercAlunos]);
        // Estrutura que percorre as alternativas
        for (int PercAlter = 0; PercAlter < qtdQuestoes; PercAlter++)
        {
            // Compara a alternativas dos alunos com gabarito
            if (respostasAlunos[PercAlter][PercAlunos] == gabarito[PercAlter])
            {
                printf("Questão: %d° Resposta Correta: %c \n", PercAlter +1, gabarito[PercAlter]);
                // conta quantidade de acertos do aluno
                acertos++;
                // conta quantidade de erros do aluno
                acertoTotal++;
                // conta a quantidade de acertos da questão
                acertosPorQuestao[PercAlter]++;
            }
            else
            {
                printf("Questão: %d° Resposta Errada \n", PercAlter +1);
                // conta a quantidade de erros do aluno
                erros++;
            }
        }
        // Exibe o total de acertos e de erros do aluno
        printf("Total de Acertos do aluno(a): %d \n", acertos);
        printf("Total de Erros do aluno(a): %d \n", erros);
        
    }
    // calcula a media de acertos dos alunos
    mediaTotal = acertoTotal/qntAlunos;
    printf("\n \n");
    printf("-------------------------------------------\n");
    printf("A MÉDIA de acertos da turma é: %d/%d \n", mediaTotal, qtdQuestoes);

    
    printf("\n");
    printf("-------------------------------------------\n");    
    printf("Probabilidade de Acerto de cada questão: \n");
    // laço para calcular a probabilidade da acerto de cada questão
    for (int i = 0; i < qtdQuestoes; i++)
    {
        // calcula a probabilidade da acerto da questão
        acertosPorQuestao[i] = (acertosPorQuestao[i]/qntAlunos)*100;
        printf("%d° Questão: %.0f\% \n", i+1, acertosPorQuestao[i]);
    }
    
}