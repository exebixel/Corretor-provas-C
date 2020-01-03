#ifndef CORRETOR_H
#define CORRETOR_H

int qtdQuestoes;
int qntAlunos;
char gabarito[100];
char nomeAlunos[100][50];
// o 1° 100 é referente as respostas do gabarito
// o 2° 100 é referente aos alunos 
char respostasAlunos[100][100];

// corrigi as provas e cria um arquivo History/prova-%i
// sendo %i o número do arquivo
void corrigirProva(int numeroArquivo);

#endif