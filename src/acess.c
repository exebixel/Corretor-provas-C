#include "acess.h"
#include <stdio.h>
#include <string.h>
#include "mysql-connect.h"

// limpa o buffer
#define cleanBuffer while(getchar() != '\n');

char *login();
int cadastro();
// checa se deerminado nome de usuario do professor ja existe no banco de dados
int checkuserexist(char *user);
int addProf(char *username, char *name, char *password);

char *login()
{
    char username[40];
    char password[40] = "";

    printf("Digite seu nome de usuario: ");
    scanf("%40[^\n]", username);

    cleanBuffer;

    printf("Digite sua senha: ");
    scanf("%40[^\n]", password);

    // comando sql que sera executado
    char sql[255];
    sprintf(sql,
        "SELECT * FROM Professor WHERE username = '%s' AND senha = md5('%s')", 
        username, password);
    
    // retorno do comando sql
    MYSQL_RES *res;
    MYSQL_ROW row;
    if (res = Myselect(sql))
    {
        int cont = 0;
        while (row = mysql_fetch_row(res))
        {
            cont++;
        }
        if (cont == 1)
        {
            printf("login feito!!!\n");
            char *userreturn = username;
            return userreturn;
        } else
        {
            // opção de continuar do usuario
            char op;
            cleanBuffer;
            printf("Username e/ou senha incorretos!!! \n \n");
            printf("Deseja tentar novamente? (s/n): ");
            scanf("%c", &op);
            cleanBuffer;

            // se o usuario digitar "s", volta para o inico do login
            if (op == 's')
            {
                login();
            }
            return NULL;
        }   
    }
}

int cadastro()
{
    char user[40] = "";
    char name[40] = "";
    char senha[40] = "";
    char confirm[40] = "";
    // guarda o valor de retorno da função checkuserexist()
    int check = 0;
    
    // pede o nome de usuario do professor 
    do {
        printf("Digite seu nome de usuario: ");
        scanf("%40[^\n]", &user);
        
        // checa se o nome de usuario ja existe
        check = checkuserexist(user);
        if (check)
        {
            printf("Nome de usuario ja existente!!\n");
            printf("\n");
            cleanBuffer;
        }
    // repate enquanto o nome de usuario já existir no banco de dados
    } while (check);

    cleanBuffer;
    // pode o nome do professor
    printf("Digite seu nome: ");
    scanf("%40[^\n]", name);

    // pede uma senha para o novo professor
    do{
        cleanBuffer;
        // pede a senha
        printf("Digite sua senha: ");
        scanf("%40[^\n]", &senha);
        cleanBuffer;
        // pede uma confirmação da senha
        printf("Confirme sua senha: ");
        scanf("%40[^\n]", &confirm);
        
        // checa se as senhas são iguis
        if (!(strcmp(senha, confirm) == 0))
        {
            printf("Senhas diferentes\n");
            printf("Tente navomente!!!\n");
            printf("\n");
        }
    // repete enquanto as senhas forem diferentes
    } while(!(strcmp(senha, confirm) == 0));
    
    printf("\n");
    // adiciona o professor no banco de dados
    if (addProf(user, name, senha))
    {
        printf("Cadastro feito com sucesso!!! \n");
    } 
    else 
    {
        printf("Erro ao fazer cadastro!!! \n");
    }
}

int checkuserexist(char *user)
{
    // coamndo sql eecutado 
    char sql[255];
    sprintf(sql, "SELECT username FROM Professor \
                    WHERE username = '%s'", user);
    
    MYSQL_RES *res;
    MYSQL_ROW row;
    if (res = Myselect(sql))
    {
        int cont = 0;
        while (row = mysql_fetch_row(res))
        {
            cont++;
        }
        
        // se tiver retorno do banco de dabos 
        // quer dizer que o username existe 
        // então retorna 1
        // senão retorna 0
        if (cont > 0)
        {
            return 1;
        } else
        {
            return 0;
        }
    }
        
}

int addProf(char *username, char *name, char *password)
{
    char sql[255];
    sprintf(sql, "INSERT INTO Professor VALUES('%s', '%s', md5('%s'))",
            username, name, password);
    
    if (MyCrud(sql))
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}