#ifndef ADD_PROVA_H
#define ADD_PROVA_H

// adiciona prova no banco de dados
// retorna 1 para sucesso 
// e 0 para falha
int addProva(char *nameProva, char *username);

// adiciona uma questão ao gabarito
// retorna 1 para sucesso
// e 0 para falha
int addGabarito(int prova_id, int numQuestao, char respostaQuestao);

// adiciona a resposta de um aluno para uma questão 
// retorna 1 para sucesso
// e 0 para falha
int addRespostasAlunos(int numQuestao, int prova_id, int aluno_id, char *respostaQuestao);

#endif