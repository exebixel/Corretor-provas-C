#include "include/utils.h"
#include <stdio.h>
#include <string.h>

int isSpecialCaracter(char caracter)
{
    // string com todos as caracteres qeu serão verificados
    char *blocks = "!\"#$\%&'()*+,-./:;<=>?@[\\]^_`{|}~1234567890¨°ºª§";

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