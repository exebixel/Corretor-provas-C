#ifndef FILE_H
#define MENU_H

// cria um novo arquivo de log
int checklog();

// adciona um novo número ao log 
void addlog(int mumeroLog);

// retorna o número do arquivo que deve ser criado 
int file();

// cria um arquivo de log
void createlog();

// checa se o arquivo "prova-%i" existe \n
// retorna 1 se existir e 0 se não existir
int checkarchive(int mumArquivo);

// imprime todo conteudo de um arquivo "prova-%i" na tela do terminal
int printarq(int numarq);

#endif