#include "Aluno.h"

int setAluno(t_Aluno *a, char *RGM, char *nome) {
  setRGM(*a, *RGM);
  setNome(*a, *nome);
  return 1;
}

int setNome(t_Aluno *a, char *nome){
  if(!validaNome(*nome))
    return 0;
  sizeof nameSize = strlen(nome); //VERIFICAR SE ISSO RETORNA O ESPERADO
  strncpy(a->nome, nome, nameSize);
  return 1;
}

int setRGM(t_Aluno *a, char *RGM){
  if(validaRGM(*RGM)!=1)
    return 0;
  RGM[8] = '\0';
  strncpy(a->RGM, RGM, (9*sizeof(char)));
  return 1;
}

int validaNome(char *nome){
  if(strlen(nome) > 256*sizeof(char) || strlen(nome) < 1*sizeof(char)){
    printf("\n\t*** Valor fornecido para o nome do aluno fora de padrao ***"
           "\n\t*** Nomes devem possuir no minimo 1 e no maximo 256 caracteres ***"
           "\n\t*** Por favor, forneca um nome valido ***\n");
    return 0;
  }
  for(int i = 0; i < strlen(nome); i++){ //TESTAR ISSO
    if(isdigit(nome[i])){
     printf("\n\t*** Valor fornecido para o nome do aluno fora de padrao ***"
           "\n\t*** Nome nao pode conter numeros ***"
           "\n\t*** Por favor, forneca um nome valido ***\n");
      return -1;
  }
  return 1;
}

int validaRGM(char *RGM){
  if(strlen(RGM)!=9*sizeof(char)){
    printf("\n\t*** Valor fornecido para o RGM do aluno fora de padrao ***"
           "\n\t*** Erro: numero de digitos incongruente ***"
           "\n\t*** Formato: [XXXXXXXX] (8 digitos, apenas numeros) ***"
           "\n\t*** Por favor, forneca um valor valido ***\n");
    return 0;
  }
  for(int i = 0; i<8; i++){
    if(!isdigit(RGM[i])){
     printf("\n\t*** Valor fornecido para o RGM do aluno fora de padrao ***"
            "\n\t*** Erro: caracter nao numeral foi informado ***"
            "\n\t*** Formato: [XXXXXXXX] (8 digitos, apenas numeros) ***"
            "\n\t*** Por favor, forneca um valor valido ***\n");
      return -1;
    }
  }
  return 1;
}
