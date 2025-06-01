#include "GUI.h"

#ifndef ALUNO_H
#define ALUNO_H

#define ERRO_NOME_INVALIDO  0
#define ERRO_NOME_TAMANHO   0

#define ERRO_RGM_INVALIDO   0
#define ERRO_RGM_TAMANHO    0

typedef struct Aluno {
  char nome[256];
  char RGM[9];
} t_Aluno;

/*Setter para um aluno*/
    // - Retorna 1 para procedimento bem-sucedido;
    // - Retorna 0 para procedimento malsucedido;
    // - Recebe ponteiro para o objeto aluno;
    // - Recebe RGM a ser cadastrado;
    // - Recebe nome a ser cadastrado;
    // - Chama as fun��es setRGM e setNome.
int setAluno(t_Aluno *, char *, char *);

/*Setter para nome de aluno*/
    // - Retorna 1 para procedimento bem-sucedido;
    // - Retorna 0 para procedimento malsucedido;
    // - Recebe ponteiro para o objeto aluno;
    // - Recebe nome a ser cadastrado;
    // - Verifica validade pela fun��o validaNome.
int setNome(t_Aluno *, char *);

/*Setter para RGM de aluno*/
    // - Retorna 1 para procedimento bem-sucedido;
    // - Retorna 0 para procedimento malsucedido;
    // - Recebe ponteiro para o objeto aluno;
    // - Recebe RGM a ser cadastrado;
    // - Verifica validade pela fun��o validaRGM.
int setRGM(t_Aluno *, char *);

/*Verifica nome fornecido:*/
    // - Retorna 1 para nome v�lido;
    // - Retorna 0 para nome fora do padr�o por quantidade de caracteres;
    // - Retorna -1 para nome fora do padr�o por caracter(es) invalido(s);
    // - Recebe o pretenso nome.
int validaNome(char *);

/*Verifica RGM fornecido:*/
    // - Retorna 1 para RGM v�lido;
    // - Retorna 0 para RGM fora do padr�o por quantidade de caracteres;
    // - Retorna -1 para RGM fora do padr�o por caracter(es) invalido(s);
    // - Recebe o pretenso RGM.
int validaRGM(char *);

#endif // ALUNO_H
