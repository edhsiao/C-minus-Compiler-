#include "linkedList.h"

info_t fillInfo(char* nameID, char* scopes, char* linesNumbers, char* dataType)
{
	info_t newInfo;

	newInfo.nameID = nameID;
	newInfo.scopes = scopes;
	newInfo.linesNumbers = linesNumbers;
	newInfo.dataType = dataType;

	return newInfo;
}

linkedList_t* createNewListNode()
{
	linkedList_t* newNode;

	newNode = malloc(sizeof(linkedList_t));

	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->info = fillInfo("", "", "", "");

	return newNode;
}

void addNodeEnd(linkedList_t** list, linkedList_t** newNode)
{
	linkedList_t* aux;

	if((*list)== NULL)
	{
		(*list) = (*newNode);
		return;
	}

	aux = (*list);
	while( aux->next != NULL )
		aux = aux->next;

	aux->next = (*newNode);
	(*newNode)->prev = aux;
}

void removeNode(linkedList_t* list, char* nameID)
{
	if(list == NULL)
	{
		printf("\n\nERROR: linkedList - removeNode - list = NULL");
		return;
	}

	while( list->next != NULL )
	{
		if( strcmp(list->info.nameID, nameID) == 0 )
		{
			//Remove
			list->prev->next = list->next;
			list->next->prev = list->prev;
			free(list);
		}
		list = list->next;
	}
}

void printInfo(info_t info)
{
	printf("\nInfo:\n\tnameID: %s\n\tscopes: %s\n\tlinesNumbers: %s\n\tdataType: %s\n",
			info.nameID, info.scopes, info.linesNumbers, info.dataType);
}

void printList(linkedList_t* list)
{
	printf("\n\nImprimindo lista que representa a tabela de simbolos:\n");

	if(list == NULL)
	{
		printf("\n\nERROR: linkedList - printList - list = NULL");
		return;
	}

	while( list != NULL )
	{
		printf("\n\nNoh da lista:");
		printInfo(list->info);

		printf("\nnext: ");
		if(list->next == NULL)
			printf("NULL");
		else
			printf("%s", list->next->info.nameID);

		printf("\nprev: ");
				if(list->prev == NULL)
					printf("NULL");
				else
					printf("%s", list->prev->info.nameID);

		list = list->next;
	}
}

info_t* findID(linkedList_t* list, char* nameID)
{
	linkedList_t* aux;

	if(list == NULL)
		return NULL;

	aux = list;
	while(aux != NULL)
	{
		if( strcmp(nameID, aux->info.nameID ) == 0 )
			return &(aux->info);
	}

	return NULL;
}
