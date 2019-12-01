#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "corretor.c"

void file()
{
    DIR *diretorio = opendir("History");

    int cont = 0;
    while (readdir(diretorio))
    {
        cont++;
    }
    closedir(diretorio);

    corrigirProva(cont - 1);
    
}