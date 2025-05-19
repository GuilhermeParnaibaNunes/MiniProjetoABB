#ifndef ALUNO_H
#define ALUNO_H

#include <stdio.h>
#include <ctype.h>

#define ERRO_NOME_INVALIDO  -1
#define ERRO_NOME_TAMANHO    0
#define SUCESSO              1

#define ERRO_RGM_INVALIDO   -1
#define ERRO_RGM_TAMANHO     0

typedef struct Aluno {
  char nome[256];
  char RGM[9];
} t_Aluno;

/*Setter para um aluno*/
int setAluno(t_Aluno *a, char *RGM, char *nome);

/*Setter para nome de aluno*/
int setNome(t_Aluno *a, char *nome);

/*Setter para RGM de aluno*/
int setRGM(t_Aluno *a, char *RGM);

/*Valida nome fornecido*/
int validaNome(char *nome);

/*Valida RGM fornecido*/
int validaRGM(char *RGM);

#endif // ALUNO_H

