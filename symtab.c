/****************************************************/
/* File: symtab.c                                   */
/* Symbol table implementation for the TINY compiler*/
/* (allows only one symbol table)                   */
/* Symbol table is implemented as a chained         */
/* hash table                                       */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"
#include "globals.h"

/* SIZE is the size of the hash table */
#define SIZE 211

/* SHIFT is the power of two used as multiplier
   in hash function  */
#define SHIFT 4

/* the hash function */
static int hash ( char * key )
{
	int temp = 0;
	int i = 0;
while (key[i] != '\0')
{ temp = ((temp << SHIFT) + key[i]) % SIZE;
++i;
}
return temp;
}

/* the list of line numbers of the source 
 * code in which a variable is referenced
 */
typedef struct LineListRec
{ int lineno;
struct LineListRec * next;
} * LineList;

/* The record in the bucket lists for
 * each variable, including name, 
 * assigned memory location, and
 * the list of line numbers in which
 * it appears in the source code
 */
typedef struct BucketListRec
{ char * name;
LineList lines;
int memloc ; /* memory location for variable */
char * type;
int escopo;
char * dataType;
char * returnType;
struct BucketListRec * next;
} * BucketList;

/* the hash table */
static BucketList hashTable[SIZE];

/* Procedure st_insert inserts line numbers and
 * memory locations into the symbol table
 * loc = memory location is inserted only the
 * first time, otherwise ignored
 */
void st_insert( char * name, char * type, int escopo, char * dataType, char * returnType, int lineno, int loc )
{
	//int h = hash(strcat(name, type));
	int h1 = hash(name);
	//int h2 = hash(type);
	//BucketList l =  hashTable[(h1+h2)%SIZE];
	BucketList l =  hashTable[h1];
	while ((l != NULL)){
		if(((escopo == l->escopo)) && (strcmp(name,l->name) == 0)) /* found in table, so just add line number */
		{ LineList t = l->lines;
		while (t->next != NULL) t = t->next;
		t->next = (LineList) malloc(sizeof(struct LineListRec));
		t->next->lineno = lineno;
		t->next->next = NULL;
		break;
		}
		l = l->next;
	}
	if(l == NULL){
		l = (BucketList) malloc(sizeof(struct BucketListRec));
		l->name = name;
		l->type = type;
		l->escopo = escopo;
		l->dataType = dataType;
		l->returnType = returnType;
		l->lines = (LineList) malloc(sizeof(struct LineListRec));
		l->lines->lineno = lineno;
		l->memloc = loc;
		l->lines->next = NULL;
		l->next = hashTable[h1];
		hashTable[h1] = l;
	}
} /* st_insert */

/* Function st_lookup returns the memory 
 * location of a variable or -1 if not found
 */
int st_lookup (char * name, int escopo)
{ 
	int h1 = hash(name);
	BucketList l =  hashTable[h1];

	while ((l != NULL)){
		if((strcmp(name,l->name) == 0) && (escopo == l->escopo)){
			return l->memloc;
		}
		l = l->next;
	}
	return -1;
}

int st_lookupAux (char* name, int escopo)
{ 
	int h1 = hash(name);
	BucketList l =  hashTable[h1];

	while ((l != NULL)){
		if((strcmp(name,l->name) == 0) && (escopo == l->escopo)){
			if(strcmp(l->dataType, "INT")==0)
				return Integer;
			if(strcmp(l->dataType, "FLOAT")==0)
				return Float;
		}
		l = l->next;
	}
	return -1;
}

int st_lookupAuxFunc (char * name, int escopo)
{ 
	int h1 = hash(name);
	//int h2 = escopo;
	//BucketList l =  hashTable[(h1+h2)%SIZE];
	BucketList l =  hashTable[h1];

	while ((l != NULL)){
		if((strcmp(name,l->name) == 0) && (escopo > l->escopo)){
			if(strcmp(l->returnType, "INT") == 0) return 262;
			if(strcmp(l->returnType, "FLOAT") == 0) return 266;  
		}
		l = l->next;
	}
	return -1;
}


bool verificaMain(char * name){
//	if( getHasMain() == 0)
//		return false;
//	return true;

	return true;

//	int h1 = hash(name);
//	BucketList l =  hashTable[h1];
//
//	if(l==NULL)
//		return -1;
//	else
//		return 0;
}



/* Procedure printSymTab prints a formatted 
 * listing of the symbol table contents 
 * to the listing file
 */

void printSymTab(FILE * listing){ 
	int i;
	fprintf(listing,"Nome Variavel  Tipo Variavel  Escopo Tipo Dado  TipoRetorno  Local(hash)  Linha(s)\n");
	fprintf(listing,"-------------  -------------  ------ ---------  -----------  -----------  --------\n");

	for (i=0;i<SIZE;++i){
		if (hashTable[i] != NULL){
			BucketList l = hashTable[i];
			while (l != NULL){
				LineList t = l->lines;
				fprintf(listing,"%-14s ",l->name);
				fprintf(listing,"%-14s ",l->type);
				fprintf(listing,"%-6d ",l->escopo);
				fprintf(listing,"%-10s ", l->dataType);
				fprintf(listing,"%-11s ", l->returnType);
				fprintf(listing," %-8d  ",l->memloc);
				while (t != NULL){
					fprintf(listing,"%5d ",t->lineno);
					t = t->next;
				}
				fprintf(listing,"\n");
				l = l->next;
			}
		}
	}
} /* printSymTab */















