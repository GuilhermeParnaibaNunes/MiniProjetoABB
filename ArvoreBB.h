#include "Aluno.h"

#ifndef ARVOREBB_H
#define ARVOREBB_H

/*Estrutura de nome noA*/
    // - Campo aluno: aluno do no;
    // - Campo nDir: ponteiro para o pr�ximo no a direita;
    // - Campo nEsq: ponteiro para o pr�ximo no a esquerda.
typedef struct noA {
    t_Aluno aluno;
    struct noA * nDir;
    struct noA * nEsq;
} t_noA;

/*t_ArvoreBB se torna outro nome para um ponteiro para n�s Aluno*/
typedef t_noA * t_ArvoreBB;

/*Cria um novo n� Aluno*/
    // - Retorna ponteiro para o n� criado;
    // - Sem par�metros.
t_ArvoreBB criaNoA();

/*Verifica se a �rvore est� vazia:*/
    // - Retorna 1 para verdadeiro;
    // - Retorna 0 para falso;
    // - Recebe a �rvore sob an�lise.
int Vazia(t_ArvoreBB);

/*Insere um novo n� a �rvore:*/
    // - Retorna 1 para procedimento bem-sucedido;
    // - Retorna 0 para procedimento malsucedido;
    // - Recebe a �rvore para inser��o;
    // - Recebe o elemento aluno a ser inserido.
int InserirAluno(t_ArvoreBB *, t_Aluno);

/*Remove todos os n�s de uma �rvore:*/
// - Retorna 1 para procedimento bem-sucedido;
// - Retorna 0 para �rvore vazia;
// - Recebe a �rvore sob an�lise.
int ApagaArvore(t_ArvoreBB);

/*Remove um n� por RGM:*/
    // - Retorna 1 para procedimento bem-sucedido;
    // - Retorna 0 para procedimento malsucedido;
    // - Recebe a �rvore sob analise;
    // - Recebe o RGM do n� a ser removido.
int RemoverRGM(t_ArvoreBB *, char *);

/*Procura um n� na lista pelo seu RGM:*/
    // - Retorna o item procurado;
    // - Retorna NULL para RGM n�o encontrado;
    // - Recebe a �rvore sob an�lise;
    // - Recebe o RGM a ser procurado.
t_Aluno ProcurarRGM(t_ArvoreBB *, char *);

/*Exibe aluno por RGM:*/
    // - Sem retorno;
    // - Recebe a �rvore;
    // - Recebe o RGM do n� a ser exibido.
void ExibirAlunoRGM(t_ArvoreBB, char *);

/*Exibe �rvore:*/
    // - Sem retorno;
    // - Recebe a �rvore.
void ExibirArvore(t_ArvoreBB); //DIVIDIR EM PR�, IN E P�S

#endif// ARVOREBB_H
