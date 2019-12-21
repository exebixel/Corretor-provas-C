#ifndef MENU_H
#define MENU_H

#include <ncurses.h>

#define BG 1

// gerancia o menu do usario
void startmenu(char *username);
int menu();
void direct(int opt, char *username);

#endif