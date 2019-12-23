#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "acess.h"

#define cleanBuffer while(getc(stdin) != '\n');

int main()
{
    // usuario logado
    char *user;
    // opção digitada pelo usuario
    char op;

    do {
        system("clear");
        // menu do usuario
        printf("MENU DE ACESSO \n");
        printf("l - Login \n");
        printf("c - Cadastro \n");
        printf("q - sair \n");
        printf("Escolha uma opção: ");
        scanf("%c", &op);
        
        cleanBuffer;
        
        switch (op)
        {
            // login do professor
            case 'l':
                if (user = login())
                {
                    printf("Usuario logado: %s \n", user);
                    startmenu(user);
                }
                
                break;

            // cadastro de professor
            case 'c':
                cadastro();
                cleanBuffer;
                break;

            case 'q':
                printf("Volte sempre!!! \n");
                break;

            default:
                system("clear");
                printf("DIGITE UMA OPÇÃO VALIDA!!! \n");
                break;
        }
        
    } while (op != 'q');
    return 0;
}