#include "ArvoreBB.h"

t_ArvoreBB criaNoA() {
    t_ArvoreBB novo = (t_ArvoreBB) malloc(sizeof(t_noA));
    if(novo == NULL) {
        printf("\n\t*** Erro ao alocar memória para novo nó. ***");
        return NULL; // Retorna NULL se não conseguir alocar memória
    }
    if (novo) {
        novo->nDir = NULL;
        novo->nEsq = NULL;
    }
    return novo;
}

int isVazia(t_ArvoreBB arvore) {
    return (arvore == NULL);
}

static int comparaRGM(char *r1, char *r2) {
    return strcmp(r1, r2);
}

int InserirAluno(t_ArvoreBB *arvore, t_Aluno aluno) {
    if (isVazia(arvore)){
        printf("\n\t*** Ponteiro para arvore invalido. ***");
        return 0;
    }

    if (*arvore == NULL) {
        printf("\n___DEBUG: (*arvore == NULL)\n");
        *arvore = criaNoA();
        if (*arvore == NULL){
            printf("\n___DEBUG: (*arvore == NULL) - 2\n");
            return 0; // Retorna 0 se não conseguir alocar memória
        }
        (*arvore)->aluno = aluno;
        printf("\n\t*** Aluno inserido com sucesso: Nome: %s | RGM: [%s] ***\n", aluno.nome, aluno.RGM);
        printf("\n\t*** Aluno inserido com sucesso: Nome: %s | RGM: [%s] ***\n", (*arvore)->aluno.nome, (*arvore)->aluno.RGM);
        return 1;
    }

    printf("\n___DEBUG: (*arvore != NULL)\n");
    printf("\n\t*** Tentando inserir aluno: Nome: %s | RGM: [%s] ***\n", aluno.nome, aluno.RGM);
    printf("\n\t*** Aluno atual: Nome: %s | RGM: %s ***\n", (*arvore)->aluno.nome, (*arvore)->aluno.RGM);
    printf("\n\t*** Comparando RGM: %s com %s ***\n", aluno.RGM, (*arvore)->aluno.RGM);
    int cmp = comparaRGM(aluno.RGM, (*arvore)->aluno.RGM);

    if (cmp == 0) {
        printf("\n\t*** O RGM fornecido ja existe na arvore, por isso nao eh possivel inseri-lo. ***");
        return 0;
    } else if (cmp > 0) {
        return InserirAluno(&(*arvore)->nDir, aluno);
    } else {
        return InserirAluno(&(*arvore)->nEsq, aluno);
    }
}

int ApagaArvore(t_ArvoreBB *arvore) {
    if (arvore == NULL || *arvore == NULL){
        return 0;
    }

    ApagaArvore((*arvore)->nDir);
    ApagaArvore((*arvore)->nEsq);
    printf("\n\t*** Apagando aluno: Nome: %s | RGM: [%s] ***\n", (*arvore)->aluno.nome, (*arvore)->aluno.RGM);
    free((*arvore));
    (*arvore) = NULL; // Atribui NULL para o ponteiro da árvore para evitar dangling pointers
    return 1;
}

static t_ArvoreBB minimoNo(t_ArvoreBB no) {
    while (no && no->nEsq != NULL) {
        no = no->nEsq;
    }
    return no;
}

int RemoverRGM(t_ArvoreBB *arvore, char *RGM) {
    if (arvore == NULL){
        return 0;
    }
    if(*arvore == NULL) {
        printf("\n\t*** Ponteiro para arvore invalido. ***");
        return 0;
    }

    printf("\n___DEBUG: (*arvore != NULL)\n");
    printf("\n\t*** Comparando RGM: %s com [%s] ***\n", RGM, (*arvore)->aluno.RGM);
    int cmp = comparaRGM(RGM, (*arvore)->aluno.RGM);

    if (cmp > 0) {
        return RemoverRGM(&(*arvore)->nDir, RGM);
    } else if (cmp < 0) {
        return RemoverRGM(&(*arvore)->nEsq, RGM);
    } else {
        printf("\t*** Aluno a ser removido: ***\n\t\tNome: %s\n\t\tRGM: [%s]", (*arvore)->aluno.nome, (*arvore)->aluno.RGM);
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

t_Aluno ProcurarRGM(t_ArvoreBB *arvore, char *RGM) {
    t_Aluno vazio;
    vazio.RGM[0] = '\0';
    vazio.nome[0] = '\0';

    if (arvore == NULL){
        return vazio;
    }
    if(*arvore == NULL){
        printf("\n\t*** Ponteiro para arvore ou arvore invalido(a). ***");
        return vazio; // Retorna aluno vazio se a árvore for inválida
    }

    int cmp = comparaRGM(RGM, (*arvore)->aluno.RGM);

    if (cmp == 0) {
        return (*arvore)->aluno;
    } else if (cmp > 0) {
        return ProcurarRGM(&(*arvore)->nDir, RGM);
    } else {
        return ProcurarRGM(&(*arvore)->nEsq, RGM);
    }
}

void ExibirAlunoRGM(t_ArvoreBB arvore, char *RGM) {
    t_Aluno aluno = ProcurarRGM(&arvore, RGM);
    if (aluno.RGM[0] == '\0') {
        printf("\t*** Aluno com RGM %s nao encontrado. ***", RGM);
    } else {
        printf("\t*** Aluno encontrado: ***\n\t\tNome: %s\n\t\tRGM: [%s]\n", aluno.nome, aluno.RGM);
    }
}

void ExibirArvore(t_ArvoreBB arvore) {
    if (arvore == NULL) {
        return;
    }
    printf("\n\t*** Arvore em pre-ordem: ***\n");
    ExibirArvorePre(arvore);
    printf("\n\t*** Arvore em in-ordem: ***\n");
    ExibirArvoreIn(arvore);
    printf("\n\t*** Arvore em pos-ordem: ***\n");
    ExibirArvorePos(arvore);
    printf("\n\t*** Exibicao grafica de arvore em pre-ordem: ***\n");

}

void ExibirArvorePre(t_ArvoreBB arvore){
    if (arvore == NULL) {
        return;
    }
    printf("\t\tNome: %s | RGM: %s\n", arvore->aluno.nome, arvore->aluno.RGM);
    ExibirArvorePre(arvore->nEsq);
    ExibirArvorePre(arvore->nDir);
}

void ExibirArvoreIn(t_ArvoreBB arvore){
    if (arvore == NULL) {
        return;
    }
    ExibirArvoreIn(arvore->nEsq);
    printf("\t\tNome: %s | RGM: %s\n", arvore->aluno.nome, arvore->aluno.RGM);
    ExibirArvoreIn(arvore->nDir);
}

void ExibirArvorePos(t_ArvoreBB arvore){
    if (arvore == NULL) {
        return;
    }
    ExibirArvorePos(arvore->nEsq);
    ExibirArvorePos(arvore->nDir);
    printf("\t\tNome: %s | RGM: %s\n", arvore->aluno.nome, arvore->aluno.RGM);
}

void ExibirArvoreGUIPre(t_ArvoreBB arvore){
    if (arvore == NULL) {
        return;
    }
//IMPLEMENTAÇÃO DA FUNÇÃO PARA EXIBIR A ÁRVORE GRAFICAMENTE EM PRÉ-ORDEM
}
