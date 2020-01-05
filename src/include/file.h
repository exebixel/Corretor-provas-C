#ifndef FILE_H
#define FILE_H

// nome do diretorio que será criado na HOME 
// e que conterá o historico de provas
#define DIRNAME "Historico"

// checa a existencia do log 
// se não existir ele é criado 
// retorna o maior número encontrado no log
int checklog();

// atualiza o número de arquivo do log
void addlog(int numeroLog);

// faz todas as verificações necessarias
// e retorna o número do proximo arquivo da prova a ser criado
int file();

// cria um arquivo de log 
// e salva o maior número de arquivo encontrado na pasta
void createlog();

// checa se o arquivo com o número 'numArquivo' existe
// se existir retorna 1
// se não existir retorna 0
int checkarchive(int numArquivo);

// imprime o conteudo de um arquivo na tela
// se o arquivo não existir retorna 0
// se o arquivo for impresso com sucesso retorna 1
int printarq(int numarq);

#endif
