#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

extern FILE* source;			/* Arquivo de entrada com o codigo fonte a ser compilado. */
extern FILE* listing; 			/* Saida de mensagens de print, arquivo ou o proprio terminal. */
extern int lineno; 				/* Linha do source sendo analisada no momento. */
extern int col; 				/* Coluna do caracter sendo analisado no momento. */

/* Constantes utilizada em todo o programa */
#define MAXCHILDREN 3
typedef enum {Stmt, Exp, Decl, ListK, Error} NodeKind;
typedef enum {If, Iter, Assign, Cmpd, Return, Call} StmtKind;
typedef enum {Factor, Const, Additive, Simple, Id, Term, Op} ExpKind;
typedef enum {Var, Fun, Param, Type} DeclKind;
typedef enum {Params, Local, StmtList, AdditiveList, TermList, Args} ListKind;
typedef enum {Dummy, Ummyd, Void, Integer, Float, Array} ExpType; /* Para a verificação de tipos */

/* Estrutura de dados para aramzenar numeros inteiros e reais na mesma variavel */
typedef union{
	int val_int;
	float val_float;
}ValType;

/*  Estrutura de dados para armazenar o tipo do noh que compoe a arvore sintatica */
typedef union {
	StmtKind stmt;
	ExpKind exp;
	DeclKind decl;
	ListKind list;
} kind_t;

typedef struct treeNode
{
	struct treeNode* child[MAXCHILDREN];
	struct treeNode* sibling;
	NodeKind nodekind;
	kind_t kind;
	int lineno;
	int col;
	char* expected;
	int op;
	bool constIsInt;
	ValType val; /* Inteiro ou Real */
	char* name;
	char* type;
	/*ExpType type; */ /* Para a checagem de tipo */
} TreeNode;

/*
 * Flag global para imprimir ou nao os tokens durante a anlise lexica
 */
extern int TraceScan;

/*
 * Flag global para imprimir ou nao a arvore sintatica final
 */
extern int TraceParse;

/*
 * Flag global para imprimir as insercoes e pesquisas na tabela de simbolos
 */
extern int TraceAnalyze;

/*
 * Flag global para escrever comentarios no codigo fonte gerado
 */
extern int TraceCode;

#endif
