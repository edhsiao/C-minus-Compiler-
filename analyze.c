/****************************************************/
/* File: analyze.c                                  */
/* Semantic analyzer implementation                 */
/* for the TINY compiler                            */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include "globals.h"
#include "symtab.h"
#include "analyze.h"

/* counter for variable memory locations */
static int location = 0;
static int scope = 0;
static int hasMain = 0;

int iteracao = 0;

int isInFunction;
int global = 0;

int getHasMain()
{
	return hasMain;
}

//static void typeError(TreeNode* t, char* message){
//	fprintf(listing,"\nERRO SEMÂNTICO: \"%s\" LINHA: %d %s\n",t->name,t->lineno,message);
//	//Error = 1;
//}

/* Procedure traverse is a generic recursive 
 * syntax tree traversal routine:
 * it applies preProc in preorder and postProc 
 * in postorder to tree pointed to by t
 */
static void traverse( TreeNode* t, void (* preProc) (TreeNode*), void (* postProc) (TreeNode*) ){
	if (t != NULL)
	{
		preProc(t);
		{
			int i;
			for (i=0; i < MAXCHILDREN; i++)
				traverse(t->child[i],preProc,postProc);
		}
		postProc(t);
		traverse(t->sibling,preProc,postProc);
	}
}

/* nullProc is a do-nothing procedure to 
 * generate preorder-only or postorder-only
 * traversals from traverse
 */
static void nullProc(TreeNode* t){

	if (t==NULL)
		return;
	else
		return;
}



/* Procedure insertNode inserts 
 * identifiers stored in t into 
 * the symbol table 
 */
static void insertNode(TreeNode * t){
	char* type;
	char* dataType="";
	char* tipoToken;
	type =  (char*)malloc(20);
	dataType = (char*)malloc(20);
	int aux=0;

	//DESCOBRIR O TIPO DE VARIAVEL - func, var ou array
	if (t->nodekind == Decl){
		if(t->kind.decl == Fun || t->nodekind == Call)
		{
			type = "func";
			aux=1;
		}
		else
			if(t->kind.decl == Var || t->kind.decl == Param)
			{
				type = "var";
			}
			else

				if(strcmp(t->type, "Array") == 0)
				{
					type = "array";
				}
	}

	if(t->type != NULL)
	{
		//DESCOBRIR O TIPO DE RETORNO DA VARIAVEL
		if(strcmp(t->type, "Array") == 0)
		{
			type = "array";
		}
		else
		{
			if(strcmp(t->type, "Integer") == 0)
			{
				type = "int";
			}
			else
			{
				if(strcmp(t->type, "Float") == 0)
				{
					type = "float";
				}
				else
				{
					if(strcmp(t->type, "Void") == 0)
					{
						type = "void";
					}
				}
			}
		}
	}

	//INSERE NA TABELA
	switch (t->nodekind){
	case Stmt:
		if(t->kind.stmt == Call)
		{
			printf("\nt->kind.stmt == Call");
			if (st_lookup(t->name, t->scopeVar) == -1){
				/* Nao ta na tabela, trata como nova definicao*/
				if(aux == 1)
					st_insert(t->name, type,t->scopeVar, "", "", t->lineno, location++);
				else
					st_insert(t->name, type,t->scopeVar, "", "", t->lineno, location++);
			}
		}
		break;
	case Decl:

		if(t->kind.decl == Fun)
		{
			if(t->name != NULL )
			{
				if((strcmp(t->name, "main") == 0))
					hasMain = 1;

				if (st_lookup(t->name, t->scopeVar) == -1)
				{
					if(t->child[0] != NULL  && t->child[0]->type != NULL)
					{
						/* Nao ta na tabela, trata como nova definicao*/
						if( ( (strcmp(type, "var") == 0) ||
								(strcmp(type, "array") == 0) ) &&
								(strcmp(t->child[0]->type, "void") == 0) ){
							printf("\nERRO SEMANTICO: %s, LINHA: %d -  Variavel declarada com void\n", t->name, t->lineno);
						}
						else{
							if(aux == 1)
								st_insert(t->name,
										"func",
										t->scopeVar,
										"",
										t->child[0]->type,
										t->lineno,
										location++);
						}
					}
					else
					{ /* Inserindo o main na tabela */
						st_insert(t->name,
								"func",
								t->scopeVar,
								"",
								"Integer",
								t->lineno,
								location++);
					}

				}
				else
					printf("\nERRO SEMANTICO: %s, LINHA: %d - Ja foi declarado\n",
							t->name,
							t->lineno);
			}
		}
		else
			if(t->kind.decl == Var)
			{
				if(t->name != NULL && t->type != NULL)
				{
					if (st_lookup(t->name, t->scopeVar) == -1){
						/* Nao ta na tabela, trata como nova definicao*/
						if( ( (strcmp(t->type, "int") == 0) ||
								(strcmp(t->type, "array") == 0) ) &&
								(strcmp(t->type, "void") == 0) ){
							printf("\nERRO SEMANTICO: %s, LINHA: %d -  Variavel declarada com void\n", t->name, t->lineno);
						}
						else{
							if(aux == 1)
								st_insert(t->name,
										type,
										t->scopeVar,
										"",
										t->type,
										t->lineno,
										location++);
							else
								st_insert(t->name,
										type,
										t->scopeVar,
										t->type,
										"",
										t->lineno,
										location++);
						}
					}
					else
						printf("\nERRO SEMANTICO: %s, LINHA: %d - Ja foi declarado\n",
								t->name,
								t->lineno);
				}
			}


		break;
	case Exp:
		if(t->kind.exp == Id)
		{
			if(t->name != NULL)
			{
				if ((st_lookup(t->name, t->scopeVar) == -1) &&
						(st_lookup(t->name, 0) == -1))
					printf("\nERRO SEMANTICO: %s, LINHA: %d - Não foi declarado\n",
							t->name,
							t->lineno);
				else{
					st_insert(t->name, type, t->scopeVar, tipoToken, "", t->lineno, 0);
				}
			}
		}
		break;
	default:
		break;
	}
}


void scopeVar(TreeNode *t){

	int i;
	/* Se declarou funcao muda o escopo. */
	if(t->nodekind ==  Decl && t->kind.decl == Fun)
		t->scopeVar = ++scope;

	//printf("Veja bem o valor de isInFunction: %d - rsrs\n", isInFunction);
	for (i=0; i < MAXCHILDREN; i++)
		if(t->child[i] != NULL)
			t->child[i]->scopeVar = t->scopeVar;

	if(t->sibling != NULL){
		t->sibling->scopeVar = t->scopeVar;
	}

}

static void checkNode(TreeNode * t){

	if(t->nodekind == Stmt && t->kind.stmt == Assign)
	{
		if(t->child[0] != NULL)
		{
			if( t->child[0]->kind.exp == Id ) //Se o filho 0 for ID
			{
				if(t->child[0]->name != NULL)
				{
					if(st_lookup(t->child[0]->name, t->child[0]->scopeVar) != -1)//Se ja tiver sido declarado
					{
						if(t->child[2] != NULL && t->child[2]->name)
						{
							if( t->child[2]->kind.stmt == Call )//Se o filho 2 for Chamada de funcao
							{
								if(	st_lookupAux(t->child[0]->name, t->child[0]->scopeVar) !=
										st_lookupAuxFunc(t->child[2]->name, t->child[2]->scopeVar))
								{

									if((st_lookupAuxFunc(t->child[2]->name, t->child[2]->scopeVar) == -1))
									{
										if((strcmp(t->child[2]->name, "input") != 0) && ((strcmp(t->child[2]->name, "output") != 0)))
											printf("\nERRO SEMANTICO: %s, LINHA: %d - Funcao nao declarada\n", t->child[0]->name, t->child[0]->lineno);
									}
									else
										printf("\nERRO SEMANTICO: %s, LINHA: %d - Problema de atribuicao\n", t->child[0]->name, t->child[0]->lineno);
								}
							}
							else
								if( t->child[2]->nodekind == Exp && t->child[2]->kind.exp == Const ) //Se for um numero
								{
									int typeTokenValueAux;

									if( strcmp("Integer", t->child[2]->type) == 0 )
										typeTokenValueAux = Integer;
									else
										typeTokenValueAux = Float;

									if(st_lookupAux(t->child[0]->name, t->child[0]->scopeVar) != typeTokenValueAux )
										printf("\nERRO SEMANTICO: %s, LINHA: %d - Problema de atribuicao\n", t->child[0]->name, t->child[0]->lineno);
								}
						}
					}
				}
			}
		}
	}
}





/* Function buildSymtab constructs the symbol
 * table by preorder traversal of the syntax tree
 */
void buildSymtab(TreeNode * syntaxTree){

	traverse(syntaxTree,scopeVar,nullProc);
	traverse(syntaxTree,insertNode,nullProc);

	FILE* aux = fopen("SimTab", "w+");

	fprintf(aux,"\nTabela de Simbolos:\n\n");
	printSymTab(aux);
	fprintf(listing, "\nTabela de Simbolos: \n\n");
	printSymTab(listing);
}



/* Procedure typeCheck performs type checking
 * by a postorder syntax tree traversal
 */
void typeCheck(TreeNode * syntaxTree)
{
	traverse(syntaxTree,nullProc,checkNode);
}
