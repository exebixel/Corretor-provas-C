#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ncurses.h>


void menu()
{
    setlocale(LC_ALL, "");
    // inicia o ncurses
    initscr();

    // inicia suporte a cores
    start_color();
    // cria um par de cores cor do foreground branco e
    // background azul
    init_pair(1, COLOR_WHITE, COLOR_BLUE);

    // define a cor do background
    bkgd(COLOR_PAIR(1));

    // atualiza interface
    refresh();

    // variaveis com tamanho da janela 
    int windowLines = 20;
    int windowColumns = 50;

    int windowSizeColum = COLS;
    int windowSizeLine = LINES; 

    // if para limitar tamanho maxino da janela ao tamanho do terminal
    if (windowLines > windowSizeLine)
    {
        windowLines = windowSizeLine;
    }
    if (windowColumns > windowSizeColum)
    {
        windowColumns = windowSizeColum;
    }    

    // calculo para centralizar janela 
    windowSizeColum/=2;
    windowSizeLine/=2;
    windowSizeColum -= windowColumns/2;
    windowSizeLine -= windowLines/2;

    // criação da janela
    WINDOW *window;
    window = newwin(windowLines, // númeoro de linhas da janela
                    windowColumns, // número de colunas 
                    windowSizeLine, // linha que inicia a janela
                    windowSizeColum); // coluna que inicia a janela
    // atualiza janela
    wrefresh(window);
    
    // aguarda usuario digita alguma tecla
    getch();

    // deleta a janela
    delwin(window);
    // fecha ncurses
    endwin();

}

int main()
{
    menu();
    return 0;
}