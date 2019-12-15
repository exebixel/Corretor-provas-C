#ifndef CTL_UTILS_H
#define CTL_UTILS_h

#include <ncurses.h>

// define o valor da tecla enter
#define ENTER 10

// cria uma janela centralizada na tela do terminal
WINDOW *createCentralizeWindow(int lines, int columns);
// imprime um texto centralizado na tela
void printwcentralize(WINDOW *window, int line, char *text);
// cria uma janela com uma mensagem que é passada pelo parametro
int messageBox(char *menssage);

#endif