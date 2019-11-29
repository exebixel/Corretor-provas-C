#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define limparBuffer while(getchar()!='\n');

// Variaveis Globais

int qtdQuestoes;
int qntAlunos=0;
char gabarito[100];
char nomeAlunos[100][50];
// o 1° 100 é referente as respostas do gabarito
// o 2° 100 é referente aos alunos 
char respostasAlunos[100][100];

// Prototipação de função

void entradaGabarito();
void entradaAluno();
void corrigirProva();

int main(){
    printf("ENTRADA DO GABARITO DE PROVA \n");
    entradaGabarito();
    printf("\n \n");
    printf("ENTRADA DAS RESPOSTAS DO ALUNOS \n");
    entradaAluno();
    system("clear");
    corrigirProva();
    
    return 0;
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

    int  simnao;
        
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
            printf("Digite 0 para não e 1 para sim \n");
            scanf("%d",&simnao);

            limparBuffer;

            // Exibe a mensagem caso o usuario digite uma opção diferente de 0 ou 1
            if (simnao !=0 && simnao !=1)
            {
                printf("Digite somente 0 ou 1\n");
            }
            printf("\n");
            // Repete enquanto o usuario não digitar 0 ou 1
        } while (simnao != 0 && simnao !=1);
        
            // Repete caso o usuario escolha cadastrar outro aluno
    } while (simnao == 1);
    
    
}


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