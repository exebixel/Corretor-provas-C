#ifndef CORRETOR_H
#define CORRETOR_H

// guarda o número de questões cadastradas pelo usuario
int qtdQuestoes;

// guarda o número de alunos cadastrados
int qtdAlunos;

// vetor com o gabarito 
// com as respostas certas
char gabarito[100];

// guarda todos os nomes dos alunos cadastrados
char nomeAlunos[100][50];
// o 1° 100 é referente as respostas do gabarito
// o 2° 100 é referente aos alunos 
char respostasAlunos[100][100];

// corrigi as provas e cria um arquivo prova-%i na pasta de Historico
// sendo %i o número do arquivo
void corrigirProva(int numeroArquivo);

#endif