#include "ArvoreBB.h"

int main(){
  char continuar = 's';
  int sel = 1, pos, cErro, val = 0;
  t_ArvoreBB alunosABB;
  t_ArvoreBB *palunosABB = &alunosABB;
  char *RGM[9], *nome[256];
  dashDiv();

  /*LEITURA DOS DADOS DO ARQUIVO*/

  printf("\n\t*** Seja bem-vindo(a) ao nosso Sistema de Alunos (ABB)! ***\n");
  dashDiv();

  while(sel){
    printf("\t******MENU******\n"
           "\t*** (1) - Cadastrar aluno;\n"
           "\t*** (2) - Apagar aluno por RGM;\n"
           "\t*** (3) - Exibir aluno por RGM;\n"
           "\t*** (4) - Reiniciar sistema;\n"
           "\t*** (5) - Exibir alunos;\n"
           "\t*** (0) - Sair do sistema.\n\t");
    scanf("%d", &sel);
    getchar();
    switch(sel){
      case 1:
        while(!val){
          printf("\n\t*** Informe o RGM do aluno: ");
          fgets(RGM, sizeof(RGM), stdin);
          val = validaRGM(RGM);
        } //Validar aqui, ou só na inserção?
        while(!val){
          printf("\n\t*** Informe o nome do aluno: ");
          fgets(nome, sizeof(nome), stdin);
          val = validaRGM(nome);
        } //Validar aqui, ou só na inserção?
        InserirAluno(palunosABB, t_Aluno); //INSERIR ALUNO
        dashDiv();
        break;
      case 2:
        printf("\n\t*** Qual o RGM do aluno que deseja apagar? ");
        while(!val){
          printf("\n\t*** Informe o RGM do aluno: ");
          fgets(RGM, sizeof(RGM), stdin);
          val = validaRGM(RGM);
        }
        val = 0;
        cErro = RemoverRGM(palunosABB, RGM); //APAGAR ALUNO POR RGM
        printf("\n\t*** %s ***\n",cErro==1? "Aluno removido com sucesso"
               :cErro==-1? "RGM nao encontrado":cErro==-2? "Arvore invalida"
               :cErro==-3? "Arvore vazia": "Erro desconhecido");
        dashDiv();
        break;
      case 3:
        printf("\n\t*** Qual o RGM do aluno que deseja visualizar? ");
        while(!val){
          printf("\n\t*** Informe o RGM do aluno: ");
          fgets(RGM, sizeof(RGM), stdin);
          val = validaRGM(RGM);
        }
        val = 0;
        ExibirAlunoRGM(palunosABB, RGM); //EXIBIR ALUNO POR RGM
        dashDiv();
        break;
      case 4:
        ApagaArvore(palunosABB); //APAGAR ÁRVORE INTEIRA
        dashDiv();
        break;
      case 5:
        //SELEÇÃO DO TIPO DA EXIBIÇÃO DE ÁRVORE: PRÉ, IN ou PÓS
        printf("\n\t*** Lista completa do SA ***\n");
        ExibirArvore(palunosABB);
        dashDiv();
        break;
      case 0:
        printf("\t*** Ate mais! ***\n");
        return 1;
      default:
        printf("\t*** Insira valor valido ***\n");
        break;
    }
  }
}

/*
1 – INSERIR – fornecer RGM e Nome
2 – REMOVER UM NÓ – fornecer o RGM a remover
3 – PESQUISAR – fornecer o RGM a pesquisar
4 – ESVAZIAR A ÁRVORE
5 – EXIBIR A ÁRVORE – três opções: PRÉ, IN ou PÓS
0 – SAIR
*/

