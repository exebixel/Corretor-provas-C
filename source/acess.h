#ifndef ACESS_H
#define ACESS_H

/* pede login do usuario 
 * retorna 0 para login mal sucedido
 * retorna 1 para login bem sucedido
 */
char *login();

/* cadastra um novo professor no banco de dados */
int cadastro();

/* checa se o username existe no banco de dados
 * se existir retorna 1
 * se não existir retorna 0
 */
int checkuserexist(char *user);

#endif