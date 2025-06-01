#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


#ifndef GUI_H
#define GUI_H

/*Printa na tela uma divis�ria de '-'*/
void dashDiv();

/*Printa na tela uma divis�ria de '*'*/
void astDiv();

/*Printa na tela um dado texto em formato padr�o*/
void printAsText(char *);

/*Printa na tela um dado input em formato padr�o*/
void printAsQuest(char *);

#endif //GUI_H

/* Implementar:
* PrintASText recebendo mais 2 parâmetros booleanos, definim a presença ou ausência de quebra de linha antes e depois do texto;
* Padronização de print para Elementos do tipo aluno a serem inseridos, removidos ou exibidos:
    * VERTICAL \t\tNome: %s | RGM: %s\n
    * HORIZONTAL \t\tNome: %s\n\t\tRGM: %s\n
* Padronização de print para menus;
* Impressão correta de acentuação e caracteres especiais;
*/