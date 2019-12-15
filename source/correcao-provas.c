#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "global.c"
#include "file.c"

#define limparBuffer while(getchar()!='\n');

// Prototipação de função

void entradaGabarito();
void entradaAluno();

void entradaProvas(){
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
    
}

void entradaGabarito()
{
    /*
     * Função responsável pela entrada do gabarito do programa
     */
    
        // Estrutura de validação
    do
    {
        // Pede o numero de questões da prova
        printf("Digite o numero de questões da prova: ");
        scanf("%d",&qtdQuestoes);

        limparBuffer;

        // Imprime uma mensagem se não for digitado um valor válido
        if (qtdQuestoes>100 || qtdQuestoes<=0)
        {
            printf("Digite um numero de questões entre 1 e 100 !!!\n");
        }
        // Enquanto não for digitado um valor válido, ele pede de novo o numero de questões
    } while (qtdQuestoes>100 || qtdQuestoes<=0);
    
    
    fflush(stdin);
        // Repete o laço para, o usuario digitar todas as questões
    for(int i=0; i<qtdQuestoes; i++)
    {
        do
        {
                // Pergunta a alternativa correta de cada questão
            printf("Digite a alternativa correta da %d° questão: ",i+1);
            scanf("%c",&gabarito[i]);

            limparBuffer;

                // Verifica se a alternativa digitada pelo usuario é valida
            if (!((gabarito[i] >= 'a' && gabarito[i] <= 'e')))
            {
                // Mensagem caso o usuario digite uma alternativa inválida
                printf("Digite apenas Alternativas válidas!!! \n");
                printf("Alternativas válidas: A B C D E \n");
                printf("Somente Letras MINÚSCULAS !!! \n");
            }
                
                // Repete enquanto nao for digitar uma alternativa válida
        } while (!((gabarito[i] >= 'a' && gabarito[i] <= 'e')));
             
    }
      
}

void entradaAluno()
{
    /*
     * Função referente a entrada de dados do aluno
     * Nome do aluno e respostas da prova
    */
    qntAlunos = 0;
    char simnao;
        
    // estrutura de repetição para cadastro de aluno, e suas respostas, 
    //repete enquanto o usuario digita 1 na opção de continuar cadastro
    do
    {
        // Pede o nome do aluno
        printf("Digite o nome do %d° aluno(a): ", qntAlunos+1);
        scanf("%50[^\n]", &nomeAlunos[qntAlunos]);
           
        limparBuffer;

        // Pede todas as alternativas escolhidas pelo aluno
        for(int resp=0; resp<qtdQuestoes; resp++)
        {
            // Estrutura de validação de alternativas do aluno
            do
            {
                printf("Digite a alternativa escolhida pelo aluno da %d° questão: ",resp+1);
                scanf("%s",&respostasAlunos[resp][qntAlunos]);
                
                limparBuffer;

                // Verifica se a resposta digitada é válida
                if (!((respostasAlunos[resp][qntAlunos] >= 'a') && (respostasAlunos[resp][qntAlunos] <= 'e')))
                {
                    printf("Digite apenas Alternativas válidas !!! \n");
                    printf("Alternativas válidas: A B C D E \n");
                    printf("Somente Letras MINÚSCULAS !!! \n");
                }
                // Repete ate que o usuario digite a opção válida
            } while (!((respostasAlunos[resp][qntAlunos] >= 'a') && (respostasAlunos[resp][qntAlunos] <= 'e')));
                
        }

        // Depois que terminar de digitar todas as repostas do aluno mais 1 aluno é adicionado
        qntAlunos++;
        
        // Estrutura para perguntar se o usuario deseja cadastrar outro aluno
        do
        {
            printf("Voce deseja cadastrar outro aluno ? \n");
            printf("Digite 'n' para não e 's' para sim \n");
            scanf("%c",&simnao);

            limparBuffer;

            // Exibe a mensagem caso o usuario digite uma opção diferente de 0 ou 1
            if (simnao !='s' && simnao !='n')
            {
                printf("Digite somente 's' ou 'n'\n");
            }
            printf("\n");
            // Repete enquanto o usuario não digitar 0 ou 1
        } while (simnao != 's' && simnao !='n');
        
            // Repete caso o usuario escolha cadastrar outro aluno
    } while (simnao == 's');
    
}