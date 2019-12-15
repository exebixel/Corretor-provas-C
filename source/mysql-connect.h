#ifndef MYSQL_CONNECT_H
#define MYSQL_CONNECT_H

#include <mysql/mysql.h>

// Inicia a conexão com o banco de dados mysql 
MYSQL *startConnect();

// fecha a conexão com o banco de dados
void closeConnect(MYSQL *conn);

// executa comando sql no banco de dados (mariadb)
MYSQL_RES *Mycrud(char *sql);

#endif