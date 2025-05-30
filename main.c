#include "ArvoreBB.h"

int main(){
  setlocale(LC_ALL, "Portuguese");
  char continuar = 's';
  int sel = 1, pos, cErro, val = 0;
  t_ArvoreBB alunosABB = NULL;
  t_ArvoreBB *palunosABB = &alunosABB;
  t_Aluno aluno;
  char *RGM[9], *nome[256];
  dashDiv();
  FILE *file = fopen("dados.csv", "r"); //Leitura e inserção de dados do arquivo CSV

    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    char buffer[267];
    printf("\n\t*** Carregando dados do arquivo CSV: ***\n");
    while (fgets(buffer, sizeof(buffer), file)) {
        char *token = strtok(buffer, ",");
        if (token != NULL) {
            strncpy(aluno.nome, token, 256);
        }
        token = strtok(NULL, ",");
        if (token != NULL) {
            strncpy(aluno.RGM, token, 8);
        }
        InserirAluno(palunosABB, aluno); // Mínimo de mensagens
    }
  dashDiv();

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
        }
        val = 0;
        while(!val){
          printf("\n\t*** Informe o nome do aluno: ");
          fgets(nome, sizeof(nome), stdin);
          val = validaNome(nome);
        }
        val = 0;
        cErro = setAluno(&aluno, RGM, nome);
        printf("\n\t*** %s ***\n",cErro==1? "Aluno criado com sucesso: "
               :cErro==0? "Nao foi possivel criar aluno": "Erro desconhecido");
        cErro = InserirAluno(palunosABB, aluno);
        printf("\n\t*** %s ***\n",cErro==1? "Aluno inserido com sucesso"
               :cErro==0? "Nao foi possivel inserir aluno": "Erro desconhecido");
        dashDiv();
        break;
      case 2:
        if(isVazia(alunosABB)){
          printf("\n\t*** Arvore vazia! ***\n");
          dashDiv();
          break;
        }
        printf("\n\t*** Qual o RGM do aluno que deseja apagar? ");
        while(!val){
          printf("\n\t*** Informe o RGM do aluno: ");
          fgets(RGM, sizeof(RGM), stdin);
          val = validaRGM(RGM);
        }
        val = 0;
        setRGM(&aluno, RGM); // Garante que o RGM procurado está no formato correto
        cErro = RemoverRGM(palunosABB, aluno.RGM);
        printf("\n\t*** %s ***\n",cErro==1? "Aluno removido com sucesso"
               :cErro==0? "Nao foi possivel remover aluno": "Erro desconhecido");
        dashDiv();
        break;
      case 3:
        if(isVazia(alunosABB)){
          printf("\n\t*** Arvore vazia! ***\n");
          dashDiv();
          break;
        }
        printf("\n\t*** Qual o RGM do aluno que deseja visualizar? ");
        while(!val){
          printf("\n\t*** Informe o RGM do aluno: ");
          fgets(RGM, sizeof(RGM), stdin);
          val = validaRGM(RGM);
        }
        val = 0;
        setRGM(&aluno, RGM); // Garante que o RGM procurado está no formato correto
        ExibirAlunoRGM(alunosABB, aluno.RGM);
        dashDiv();
        break;
      case 4:
        if(isVazia(alunosABB)){
          printf("\n\t*** Arvore vazia! ***\n");
          dashDiv();
          break;
        }
        cErro = ApagaArvore(palunosABB);
        printf("\n\t*** %s ***\n",cErro==1? "Arvore apagada com sucesso"
               :cErro==0? "Nao foi possivel apagar arvore": "Erro desconhecido");
        dashDiv();
        break;
      case 5:
        if(isVazia(alunosABB)){
          printf("\n\t*** Arvore vazia! ***\n");
          dashDiv();
          break;
        }
        printf("\n\t*** Escolha a forma de exibir a arvore: ***\n"
               "\t*** (1) - Pre-ordem;\n"
               "\t*** (2) - In-ordem;\n"
               "\t*** (3) - Pos-ordem.\n"
               "\t*** (4) - Exibicao grafica.\n"
               "\t*** (5) - Todas as anteriores.\n"
               "\t*** (0) - Voltar ao menu principal.\n\t");
        scanf("%d", &sel);
        getchar();
        switch(sel){
            case 1:
              printf("\n\t*** Exibindo arvore em pre-ordem: ***\n");
              ExibirArvorePre(alunosABB);
              break;
            case 2:
              printf("\n\t*** Exibindo arvore em in-ordem: ***\n");
              ExibirArvoreIn(alunosABB);
              break;
            case 3:
              printf("\n\t*** Exibindo arvore em pos-ordem: ***\n");
              ExibirArvorePos(alunosABB);
              break;
            case 4:
              printf("\n\t*** Exibindo arvore graficamente em pre-ordem: ***\n");
              ExibirArvorePre(alunosABB);
              break;
            case 5:
              ExibirArvore(alunosABB);
              break;
            case 0:
              printf("\n\t*** Voltando ao menu principal... ***\n");
              sel = 1;
              break;
            default:
              printf("\n\t*** Insira valor valida! ***\n");
              break;
          }
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
1 � INSERIR � fornecer RGM e Nome
2 � REMOVER UM N� � fornecer o RGM a remover
3 � PESQUISAR � fornecer o RGM a pesquisar
4 � ESVAZIAR A �RVORE
5 � EXIBIR A �RVORE � tr�s op��es: PR�, IN ou P�S
0 � SAIR
*/

