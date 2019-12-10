#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "menu.c"

int main()
{
    setlocale(LC_ALL, "");
    // inicia o ncurses
    initscr();
    curs_set(0);
    //abilita o uso dos #defines do teclado, possibilita, por exemplo a referência da tecla F1 por KEY_F1
    keypad(stdscr, TRUE); 
    // inicia suporte a cores
    start_color();
    // cria um par de cores cor do foreground branco e
    // background azul
    init_pair(BG, COLOR_WHITE, COLOR_BLUE);

    // define a cor do background
    bkgd(COLOR_PAIR(BG));
    
    refresh();

    int opt;
    do
    {
        opt = menu();
        direct(opt);
    } while (opt != 5);
    
    // fecha ncurses
    endwin();
    return 0;
}