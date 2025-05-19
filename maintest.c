#include <stdio.h>
#include <string.h>
#include "Aluno.h"
#include "ArvoreBB.h"

int main() {
    t_ArvoreBB arvore = NULL; // árvore vazia

    t_Aluno aluno1, aluno2, aluno3, aluno4, aluno5, aluno6;

    setAluno(&aluno1, "38887479", "Guilherme Parnaíba Nunes");
    setAluno(&aluno2, "37366041", "Tasso Tanouss");
    setAluno(&aluno3, "44477945", "Layssa Evellyn Martins dos Santos");
    setAluno(&aluno4, "37405624", "Matheus Ferreira Amaral");
    setAluno(&aluno5, "38503239", "Yuri Fernandes de França Leal");
    setAluno(&aluno6, "03844371", "Luiz Henrique de Lima");

    printf("Inserindo alunos na árvore...\n");
    InserirAluno(&arvore, aluno1);
    InserirAluno(&arvore, aluno2);
    InserirAluno(&arvore, aluno3);
    InserirAluno(&arvore, aluno4);
    InserirAluno(&arvore, aluno5);
    InserirAluno(&arvore, aluno6);

    printf("\nÁrvore após inserções:\n");
    ExibirArvore(arvore);

    char buscaRGM[] = "37366041"; // buscando Tasso Tanouss
    printf("\nBuscando aluno com RGM %s...\n", buscaRGM);
    t_Aluno achado = ProcurarRGM(&arvore, buscaRGM);
    if (strlen(achado.RGM) > 0) {
        printf("Aluno encontrado: %s - %s\n", achado.RGM, achado.nome);
    } else {
        printf("Aluno não encontrado.\n");
    }

    printf("\nRemovendo aluno com RGM %s...\n", buscaRGM);
    RemoverRGM(&arvore, buscaRGM);

    printf("\nÁrvore após remoção:\n");
    ExibirArvore(arvore);

    ApagaArvore(arvore);

    return 0;
}
