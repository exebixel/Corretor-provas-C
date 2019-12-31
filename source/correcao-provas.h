#ifndef CORRECAO_PROVAS_H
#define CORRECAO_PROVAS_H

int qtdQuestoes;
int qntAlunos;
char gabarito[100];
char nomeAlunos[100][50];
// o 1° 100 é referente as respostas do gabarito
// o 2° 100 é referente aos alunos 
char respostasAlunos[100][100];

void entradaGabarito();
void entradaAluno();

// pede prova, gabarito e respostas ao usuario
// adiciona os dados no BD 
// retorna 0 para sucesso 
// retonra 1 para falha
int entradaProvas(char *username);
void corrigirProva(int numeroArquivo);

#endif