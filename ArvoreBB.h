#include "Aluno.h"

#ifndef ARVOREBB_H
#define ARVOREBB_H

/*Estrutura de nome noA*/
    // - Campo aluno: aluno do no;
    // - Campo nDir: ponteiro para o próximo no a direita;
    // - Campo nEsq: ponteiro para o próximo no a esquerda.
typedef struct noA {
    t_Aluno aluno;
    struct noA * nDir;
    struct noA * nEsq;
} t_noA;

/*t_ArvoreBB se torna outro nome para um ponteiro para nós Aluno*/
typedef t_noA * t_ArvoreBB;

/*Cria um novo nó Aluno*/
    // - Retorna ponteiro para o nó criado;
    // - Sem parâmetros.
t_ArvoreBB criaNoA();

/*Verifica se a árvore está vazia:*/
    // - Retorna 1 para verdadeiro;
    // - Retorna 0 para falso;
    // - Recebe a árvore sob análise.
int Vazia(t_ArvoreBB);

/*Insere um novo nó a árvore:*/
    // - Retorna 1 para procedimento bem-sucedido;
    // - Retorna 0 para procedimento malsucedido;
    // - Recebe a árvore para inserção;
    // - Recebe o elemento aluno a ser inserido.
int InserirAluno(t_ArvoreBB *, t_Aluno);

/*Remove todos os nós de uma árvore:*/
// - Retorna 1 para procedimento bem-sucedido;
// - Retorna 0 para árvore vazia;
// - Recebe a árvore sob análise.
int ApagaArvore(t_ArvoreBB);

/*Remove um nó por RGM:*/
    // - Retorna 1 para procedimento bem-sucedido;
    // - Retorna 0 para procedimento malsucedido;
    // - Recebe a árvore sob analise;
    // - Recebe o RGM do nó a ser removido.
int RemoverRGM(t_ArvoreBB *, char *);

/*Procura um nó na lista pelo seu RGM:*/
    // - Retorna o item procurado;
    // - Retorna NULL para RGM não encontrado;
    // - Recebe a árvore sob análise;
    // - Recebe o RGM a ser procurado.
t_Aluno ProcurarRGM(t_ArvoreBB *, char *);

/*Exibe aluno por RGM:*/
    // - Sem retorno;
    // - Recebe a árvore;
    // - Recebe o RGM do nó a ser exibido.
void ExibirAlunoRGM(t_ArvoreBB, char *);

/*Exibe árvore:*/
    // - Sem retorno;
    // - Recebe a árvore.
void ExibirArvore(t_ArvoreBB); //DIVIDIR EM PRÉ, IN E PÓS

#endif// ARVOREBB_H
