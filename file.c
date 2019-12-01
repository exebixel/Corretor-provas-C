#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include "corretor.c"

void file()
{
    mkdir("History", 0755);
    
    DIR *diretorio = opendir("History");

    int cont = 0;
    while (readdir(diretorio))
    {
        cont++;
    }
    closedir(diretorio);
    
    corrigirProva(cont - 1);
    
}