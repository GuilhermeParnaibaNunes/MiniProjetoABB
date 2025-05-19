#include "ArvoreBB.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cria um nó novo, aloca memória e inicializa campos
t_ArvoreBB criaNoA() {
    t_ArvoreBB novo = (t_ArvoreBB) malloc(sizeof(t_noA));
    if (novo) {
        novo->nDir = NULL;
        novo->nEsq = NULL;
        // Pode inicializar campos do aluno se quiser, mas não obrigatório
    }
    return novo;
}

// Verifica se árvore é vazia (NULL)
int Vazia(t_ArvoreBB arvore) {
    return (arvore == NULL) ? 1 : 0;
}

// Função auxiliar para comparar RGM dos alunos (string de 8 dígitos)
static int comparaRGM(char *r1, char *r2) {
    return strcmp(r1, r2);
}

// Insere aluno na ABB
int InserirAluno(t_ArvoreBB *arvore, t_Aluno aluno) {
    if (arvore == NULL) return 0;

    if (*arvore == NULL) {
        *arvore = criaNoA();
        if (*arvore == NULL) return 0;
        (*arvore)->aluno = aluno;
        return 1;
    }

    int cmp = comparaRGM(aluno.RGM, (*arvore)->aluno.RGM);

    if (cmp == 0) {
        // RGM já existe na árvore, não insere duplicado
        return 0;
    } else if (cmp < 0) {
        return InserirAluno(&(*arvore)->nEsq, aluno);
    } else {
        return InserirAluno(&(*arvore)->nDir, aluno);
    }
}

// Apaga todos os nós da árvore recursivamente
int ApagaArvore(t_ArvoreBB arvore) {
    if (arvore == NULL) return 0;

    ApagaArvore(arvore->nEsq);
    ApagaArvore(arvore->nDir);

    free(arvore);
    return 1;
}

// Função auxiliar para encontrar nó com menor RGM na subárvore (para remoção)
static t_ArvoreBB minimoNo(t_ArvoreBB no) {
    while (no && no->nEsq != NULL) {
        no = no->nEsq;
    }
    return no;
}

// Remove nó por RGM da árvore
int RemoverRGM(t_ArvoreBB *arvore, char *RGM) {
    if (arvore == NULL || *arvore == NULL) return 0;

    int cmp = comparaRGM(RGM, (*arvore)->aluno.RGM);

    if (cmp < 0) {
        return RemoverRGM(&(*arvore)->nEsq, RGM);
    } else if (cmp > 0) {
        return RemoverRGM(&(*arvore)->nDir, RGM);
    } else {
        // Nó encontrado, remover
        if ((*arvore)->nEsq == NULL) {
            t_ArvoreBB temp = (*arvore)->nDir;
            free(*arvore);
            *arvore = temp;
            return 1;
        } else if ((*arvore)->nDir == NULL) {
            t_ArvoreBB temp = (*arvore)->nEsq;
            free(*arvore);
            *arvore = temp;
            return 1;
        }

        // Nó com dois filhos: pegar menor da direita para substituir
        t_ArvoreBB temp = minimoNo((*arvore)->nDir);
        (*arvore)->aluno = temp->aluno;
        return RemoverRGM(&(*arvore)->nDir, temp->aluno.RGM);
    }
}

// Procura aluno pelo RGM, retorna cópia do aluno ou aluno com RGM vazio se não achar
t_Aluno ProcurarRGM(t_ArvoreBB *arvore, char *RGM) {
    t_Aluno vazio;
    vazio.RGM[0] = '\0';
    vazio.nome[0] = '\0';

    if (arvore == NULL || *arvore == NULL) return vazio;

    int cmp = comparaRGM(RGM, (*arvore)->aluno.RGM);

    if (cmp == 0) {
        return (*arvore)->aluno;
    } else if (cmp < 0) {
        return ProcurarRGM(&(*arvore)->nEsq, RGM);
    } else {
        return ProcurarRGM(&(*arvore)->nDir, RGM);
    }
}

// Exibe aluno de acordo com o RGM (chama ProcurarRGM)
void ExibirAlunoRGM(t_ArvoreBB arvore, char *RGM) {
    t_Aluno aluno = ProcurarRGM(&arvore, RGM);
    if (aluno.RGM[0] == '\0') {
        printf("Aluno com RGM %s nao encontrado.\n", RGM);
    } else {
        printf("Aluno encontrado:\nNome: %s\nRGM: %s\n", aluno.nome, aluno.RGM);
    }
}

// Exibe a árvore em ordem (in-order)
void ExibirArvore(t_ArvoreBB arvore) {
    if (arvore == NULL) return;
    ExibirArvore(arvore->nEsq);
    printf("Nome: %s | RGM: %s\n", arvore->aluno.nome, arvore->aluno.RGM);
    ExibirArvore(arvore->nDir);
}
