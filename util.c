/****************************************************/
/* File: util.c                                     */
/* Utility function implementation                  */
/* for the TINY compiler                            */
/****************************************************/

#include "globals.h"
#include "util.h"
#include "gram.tab.h"

void printToken(int token, const char* tokenString) {
	switch (token) {
	case ELSE:
	case IF:
	case INT:
	case FLOAT:
	case RETURN:
	case VOID:
	case WHILE:

		fprintf(listing, "palavra reservada: %s\n", tokenString);
		break;
	case SOMA:
		fprintf(listing, "+\n");
		break;
	case SUB:
		fprintf(listing, "-\n");
		break;
	case MUL:
		fprintf(listing, "*\n");
		break;
	case DIV:
		fprintf(listing, "/\n");
		break;
	case MENOR:
		fprintf(listing, "<\n");
		break;
	case MENORIG:
		fprintf(listing, "<=\n");
		break;
	case MAIOR:
		fprintf(listing, ">\n");
		break;
	case MAIORIG:
		fprintf(listing, ">=\n");
		break;
	case IG:
		fprintf(listing, "==\n");
		break;
	case DIF:
		fprintf(listing, "!=\n");
		break;
	case ATRIB:
		fprintf(listing, "=\n");
		break;
	case PV:
		fprintf(listing, ";\n");
		break;
	case VIRG:
		fprintf(listing, ",\n");
		break;
	case AP:
		fprintf(listing, "(\n");
		break;
	case FP:
		fprintf(listing, ")\n");
		break;
	case ACOL:
		fprintf(listing, "[\n");
		break;
	case FCOL:
		fprintf(listing, "]\n");
		break;
	case ACH:
		fprintf(listing, "{\n");
		break;
	case FCH:
		fprintf(listing, "}\n");
		break;
	case 0:
		fprintf(listing, "EOF\n");
		break;
	case NUM:
		fprintf(listing, "NUM, valor = %s\n", tokenString);
		break;
	case NUM_FLOAT:
		fprintf(listing, "NUM_FLOAT, valor = %s\n", tokenString);
		break;
	case ID:
		fprintf(listing, "ID, nomeID = %s\n", tokenString);
		break;
	case ERROR:
		fprintf(listing, "'%s'\n", tokenString);
		break;
	default:
		fprintf(listing, "Token desconhecido: %d\n", token);
	}
}

TreeNode* newStmtNode(StmtKind kind) {
	TreeNode* t = (TreeNode*) malloc(sizeof(TreeNode));
	int i;
	if (t == NULL)
		fprintf(listing,
				"util.c - newStmtNode Erro de falta de memoria na linha %d\n",
				lineno);
	else {
		for (i = 0; i < MAXCHILDREN; i++)
			t->child[i] = NULL;
		t->sibling = NULL;
		t->nodekind = Stmt;
		t->kind.stmt = kind;
		t->lineno = lineno;
	}
	return t;
}

TreeNode* newExpNode(ExpKind kind) {
	TreeNode* t = (TreeNode*) malloc(sizeof(TreeNode));
	int i;
	if (t == NULL)
		fprintf(listing,
				"util.c - newExpNode Erro de falta de memoria na linha %d\n",
				lineno);
	else {
		for (i = 0; i < MAXCHILDREN; i++)
			t->child[i] = NULL;
		t->sibling = NULL;
		t->nodekind = Exp;
		t->kind.exp = kind;
		t->lineno = lineno;
	}
	return t;
}

TreeNode* newDeclNode(DeclKind kind) {
	TreeNode* t = (TreeNode*) malloc(sizeof(TreeNode));
	int i;
	if (t == NULL)
		fprintf(listing,
				"util.c - newDeclNode Erro de falta de memoria na linha %d\n",
				lineno);
	else {
		for (i = 0; i < MAXCHILDREN; i++)
			t->child[i] = NULL;
		t->sibling = NULL;
		t->nodekind = Decl;
		t->kind.decl = kind;
		t->lineno = lineno;
	}
	return t;
}


TreeNode* newListNode(ListKind kind) {
	TreeNode* t = (TreeNode*) malloc(sizeof(TreeNode));
	int i;
	if (t == NULL)
		fprintf(listing, "util.c - newListNode Erro de falta de memoria na linha %d\n", lineno);
	else {
		for (i = 0; i < MAXCHILDREN; i++)
			t->child[i] = NULL;
		t->sibling = NULL;
		t->nodekind = ListK;
		t->kind.list = kind;
		t->lineno = lineno;
	}
	return t;
}


TreeNode* newErrNode() {
	TreeNode* t = (TreeNode*) malloc(sizeof(TreeNode));
	int i;
	if (t == NULL)
		fprintf(listing, "util.c - newErrNode Erro de falta de memoria na linha %d\n", lineno);
	else {
		for (i = 0; i < MAXCHILDREN; i++)
			t->child[i] = NULL;
		t->sibling = NULL;
		t->nodekind = Error;
		t->lineno = lineno;
		t->col = col;
	}
	return t;
}


char* copyString(char * s) {
	int n;
	char * t;
	if (s == NULL)
		return NULL;
	n = strlen(s) + 1;
	t = malloc(n);
	if (t == NULL)
		fprintf(listing, "util.c - copyString Erro de falta de memoria na linha %d\n", lineno);
	else
		strcpy(t, s);
	return t;
}


static int indentno = 0;


#define INDENT indentno+=2
#define UNINDENT indentno-=2


static void printSpaces(void) {
	int i;
	for (i = 0; i < indentno; i++)
		fprintf(listing, " ");
}


void printTree(TreeNode * tree) {
	int i;
	INDENT;
	while (tree != NULL) {
		printSpaces();
		if (tree->nodekind == Stmt) {
			switch (tree->kind.stmt) {
			case If:
				fprintf(listing, "If\n");
				break;
			case Iter:
				fprintf(listing, "While\n");
				break;
			case Assign:
				/*fprintf(listing,"");*/
				printToken(tree->op, "\0");
				break;
			case Cmpd:
				fprintf(listing, "Novo Escopo\n");
				break;
			case Return:
				fprintf(listing, "Return\n");
				break;
			case Call:
				fprintf(listing, "%s()\n", tree->name);
				break;
			default:
				fprintf(listing, " ExpNode tipo desconhecido\n");
				break;
			}
		} else if (tree->nodekind == Exp) {
			switch (tree->kind.exp) {
			case Op:
				printToken(tree->op, "\0");
				break;
			case Const:
				if (tree->constIsInt == true)
					fprintf(listing, "%d\n", tree->val.val_int);
				else
					fprintf(listing, "%.5f\n", tree->val.val_float);
				break;
			case Id:
				fprintf(listing, "%s\n", tree->name);
				break;
			case Factor:
				fprintf(listing, "()\n");
				break;
			case Additive:
				fprintf(listing, "Additive\n");
				break;
			case Simple:
				/*fprintf(listing,"");*/
				printToken(tree->op, "\0");
				break;
			case Term:
				fprintf(listing, "Term\n");
				break;
			default:
				fprintf(listing, "Unknown ExpNode kind\n");
				break;
			}
		} else if (tree->nodekind == Decl) {
			switch (tree->kind.decl) {
			case Var:
				fprintf(listing, "%s : %s", tree->name, tree->type);
				if (strcmp(tree->type, "Array") == 0)
					fprintf(listing, " [%d]", tree->val.val_int);
				fprintf(listing, "\n");
				break;
			case Fun:
				fprintf(listing, "funcao '%s', %s\n", tree->name, tree->type);
				break;
			case Param:
				fprintf(listing, "Parametro: %s, %s\n", tree->name, tree->type);
				break;
			case Type:
				fprintf(listing, "Tipo: %s\n", tree->name);
				break;
			}
		} else if (tree->nodekind == ListK) {
			switch (tree->kind.list) {
			case Params:
				fprintf(listing, "Param List\n");
				break;
			case Local:
				fprintf(listing, "Local Var List\n");
				break;
			case StmtList:
				fprintf(listing, "Stmt List\n");
				break;
			case AdditiveList:
				fprintf(listing, "Additive List\n");
				break;
			case TermList:
				fprintf(listing, "Term List\n");
				break;
			case Args:
				fprintf(listing, "Args List\n");
				break;
			}
		} else if (tree->nodekind == Error) {
			int i;
			fprintf(listing, "Error:\n%s\n", tree->name);
			for (i = 0; i < tree->col - 1; i++) {
				printf("-");
			}
			printf("^\nEsperado: %s\n", tree->expected);
		} else
			fprintf(listing, "Unknown node kind\n");
		for (i = 0; i < MAXCHILDREN; i++)
			printTree(tree->child[i]);
		tree = tree->sibling;
	}
	UNINDENT;
}
