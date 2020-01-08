#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "include/corretor.h"
#include "include/file.h"
#include "include/utils.h"

#define cleanBuffer while(getchar()!='\n');

// Prototipação de função

void entradaGabarito();
void entradaAluno();

int main()
{
    printf("ENTRADA DO GABARITO DE PROVA \n");
    entradaGabarito();
    printf("\n \n");
    printf("ENTRADA DAS RESPOSTAS DO ALUNOS \n");
    entradaAluno();
    system("clear");

    // checa log e retorna numero do arquivo "prova-%i"
    int numArq = file();
    // corrige e cria arquivo com historico da prova
    corrigirProva(numArq);

    // imprime arquivo criado na tala do terminal
    if (printarq(numArq) == 0)
    {
        printf("Erro ao ler arquivo!!! \n");
    }
    
    return 0;
}

/*
 * Função responsável pela entrada do gabarito do programa
 */
void entradaGabarito()
{
    
    // Estrutura de validação
    do
    {
        // Pede o numero de questões da prova
        printf("Digite o numero de questões da prova: ");
        scanf("%d",&qtdQuestoes);

        cleanBuffer;

        // Imprime uma mensagem se não for digitado um valor válido
        if (qtdQuestoes>100 || qtdQuestoes<=0)
        {
            printf("Digite um numero de questões entre 1 e 100 !!!\n");
            printf("\n");
        }
        
        // Enquanto não for digitado um valor válido, ele pede de novo o numero de questões
    } while (qtdQuestoes>100 || qtdQuestoes<=0);
    
    
    fflush(stdin);

    // Repete o laço para, o usuario digitar todas as questões
    for(int i=0; i<qtdQuestoes; i++)
    {
        // texto que será exibido para pedir o gabarito da prova
        char text[100];
        sprintf(text, "Digite a alternativa correta da %d° questão: ", i+1);
        // entrada do gabarito
        inputAlternative(text, &gabarito[i]);
    }
      
}

/*
 * Função referente a entrada de dados do aluno
 * Nome do aluno e respostas da prova
 */
void entradaAluno()
{
    
    qtdAlunos = 0;
    char simnao;
    
    // estrutura de repetição para cadastro de aluno, e suas respostas, 
    //repete enquanto o usuario digita 'S' na opção de continuar cadastro
    do
    {

        int check;
        do {
            // Pede o nome do aluno
            printf("Digite o nome do %d° aluno(a): ", qtdAlunos+1);
            scanf("%50[^\n]", &nomeAlunos[qtdAlunos]);

            check = checkName(nomeAlunos[qtdAlunos]);

        } while (check != 0);

        cleanBuffer;

        // Pede todas as alternativas escolhidas pelo aluno
        for(int resp=0; resp<qtdQuestoes; resp++)
        {
            char text[100];
            sprintf(text, "Digite a alternativa escolhida pelo aluno da %d° questão: ",resp+1);
            // entrada da resposta do aluno
            inputAlternative(text, &respostasAlunos[resp][qtdAlunos]);
        }

        // Depois que terminar de digitar todas as repostas do aluno mais 1 aluno é adicionado
        qtdAlunos++;

        if (qtdAlunos < 100)
        {
            // Estrutura para perguntar se o usuario deseja cadastrar outro aluno
            do
            {
                printf("\n");
                printf("Voce deseja cadastrar outro aluno ? \n");
                printf("Digite 'N' para não e 'S' para sim \n");
                scanf("%c", &simnao);

                // coloca a letra digitada pelo usuario em maiusculo
                simnao = toupper(simnao);

                cleanBuffer;

                // Exibe a mensagem caso o usuario digite uma opção diferente de 0 ou 1
                if (simnao !='S' && simnao !='N')
                {
                    printf("Digite somente 'S' ou 'N' !!! \n");
                }

                // Repete enquanto o usuario não digitar 0 ou 1
            } while (simnao != 'S' && simnao !='N');

            printf("\n");
        } 
        else
        {
            simnao = 'N';
        }

    // Repete caso o usuario escolha cadastrar outro aluno
    } while (simnao == 'S');
    
}