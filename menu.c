#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ncurses.h>
#include <string.h>

void menu();
WINDOW *createCentralizeWindow(int lines, int columns);
void printwcentralize(WINDOW *window, int line, int totalColumns, char *text);

void menu()
{
    setlocale(LC_ALL, "");
    // inicia o ncurses
    initscr();
    curs_set(0);
    // inicia suporte a cores
    start_color();
    // cria um par de cores cor do foreground branco e
    // background azul
    init_pair(1, COLOR_WHITE, COLOR_BLUE);

    // define a cor do background
    bkgd(COLOR_PAIR(1));

    // atualiza interface
    refresh();

    // cria uma janela com 30 linhas e 60 colunas 
    // e centraliza ela na tela
    WINDOW *window;
    window = createCentralizeWindow(30, 60);

    printwcentralize(window, 1, 60, "MENU \n");
    //wprintw(window, "Corrigir prova");
    printwcentralize(window, 2, 60, "Corrigir prova");

    // atualiza janela
    wrefresh(window);
    
    // aguarda usuario digita alguma tecla
    getch();

    // deleta a janela
    delwin(window);
    // fecha ncurses
    endwin();

}

WINDOW *createCentralizeWindow(int lines, int columns)
{
    int windowSizeColum = COLS;
    int windowSizeLine = LINES; 

    // if para limitar tamanho maxino da janela ao tamanho do terminal
    if (lines > windowSizeLine)
    {
        lines = windowSizeLine;
    }
    if (columns > windowSizeColum)
    {
        columns = windowSizeColum;
    }    

    // calculo para centralizar janela 
    windowSizeColum/=2;
    windowSizeLine/=2;
    windowSizeColum -= columns/2;
    windowSizeLine -= lines/2;

    // criação da janela
    WINDOW *window;
    window = newwin(lines, // númeoro de linhas da janela
                    columns, // número de colunas 
                    windowSizeLine, // linha que inicia a janela
                    windowSizeColum); // coluna que inicia a janela

    return window;
}

void printwcentralize(WINDOW *window, int line, int totalColumns, char *text)
{
    int column;
    int sizeText = strlen(text);
    column = (totalColumns/2)-(sizeText/2);
    
    mvwprintw(window, line, column, text);

}

int main()
{
    menu();
    return 0;
}