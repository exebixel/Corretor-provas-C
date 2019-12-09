#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ncurses.h>
#include <string.h>

#define clearBuffer while(getchar() != '\n');
// define o valor da tecla enter
#define ENTER 10

int menu();
// cria uma janela centralizada na tela do terminal
WINDOW *createCentralizeWindow(int lines, int columns);
// imprime um texto centralizado na tela
void printwcentralize(WINDOW *window, int line, char *text);
// cria uma janela com uma mensagem que é passada pelo parametro
int messageBox(char *menssage);

int menu()
{
    // cria uma janela com 30 linhas e 60 colunas 
    // e centraliza ela na tela
    WINDOW *winMenu;
    winMenu = createCentralizeWindow(15, 50);
    // cria uma borda na tela
    box(winMenu, ACS_VLINE, ACS_HLINE);

    printwcentralize(winMenu, 1, "MENU PRINCIPAL");

    char *text[6];
    text[0] = "1 - Cadastro de aluno    ";
    text[1] = "2 - Editar turmas        ";
    text[2] = "3 - Correção de prova    ";
    text[3] = "4 - Historico de provas  ";
    text[4] = "5 - Log out              ";
    text[5] = "6 - Fechar programa      ";
    
    // pega a entrada do teclado do usuario
    int key;
    // guarda a opção selecionada
    int selectOption = 0;
    while (1)
    {
        // loop para atualizar as opções do usuario
        for (int i = 0; i < 6; i++)
        {
            // checa qual opção esta setada
            if (i == selectOption)
            {
                wattron(winMenu, A_REVERSE);
            }
            // imprime as opções de novo 
            mvwprintw(winMenu, i+3, 3, text[i]);
            wattroff(winMenu, A_REVERSE);
            wrefresh(winMenu);
        }
        // pega a tecla digitada pelo usuario
        key = getch();
        switch (key)
        {
            // caso for seta pra baixo
            case KEY_DOWN:
                // checa se pode descer mais uma opção 
                // se não volta pra cima
                if (selectOption == 5)
                {
                    selectOption = 0;
                }
                else
                {
                    selectOption++;
                }            
                break;
            case KEY_UP:
                //  checa se pode subir mais uma opção 
                // se não volta pra baixo
                if (selectOption == 0)
                {
                    selectOption = 5;
                }
                else
                {
                    selectOption--;
                }
                break;
            default:
                break;
        }
        // se precionar enter sai do loop do while 
        if (key == ENTER)
        {
            break;
        }
    }

    delwin(winMenu);
    
    return selectOption;

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
    window = newwin(lines, // número de linhas da janela
                    columns, // número de colunas 
                    windowSizeLine, // linha que inicia a janela
                    windowSizeColum); // coluna que inicia a janela

    return window;
}

void printwcentralize(WINDOW *window, int line, char *text)
{
    int maxColumns = getmaxx(window);
    int column;
    // pega o tamanho do texto a ser "imprimido"
    int sizeText = strlen(text);
    // calcula a coluna inicial do texto (onde ele começa)
    column = (maxColumns/2)-(sizeText/2);
    // imprime na tela
    mvwprintw(window, line, column, text);
}

int messageBox(char *message)
{
    int num = strlen(message);
    WINDOW *winbox;
    // cria uma janela centralizada
    winbox = createCentralizeWindow(5, num + 5);
    // cria uma linha ao redor da janela
    box(winbox, ACS_VLINE, ACS_HLINE);
    printwcentralize(winbox, 1, message);

    // cria um "botão de OK"
    wattron(winbox, A_REVERSE);
    printwcentralize(winbox, 3, "| OK |");
    wattroff(winbox, A_REVERSE);

    // atualiza a janela, sem isso não mostra a janela
    wrefresh(winbox);

    // não fecha a janela até o usuario digitar enter
    int key;
    do
    {
        key = getch();
    } while (key != ENTER);
    
    // deleta a janela
    delwin(winbox);

}

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
    init_pair(1, COLOR_WHITE, COLOR_BLUE);

    // define a cor do background
    bkgd(COLOR_PAIR(1));
    
    refresh();

    int opt = menu();

    char message[30];
    sprintf(message, "Número de opção escolhida: %d", opt+1);
    messageBox(message);
    // fecha ncurses
    endwin();
    return 0;
}