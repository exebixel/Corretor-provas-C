#ifndef ADD_PROVA_H
#define ADD_PROVA_H

// adiciona prova no banco de dados
// retorna id da prova adicionada
// e retorna 0 para falha
int addProva(char *nameProva, char *username);

// adiciona uma questão ao gabarito
// retorna 1 para sucesso
// e 0 para falha
int addGabarito(int prova_id, int numQuestao, char respostaQuestao);

// adiciona a resposta de um aluno para uma questão 
// retorna 1 para sucesso
// e 0 para falha
int addRespostasAlunos(int prova_id, int numQuestao, int aluno_id, char respostaQuestao);

#endif