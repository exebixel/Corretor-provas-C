#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <locale.h>
#include "menu.h"
#include "acess.h"

#define cleanBuffer while(getc(stdin) != '\n');

int main()
{
    // setlocale(LC_ALL, "");
    // // inicia o ncurses
    // initscr();
    // curs_set(0);
    // //abilita o uso dos #defines do teclado, possibilita, por exemplo a referência da tecla F1 por KEY_F1
    // keypad(stdscr, TRUE); 
    // // inicia suporte a cores
    // start_color();
    // // cria um par de cores cor do foreground branco e
    // // background azul
    // init_pair(BG, COLOR_WHITE, COLOR_BLUE);

    // // define a cor do background
    // bkgd(COLOR_PAIR(BG));
    
    // refresh();

    // int opt;
    // do
    // {
    //     opt = menu();
    //     direct(opt);
    // } while (opt != 5);
    
    // // fecha ncurses
    // endwin();

    // usuario logado
    char *user;
    // opção digitada pelo usuario
    char op;

    system("clear");
    do {
        // menu do usuario
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
                    
                }
                cleanBuffer;
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