#include <mysql/mysql.h>
#include <stdio.h>

/*
 * Como não se tem Try em C é usado if no lugar
 */
MYSQL *startConnect(){
    // cria uma referencia do banco, meio que vc ta iniciando ele...
    // dizendo que vai fazer a conexão
    MYSQL *conn = mysql_init(NULL);

    /* o mysql_real_connect como o nome sugere conecta de fato com o banco de dados
     * ele tem variaos parametros, sendo os principais a referencia da conexão (conn), 
     * o ip do banco (localhost), o nome do usuario (root), a senha (toor),
     * o que vem a seguir é porta, socket essas coisas, vai ler a documentação...
     * 
     * isso esta dentro da condição de um if para tratamento de erro
     * o mysql_real_connection retorna a referencia da conexão se a conexão for bem sucedida 
     * ou nulo (NULL) se a conexão for mal sucedida
     * como qualquer valor diferente de 0 (zero) e nulo (NULL) é interpretado como verdadeiro
     * isso é usado para o tratamento de erro da conexão ou seja 
     * se der errado exibe o erro no console (printf) e para a execução
     * se der certo retorna o ponteiro da conexão
     */
    if (!mysql_real_connect(conn, "localhost", "root", "toor", NULL, 0, NULL, 0))
    {
        printf("Erro ao conectar!!! \n%u %s \n", mysql_errno(conn), mysql_error(conn));
        exit(1);
    }
    else
    {
        return conn;
    }
}

/* fecha a conexão com o banco de dados
 * me pergunto pq tenho uma função de uma linha mas ok...
 */
void closeConnect(MYSQL *conn){
    mysql_close(conn);
}


void Mycrud(char *sql){
    // usa a função acima para criar a conexão com o banco
    MYSQL *conn = startConnect();
    // testa se é uma conexão de "verdade", senão para a execução da função
    if (conn == NULL){
        exit(1);
    }
    
    /*
     * mysql_query é a função que executa comandos do mysql
     * ela precisa da referencia (ponteiro) da conexão e do comando sql como argumentos
     * tambem está no if para tratamento de erro...
     * se der errado o comando exibe o erro no console a para a execução da função
     */
    if (mysql_query(conn, sql)){
        printf("Erro ao executar comando!!! \n%u %s \n", mysql_errno(conn), mysql_error(conn));
        closeConnect(conn);
        exit(1);
    }
    
    closeConnect(conn);
}


MYSQL_RES *mySelect(char *sql){
    // cria conexão
    MYSQL *conn = startConnect();
    MYSQL_RES *res; // aqui é armasenado o retorno do comando sql
    // pelo menos eu acho que é por ai...

    // testa conexão
    if (conn == NULL){
        exit(1);
    }
    
    //exacuta o comando sql
    if (mysql_query(conn, sql)){
        printf("Erro ao recuperar arquivos!!! \n %u %s \n", mysql_errno(conn), mysql_error(conn));
        exit(1);
    }

    // armazena o retorno ou resultado do comando na variavel res que segnifica resultado
    res = mysql_store_result(conn);
    
    // fecha a conexão
    closeConnect(conn);

    /*
     * a variavel res tem o resultado do comando sql, mas esses dados não estão "tratados"
     * estão brutos e por motivos de que não se sabe o que será feito com esse resultado 
     * e para evitar um retrabalho de analize desses dados
     * ele é "entregue" bruto 
     */
    return res;
}