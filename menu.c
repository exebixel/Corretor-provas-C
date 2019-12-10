#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ncurses.h>
#include <string.h>
#include "ctl-utils.c"
#include "correcao-provas.c"

#define clearBuffer while(getchar() != '\n');
#define BG 1

// cria o menu principal e retorna a opção escolhida pelo usuario
int menu();
// direciona o usuario para as opções escolhias
void direct(int opt);

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

void direct(int opt)
{
    switch (opt)
    {
        // cadastro de aluno
        case 0:
            messageBox("Em Desenvolvimento!!!");
            break;
        
        // editar turmas
        case 1:
            messageBox("Em Desenvolvimento!!!");
            break;
        
        // correção de prova
        case 2:
            endwin();
            system("clear");
            entradaProvas();
            break;
        
        // historico de prova
        case 3:
            messageBox("Em Desenvolvimento!!!");
            break;
        
        // log out
        case 4:
            messageBox("Em Desenvolvimento!!!");
            break;
        
        // fechar programa
        case 5:
            messageBox("Volte sempre!!!");
            break;
    }
}