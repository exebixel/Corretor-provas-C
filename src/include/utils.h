#ifndef UTILS_H
#define UTILS_H

// limpa o conteudo de uma string
void initString(char *string);

// checa se o 'name' é valido
// retorna 1 se for um nome invalido
// retorna 0 se for um nome valido
int checkName(char *name);

// checa se a alternativa digitada é valida
// retorna 1 se for uma alternativa invalida
// retorna 0 se for uma alternativa valida
// só são aceitas letras maiusculas
int checkAlternative(char alternative);

// entrada de alternativa
// test = texto que será impresso na hora de pedir a alternativa
// alter = endereço de memoria que a alternativa sera guardada
int inputAlternative(char *text, char *alter);

#endif