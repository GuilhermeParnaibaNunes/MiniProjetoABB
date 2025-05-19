#include "GUI.h"

#ifndef ALUNO_H
#define ALUNO_H

typedef struct Aluno{
  char nome[256];
  char RGM[9];
} t_Aluno;

/*Setter para um aluno*/
    // - Retorna 1 para procedimento bem-sucedido;
    // - Retorna 0 para procedimento malsucedido;
    // - Recebe ponteiro para o objeto aluno;
    // - Recebe RGM a ser cadastrado;
    // - Recebe nome a ser cadastrado;
    // - Chama as funções setRGM e setNome.
int setAluno(t_Aluno *, char *, char *);

/*Setter para nome de aluno*/
    // - Retorna 1 para procedimento bem-sucedido;
    // - Retorna 0 para procedimento malsucedido;
    // - Recebe ponteiro para o objeto aluno;
    // - Recebe nome a ser cadastrado;
    // - Verifica validade pela função validaNome.
int setNome(t_Aluno *, char *);

/*Setter para RGM de aluno*/
    // - Retorna 1 para procedimento bem-sucedido;
    // - Retorna 0 para procedimento malsucedido;
    // - Recebe ponteiro para o objeto aluno;
    // - Recebe RGM a ser cadastrado;
    // - Verifica validade pela função validaRGM.
int setRGM(t_Aluno *, char *);

/*Verifica nome fornecido:*/
    // - Retorna 1 para nome válido;
    // - Retorna 0 para nome fora do padrão por quantidade de caracteres;
    // - Retorna -1 para nome fora do padrão por caracter(es) invalido(s);
    // - Recebe o pretenso nome.
int validaNome(char *);

/*Verifica RGM fornecido:*/
    // - Retorna 1 para RGM válido;
    // - Retorna 0 para RGM fora do padrão por quantidade de caracteres;
    // - Retorna -1 para RGM fora do padrão por caracter(es) invalido(s);
    // - Recebe o pretenso RGM.
int validaRGM(char *);

#endif // ALUNO_H

//Onde vão os códigos de erro???

