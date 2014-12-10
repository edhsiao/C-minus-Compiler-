#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct info_s
{
	char* nameID;		/* nome da varivavel de entrada na tabela */
	char* scopes; 		/* nomes das funcoes que definem os escopos superiores, por exemplo: func1,func2,func3 */
	char* linesNumbers; /* linhas que a variavel aparece, por exemplo: 1,15,30 */
	char* dataType; 	/* String que representa o tipo de dado, por exemplo: int, float, array */
}info_t;

typedef struct listaEnc_s
{
	struct listaEnc_s* next; /* Proximo noh da lista */
	struct listaEnc_s* prev; /* Noh anterior */
	info_t info;
}linkedList_t;

info_t fillInfo(char* nameID, char* scopes, char* linesNumbers, char* dataType);

linkedList_t* createNewListNode();

void addNodeEnd(linkedList_t** list, linkedList_t** newNode);

void removeNode(linkedList_t* list, char* nameID);

void printInfo(info_t info);

void printList(linkedList_t* list);

info_t* findID(linkedList_t* list, char* nameID);

#endif /* LINKEDLIST_H_ */
