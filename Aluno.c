#include "Aluno.h"
#include <string.h>

int setAluno(t_Aluno *a, char *RGM, char *nome) {
  if(!setRGM(a, RGM)) return 0;
  if(!setNome(a, nome)) return 0;
  return 1;
}

int setNome(t_Aluno *a, char *nome){
  int val = validaNome(nome);
  if(val != SUCESSO)
    return 0;
  size_t nameSize = strlen(nome);
  if(nameSize >= sizeof(a->nome))
    nameSize = sizeof(a->nome) - 1;
  strncpy(a->nome, nome, nameSize);
  a->nome[nameSize] = '\0'; // garante terminação
  return 1;
}

int setRGM(t_Aluno *a, char *RGM){
  int val = validaRGM(RGM);
  if(val != SUCESSO)
    return 0;
  strncpy(a->RGM, RGM, 8);
  a->RGM[8] = '\0'; // garante terminação
  return 1;
}

int validaNome(char *nome){
  size_t len = strlen(nome);
  if(len < 1 || len >= 256){
    printf("\n\t*** Nome deve ter entre 1 e 255 caracteres ***\n");
    return ERRO_NOME_TAMANHO;
  }
  for(size_t i = 0; i < len; i++){
    if(isdigit(nome[i])){
      printf("\n\t*** Nome não pode conter números ***\n");
      return ERRO_NOME_INVALIDO;
    }
  }
  return SUCESSO;
}

int validaRGM(char *RGM){
  if(strlen(RGM) != 8){
    printf("\n\t*** RGM deve ter exatamente 8 dígitos ***\n");
    return ERRO_RGM_TAMANHO;
  }
  for(int i = 0; i < 8; i++){
    if(!isdigit(RGM[i])){
      printf("\n\t*** RGM deve conter apenas números ***\n");
      return ERRO_RGM_INVALIDO;
    }
  }
  return SUCESSO;
}
