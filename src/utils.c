#include "include/utils.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define cleanBuffer while(getchar() != '\n')

void initString(char *string)
{
    int tam = sizeof(string)/sizeof(char);
    for (int  i = 0; i < tam; i++)
    {
        string[i] = 0;
    }    
}

int checkName(char *name)
{
    int checkcaractere = 0;
    int tam = strlen(name);

    for (int i = 0; i < tam; i++)
    {
        if ((ispunct(name[i]) != 0) ||
            (isdigit(name[i])) != 0)
        {
            printf("Digite apenas letras!!! \n");
            checkcaractere++;
            cleanBuffer;
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
        printf("%s", text);
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