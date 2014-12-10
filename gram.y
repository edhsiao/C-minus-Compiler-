/****************************************************/
/* Especificao YACC/Bison  C-menos                  */
/****************************************************/

%{
#define YYPARSER /* diferencia a saida do Yacc dos outros arquivos*/

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"
#include "list.h"

#define YYSTYPE type_t
static int savedLineNo;
static int saved_col;
static int intTemp;
static TreeNode * savedTree; /*armazena a arvore de sintaxe para uso futura*/

typedef union type_t type_t;

union type_t
{
	TreeNode *node;
	char *str;
	int op;
};

extern int yychar;

int yyerror(char * message)
{
  int i;
  //Node temp;

  fprintf(listing,"\nErro de sintaxe na linha %d: col %d, at ",lineno,col);
  printToken(yychar, next_token);
  fprintf(listing,"Linha Atual:\n%s\n",current_line);

  for(i = 1; i < strlen(current_line); i++)
    fprintf(listing,"-");

/*  printf("Testando...\n");
  temp = l->current;
  list_root(l);
  while(l->current != NULL)
  {
    printf("%d: %s\n", l->current->id, l->current->str);
    l->current = l->current->next;
  }
  l->current = temp;
//  list_kill(l);
  printf("\nTeste completa.\n");
*/
  fprintf(listing,"^\n");
  return 0;
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with the C Minus scanner
 */
static int yylex(void)
{ return getToken(); }

TreeNode * parse(void) { 
  yyparse();
  return savedTree;
}

%}

%token ELSE IF INT FLOAT RETURN VOID WHILE
%token ID NUM NUM_FLOAT
%token SOMA SUB MUL DIV MENOR MENORIG MAIOR MAIORIG IG DIF ATRIB PV VIRG AP FP ACOL FCOL ACH FCH
%token ERROR 

%nonassoc MENOR MENORIG MAIOR MAIORIG IG DIF
%left SOMA SUB
%left MUL DIV

%% 

program     : declaration_list
                 { savedTree = $1.node; } 
            ;

declaration_list 	: declaration_list declaration
			{
			    TreeNode * t = $1.node;
			    if (t != NULL)
			    {
				while (t->sibling != NULL)
				    t = t->sibling;
				t->sibling = $2.node;
				$$.node = $1.node;
			    }
			    else $$.node = $2.node;
			}
			| declaration
			    { $$.node = $1.node; }
			;

declaration	: var_declaration
			{ $$.node = $1.node; }
		| fun_declaration
			{ $$.node = $1.node; }
		;

var_declaration	: type_specifier ID PV
			{
			  $$.node = newDeclNode(Var);
			  $$.node->type = $1.str;
			  $$.node->name = copyString(tokenString);
			}
		| type_specifier ID
			{
			  savedLineNo = lineno; 
			  $$.str = copyString(tokenString);
			}
		ACOL NUM FCOL {intTemp = atoi(tokenString); } PV
			{
			  $$.node = newDeclNode(Var);
			  $$.node->type= copyString("Array");
			  $$.node->name = $3.str;
			  $$.node->lineno = savedLineNo;
			  //$$.node->val.val_int = atoi(tokenString); /* $5.op; */
			  $$.node->val.val_int = intTemp;
			}
		;

type_specifier	: 
		INT
			{
			  $$.str = copyString("Inteiro");
			}
		| VOID
			{
			  $$.str = copyString("Void");
			}
		| FLOAT
			{
			  $$.str = copyString("Float");
			}
		;

fun_declaration	: type_specifier ID 
			{
			  printf("Novo escopo\n");
			  savedLineNo = lineno;
			  $$.str = copyString(tokenString);
			}
			AP params FP compound_stmt
			{
			  $$.node = newDeclNode(Fun);
			  $$.node->name = $3.str;
			  $$.node->lineno = savedLineNo;
			  $$.node->type = $1.str;
			  $$.node->child[0] = $5.node;
			  $$.node->child[1] = $7.node;
			}
		;

params	: param_list
		{ $$.node = $1.node; }
	| VOID
	;

param_list	: param_list VIRG param
			{
			  TreeNode * t = $1.node;
			  if (t != NULL)
			  {
				while (t->sibling != NULL)
				t = t->sibling;
				t->sibling = $3.node;
				$$.node = $1.node;
			  }
			  else $$.node = $3.node;
			}
		| param
			{ $$.node = $1.node; }
		;

param	: type_specifier ID
		{
		  $$.node = newDeclNode(Param);
		  $$.node->type = $1.str;
		  $$.node->name = copyString(tokenString);
		}
	| type_specifier ID
		{
		  savedLineNo = lineno;
		  $$.str = copyString(tokenString);
		}
			ACOL FCOL
		{
		  $$.node = newDeclNode(Param);
		  $$.node->type = $1.str;
		  $$.node->name = $3.str;
		  $$.node->lineno = savedLineNo;
		}
	;

compound_stmt	: ACH local_declarations stmt_list FCH
			{
			  $$.node = newStmtNode(Cmpd);
			  $$.node->child[0] = $2.node;
			  $$.node->child[1] = $3.node;
			}
		;

local_declarations	: local_declarations var_declaration
				{
				  TreeNode * t = $1.node;
				/*printf("t is %p\n", t); fflush(stdout);*/
				  if (t != NULL)
				  {
					while (t->sibling != NULL)
					{
						t = t->sibling;
					}
					t->sibling = $2.node;
					$$.node = $1.node;
				  }
				  else
				  {
					 $$.node = $2.node;
				  }
				}
			| { $$.node = NULL; printf("Novo escopo\n"); }
			;

stmt_list	: stmt_list stmt
			{
			  TreeNode * t = $1.node;
			  if (t != NULL)
			  {
				while (t->sibling != NULL)
				t = t->sibling;
				t->sibling = $2.node;
				$$.node = $1.node;
			  }
			  else $$.node = $2.node;
			}
		| { $$.node = NULL; }
		;

stmt	: expr_stmt
		{ saved_col = col; $$.node = $1.node; }
	| compound_stmt
		{ saved_col = col; $$.node = $1.node; }
	| selection_stmt
		{ saved_col = col; $$.node = $1.node; }
	| iteration_stmt
		{ saved_col = col; $$.node = $1.node; }
	| return_stmt
		{ saved_col = col; $$.node = $1.node; }
	;

expr_stmt	: expr PV
			{ $$.node = $1.node; }
		| PV
		;

selection_stmt	: IF AP expr FP stmt
			{
			  $$.node = newStmtNode(If);
			  $$.node->child[0] = $3.node;
			  $$.node->child[1] = $5.node;
			}
		| IF AP expr FP stmt ELSE stmt
			{
			  $$.node = newStmtNode(If);
			  $$.node->child[0] = $3.node;
			  $$.node->child[1] = $5.node;
			  $$.node->child[2] = $7.node;
			}
		;

iteration_stmt	: WHILE AP expr FP stmt
			{
			  $$.node = newStmtNode(Iter);
			  $$.node->child[0] = $3.node;
			  $$.node->child[1] = $5.node;
			}
		;

return_stmt	: RETURN PV
			{
			  $$.node = newStmtNode(Return);
			  $$.node->child[0] = NULL;
			}
		| RETURN expr PV
			{
			  $$.node = newStmtNode(Return);
			  $$.node->child[0] = $2.node;
			}
		;

expr	: var ATRIB expr
		{
		  $$.node = newStmtNode(Assign);
		  $$.node->child[0] = $1.node;
		  $$.node->op = ATRIB; 
		  $$.node->child[1] = $3.node;
		}
	| simple_expr
		{
		  $$.node = $1.node;
		}
	;

var	: ID
		{
		  $$.node = newExpNode(Id);
		  $$.node->name = copyString(tokenString);
		}
	| ID
		{
		  savedLineNo = lineno;
		  $$.str = copyString(tokenString);
		}
		ACOL expr FCOL
		{
		  $$.node = newExpNode(Id);
		  $$.node->name = $2.str;
		  $$.node->lineno = savedLineNo;
		  $$.node->child[1] = $4.node;
		}
	;

simple_expr	: additive_expr relop additive_expr
			{
			  $$.node = newExpNode(Op);
			  $$.node->child[0] = $1.node;
			  $$.node->op = $2.op;
			  $$.node->child[2] = $3.node;
			}
		| additive_expr
			{ $$.node = $1.node; }
		| additive_expr error
			{
			  $$.node = newErrNode();
			  $$.node->name = copyString(current_line);
			  $$.node->expected = copyString("Relation ou Additive expression (eg '1 != 0' or '4 + 6')");
			  $$.node->col = col;
			}
		;

relop : MENORIG
		{
		  $$.op = MENORIG;
		}
	| MENOR
		{ 
		  $$.op = MENOR;
		}
	| MAIOR	
		{ 
		  $$.op = MAIOR;
		}
	| MAIORIG	
		{ 
		  $$.op = MAIORIG;
		}
	| IG	
		{ 
		  $$.op = IG;
		}
	| DIF	
		{ 
		  $$.op = DIF;
		}
	;

additive_expr	: additive_expr addop term
			{
				$$.node = newExpNode(Op);
				$$.node->child[0] = $1.node;
				$$.node->child[1] = $3.node;
				$$.node->op = $2.op;
			}
		| term
			{ $$.node = $1.node; }
		| error
			{
		  $$.node = newErrNode();
		  $$.node->name = copyString(current_line);
		  $$.node->expected = copyString("Term (eg '5' ou var_name)");
		  $$.node->col =  col;
			}
		;

addop	: SOMA
		{
		  $$.op = SOMA;
		}
	| SUB
		{
		  $$.op = SUB;
		}
	;

term	: term mulop factor
		{
			$$.node = newExpNode(Op);
				$$.node->child[0] = $1.node;
				$$.node->child[1] = $3.node;
				$$.node->op = $2.op;
		}
	| factor
		{ $$.node = $1.node; }
	;

mulop	: MUL
		{ 
		  $$.op = MUL;
		}
	| DIV
		{
		  $$.op = DIV;
		}
	;

factor	: AP expr FP
		{
		  /*$$.node = newExpNode(Factor);
		  $$.node->child[0] = $2.node;*/
		  $$.node = $2.node;
		}
	| var
		{ $$.node = $1.node; }
	| call
		{ $$.node = $1.node; }
	| NUM
		{ 
		  $$.node = newExpNode(Const);
		  $$.node->val.val_int = atoi(next_token);
		  $$.node->constIsInt = true;
		}
	| NUM_FLOAT
		{ 
		  $$.node = newExpNode(Const);
		  $$.node->val.val_float = atof(next_token);
		  $$.node->constIsInt = false;
		}
	;

call	: ID
		{
		  savedLineNo = lineno;
		  $$.str = copyString(tokenString);
		}
		AP args FP
		{
		  $$.node = newStmtNode(Call);
		  $$.node->name = $2.str;
		  $$.node->child[0] = $4.node;
		}
	;

args	: arg_list
		{ $$.node = $1.node; }
	| { $$.node = NULL; }
	;

arg_list	: arg_list VIRG expr
			{
			  TreeNode * t = $1.node;
        	          if (t != NULL)
        	          {
				while (t->sibling != NULL)
				t = t->sibling;
				t->sibling = $3.node;
				$$.node = $1.node;
			  }
			  else $$.node = $3.node;
			}
		| expr
			{ $$.node = $1.node; }
		;
