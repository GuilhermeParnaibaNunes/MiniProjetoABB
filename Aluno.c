#include "Aluno.h"

int setAluno(t_Aluno *a, char *RGM, char *nome) {
  if(!setRGM(a, RGM))
    return 0;
  if(!setNome(a, nome))
    return 0;
  return 1;
}

int setNome(t_Aluno *a, char *nome){
  if(!validaNome(nome))
    return 0;
  size_t nameSize = strlen(nome);
  if(nameSize >= sizeof(a->nome))
    nameSize = sizeof(a->nome)-1;
  strncpy(a->nome, nome, nameSize); //Reduz tamanho do array char para a string em uso
  a->nome[nameSize-1] = '\0';
  return 1;
}

int setRGM(t_Aluno *a, char *RGM){
  if(!validaRGM(RGM))
    return 0;
  strncpy(a->RGM, RGM, 9);
  a->RGM[8] = '\0';
  return 1;
}

int validaNome(char *nome){
  size_t len = strlen(nome);
  if(len < 1 || len >= 256){
    printf("\n\t*** Valor fornecido para o nome do aluno fora de padrao ***"
           "\n\t*** Nomes devem possuir no minimo 1 e no maximo 255 caracteres ***"
           "\n\t*** Por favor, forneca um nome valido ***\n");
    return ERRO_NOME_TAMANHO;
  }
  for(size_t i = 0; i < len; i++){
    if(isdigit(nome[i])){
      printf("\n\t*** Valor fornecido para o nome do aluno fora de padrao ***"
           "\n\t*** Nome nao pode conter numeros ***"
           "\n\t*** Por favor, forneca um nome valido ***\n");
      return ERRO_NOME_INVALIDO;
    }
  }
  return 1;
}

int validaRGM(char *RGM){
  if(strlen(RGM) != 9){
    printf("\n\t*** Valor fornecido para o RGM do aluno fora de padrao ***"
           "\n\t*** Erro: numero de digitos incongruente ***"
           "\n\t*** Formato: [XXXXXXXX] (8 digitos, apenas numeros) ***"
           "\n\t*** Por favor, forneca um valor valido ***\n");
    return ERRO_RGM_TAMANHO;
  }
  for(int i = 0; i < 8; i++){
    if(!isdigit(RGM[i])){
      printf("\n\t*** Valor fornecido para o RGM do aluno fora de padrao ***"
            "\n\t*** Erro: caracter nao numeral foi informado ***"
            "\n\t*** Formato: [XXXXXXXX] (8 digitos, apenas numeros) ***"
            "\n\t*** Por favor, forneca um valor valido ***\n");
      return ERRO_RGM_INVALIDO;
    }
  }
  return 1;
}
