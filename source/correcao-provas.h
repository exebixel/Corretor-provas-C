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
void entradaProvas();
void corrigirProva();

#endif