#include "include/utils.h"
#include <stdio.h>
#include <string.h>

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
    // int tam = strlen(string);
    int tam = sizeof(string)/sizeof(char);
    printf("tamanho: %d", tam);
    for (int  i = 0; i < tam; i++)
    {
        string[i] = 0;
    }    
}

// int main()
// {
//     int tam = 5;
//     int *prt;
//     prt = &tam;

//     printf("tam: %d", *prt);
    
// }