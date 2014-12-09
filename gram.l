/****************************************************/
/* File: cmenos.l                                       */
/*Lex linguagem C-menos                  */
/****************************************************/

%{
#include "globals.h"
#include "util.h"
#include "scan.h"
#include "gram.tab.h"
#include "list.h"
#include "hash.h"


/*lexema dos identificador ou palavras reservadas */

List l;
char tokenString[MAXTOKENLEN+1];
char next_token[MAXTOKENLEN+1];
char current_line[100];
int reset_flag = 0;
Hash h = NULL;

%}

digito			[0-9]
numero			("+"|"-")?{digito}+
num_float		{numero}(\.{digito}+)?
letras			[a-z|A-Z]
identificador	{letras}+
novalinha   	\r?\n
espaco  		[" "|\t]+

%%

"else"          {col += 4; return ELSE;}
"if"            {col += 2; return IF;}
"int"           {col += 3; return INT;}
"float"         {col += 5; return FLOAT;}
"return"        {col += 6; return RETURN;}
"void"          {col += 4; return VOID;}
"while"         {col += 5; return WHILE;}
"+"             {col += 1; return SOMA;}
"-"             {col += 1; return SUB;}
"*"             {col += 1; return MUL;}
"/"             {col += 1; return DIV;}
"<"             {col += 1; return MENOR;}
"<="            {col += 2; return MENORIG;}
">"             {col += 1; return MAIOR;}
">="            {col += 2; return MAIORIG;}
"=="            {col += 2; return IG;}
"!="            {col += 2; return DIF;}
"="             {col += 1; return ATRIB;}
";"             {col += 1; return PV;}
","             {col += 1; return VIRG;}
"("             {col += 1; return AP;}
")"             {col += 1; return FP;}
"["             {col += 1; return ACOL;}
"]"             {col += 1; return FCOL;}
"{"             {col += 1; return ACH;}
"}"             {col += 1; return FCH;}
{identificador}    {col += strlen(yytext); return ID;}
{numero}        {col += strlen(yytext); return NUM;}
{num_float}  {col += strlen(yytext); return NUM_FLOAT;}
{novalinha}       {col = 0; reset_flag = 1; list_kill(l); l = list_new(); memset(current_line, 0, 100); lineno++;}
{espaco}    {col += strlen(yytext); strcat(current_line, yytext); /* ignora espaco */}

"/*"            { char c; int s = 0;
                  do
                  { c = input();
		    col++;
                    if (c == EOF) break;
                    if (c == '\n'){col = 0; memset(current_line, 0, 100); lineno++;}
		    
		    if (s == 0 && c == '*') s = 1;
		    else if (s == 1 && c == '*') s = 1;
		    else if (s == 1 && c == '/') s = 2;
		    else s = 0;
                  } while (s != 2);
                }
.               {col += strlen(yytext); return ERROR;}

%%

int getToken(void)
{ static int firstTime = TRUE;
  int currentToken;
  if (reset_flag)
  {
  //  list_kill(l);
  //  l = list_new();
    reset_flag = 0;
  }
  if (firstTime)
  { firstTime = FALSE;
    lineno++;
    yyin = source;
    yyout = listing;
    l = list_new();
    strcpy(next_token, "first");
  }
  currentToken = yylex();
  strcat(current_line, yytext);
  if(strcmp(next_token, "first") != 0)
  {
    strncpy(tokenString, next_token, MAXTOKENLEN);
  }
  /*if(currentToken == NUM || currentToken == ID)
  */  strncpy(next_token, yytext, MAXTOKENLEN);
  list_add_back(l, node_new(NULL, NULL, NULL, NULL, NULL));
  list_tail(l);
  strcpy(l->current->str, yytext);
  if (TraceScan == TRUE) {
    fprintf(listing,"\t%d:%d: ",lineno,col);
    printToken(currentToken,next_token);
  }
  return currentToken;
}
