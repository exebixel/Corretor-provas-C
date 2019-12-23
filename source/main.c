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

    // valor 0 e 1 
    // 1 para 
    // 0 continua o loop de acesso
    int continuar = 0;

    do {
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
                    system("clear");
                    continuar = startmenu(user);
                }
                break;

            // cadastro de professor
            case 'c':
                system("clear");
                cadastro();
                system("clear");
                cleanBuffer;
                break;

            case 'q':
                continuar = 1;
                printf("Volte sempre!!! \n");
                break;

            default:
                continuar = 0;
                system("clear");
                printf("DIGITE UMA OPÇÃO VALIDA!!! \n");
                break;
        }
    } while (continuar != 1);
    return 0;
}