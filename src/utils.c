#include "include/utils.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define cleanBuffer while(getchar() != '\n')

void initString(char *string)
{
    // pega o tamanho da string
    // no caso o lixo de memoria da string
    int tam = sizeof(string)/sizeof(char);
    
    // percorre o tamanho de string
    for (int  i = 0; i < tam; i++)
    {
        // limpa o lixo de memoria da string
        // 0 é o equivalente de NULL aqui
        string[i] = 0;
    }    
}

int checkName(char *name)
{
    // pega o tamanho de string
    int tam = strlen(name);

    // percorre o tamanho de string, caractere por caractere
    for (int i = 0; i < tam; i++)
    {
        // checa se o caractere é valido ou não
        // não pode ser um caractere especial (pelo menos alguns deles)
        // nem eu número
        if ((ispunct(name[i]) != 0) ||
            (isdigit(name[i])) != 0)
        {
            // imprimi mensagem de caractere invalido
            printf("Digite apenas letras!!! \n");
            // limpa o buffer (evita erros)
            cleanBuffer;
            // limpa qualquer caractere existente na string (tambem ajuda a evitar erros)
            initString(&name[0]);
            
            return 1;
        }
    }
    return 0;
}

int checkAlternative(char alternative)
{
    // Verifica se a resposta digitada é válida
    if (!((alternative >= 'A') && (alternative <= 'E')))
    {
        printf("Digite apenas Alternativas válidas !!! \n");
        printf("Alternativas válidas: A B C D E \n");
        return 1;
    }
    return 0;
}

int inputAlternative(char *text, char *alter)
{
    int check;
    // Estrutura de validação de alternativas do aluno
    do
    {
        // imprimi a mensagem definida pelo parametro *text
        printf("%s", text);
        // lê a variavel que foi passada pelo parametro *alter
        scanf("%c",alter);

        // coloca a letra digitada pelo usuario em maiusculo
        *alter = toupper(*alter);

        // checa se a alternativa digitada é valida
        check =  checkAlternative(*alter);
        cleanBuffer;
        
        // Repete ate que o usuario digite a opção válida
    } while (check != 0);
    return 0;
}