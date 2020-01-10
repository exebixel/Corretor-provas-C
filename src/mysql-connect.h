#ifndef MYSQL_CONNECT_H
#define MYSQL_CONNECT_H

#include <mysql/mysql.h>

// executa comando sql no banco de dados (mariadb)
// e retorna o resultado da busca (select) MYSQL_RES
MYSQL_RES *Myselect(char *sql);

// executa um comando sql 
// se o comando for bem sucedidio retorna 1
// se ouver algum erro retorna 0
int MyCrud(char *sql);

#endif