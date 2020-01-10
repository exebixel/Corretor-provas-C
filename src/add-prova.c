#include "add-prova.h"
#include <stdio.h>
#include <stdlib.h>
#include "mysql-connect.h"

int addProva(char *nameProva, char *username)
{
    char sql[255];
    sprintf(sql, "INSERT INTO provas VALUES(NULL, '%s', '%s')",
                    nameProva, username);
    if (MyCrud(sql))
    {
        sprintf(sql, "SELECT MAX(id) FROM provas");
        MYSQL_RES *res;
        MYSQL_ROW row;
        if (res = Myselect(sql))
        {
            while (row = mysql_fetch_row(res))
            {
                return atoi(row[0]);
            }
            return 0;
        }
    }
    return 0;
}

int addGabarito(int prova_id, int numQuestao, char respostaQuestao)
{
    char sql[255];
    sprintf(sql, "INSERT INTO gabarito VALUES('%d', '%d', '%c')",
                    numQuestao, prova_id, respostaQuestao);
    if (MyCrud(sql))
    {
        return 1;
    }
    return 0;
}

int addRespostasAlunos(int prova_id, int numQuestao, int aluno_id, char     respostaQuestao)
{
    char sql[255];
    sprintf(sql, "INSERT INTO alunos_respostas VALUES('%d', '%d', '%d', '%c')",
                    numQuestao, prova_id, aluno_id, respostaQuestao);
    if (MyCrud(sql))
    {
        return 1;
    }
    return 0;
}