#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ncurses.h>
#include <string.h>

#define clearBuffer while(getchar() != '\n');
#define ENTER 10

void menu();
// cria uma janela centralizada na tela do terminal
WINDOW *createCentralizeWindow(int lines, int columns);
// imprime um texto centralizado na tela
void printwcentralize(WINDOW *window, int line, int totalColumns, char *text);
int messageBox(char *menssage);

void menu()
{
    // inicia o ncurses
    initscr();
    curs_set(0);
    //abilita o uso dos #defines do teclado, possibilita, por exemplo a referência da tecla F1 por KEY_F1
    keypad(stdscr, TRUE); 
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
    window = createCentralizeWindow(15, 50);
    // cria uma borda na tela
    box(window, ACS_VLINE, ACS_HLINE);

    printwcentralize(window, 1, 50, "MENU PRINCIPAL");

    char *text[6];
    text[0] = "1 - Cadastro de aluno";
    text[1] = "2 - Editar turmas";
    text[2] = "3 - Correção de prova";
    text[3] = "4 - Historico de provas";
    text[4] = "5 - Log out";
    text[5] = "6 - Fechar programa";
    for (int i = 0; i < 6; i++)
    {
        mvwprintw(window, (i+3), 3, text[i]);
    }

    // atualiza janela
    wrefresh(window);
    
    // aguarda usuario digita alguma tecla
    getch();

   
    messageBox("Em Desenvolvimento");
   
    //getch();

    // deleta a janela
    delwin(window);
    // fecha ncurses
    endwin();
    exit(0);

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
    // pega o tamanho do texto a ser "imprimido"
    int sizeText = strlen(text);
    // calcula a coluna inicial do texto (onde ele começa)
    column = (totalColumns/2)-(sizeText/2);
    // imprime na tela
    mvwprintw(window, line, column, text);
}

int messageBox(char *message)
{
    WINDOW *winbox;
    // cria uma janela centralizada de 5/15
    winbox = createCentralizeWindow(5, 30);
    // cria uma linha al redor da janela
    box(winbox, ACS_VLINE, ACS_HLINE);
    printwcentralize(winbox, 1, 30, message);
    wrefresh(winbox);
    //clearBuffer;
    int key;
    do
    {
        key = getch();
    } while (key != ENTER);
    
    delwin(winbox);
    
    
}

int main()
{
    setlocale(LC_ALL, "");
    menu();
    return 0;
}