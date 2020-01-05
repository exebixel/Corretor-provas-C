#include "include/utils.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define cleanBuffer while(getchar() != '\n')

int isSpecialCaracter(char caracter)
{
    // string com todos as caracteres que serão verificados
    char *blocks = "°ºª";
    // pega o total de caracteres de string
    int max = strlen(blocks);
    // checa se o parametro caracter é igual a algum caractere de string blocks
    for (int  i = 0; i < max; i++)
    {
        if (caracter == blocks[i])
        {
            return 1;
        }
    }
    return 0;
}

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