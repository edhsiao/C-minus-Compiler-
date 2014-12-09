/****************************************************/
/* File: main.c                                     */
/* Main program for TINY compiler                   */
/****************************************************/

#include "globals.h"


#define NO_PARSE FALSE

#include "util.h"
#include "list.h"
//#if NO_PARSE
#include "scan.h"
//#else
#include "parse.h"
//#endif


int lineno = 0;
int col = 0;
FILE * source;
FILE * listing;
FILE * code;


int TraceScan = TRUE;
int TraceParse = TRUE;
int TraceAnalyze = TRUE;
int TraceCode = TRUE;

int main( int argc, char * argv[] )
{
	TreeNode * syntaxTree;
	char prog[120];
	hash_new(&h);
	if (argc < 2)
	{ fprintf(stderr,"Uso: %s <nomeArquivo>\n",argv[0]);
	exit(1);
	}
	if (argc == 3)
	{
		if(strcmp(argv[2], "-a") == 0)
		{
			TraceScan = FALSE;
			TraceAnalyze = FALSE;
		}
		else if(strcmp(argv[2], "-s") == 0)
		{
			TraceScan = FALSE;
			TraceParse = FALSE;
		}
	}
	strcpy(prog,argv[1]) ;
	if (strchr (prog, '.') == NULL)
		strcat(prog,".cm");
	source = fopen(prog,"r");
	if (source==NULL)
	{ fprintf(stderr,"Arquivo %s nao encontrado\n",prog);
	exit(1);
	}
	listing = stdout;
	fprintf(listing,"\nArquivo C Menos: %s\n",prog);
#if NO_PARSE
	//if(a_flag == 0)
	while( (ttype=getToken())!= 0 )
		printToken( ttype, tokenString );
#else
	syntaxTree = parse();
	if (TraceParse) {
		fprintf(listing,"\nArvore Sintatica:\n");
		printTree(syntaxTree);
	}

	if(TraceAnalyze) {
		fprintf(listing, "\nTabela de simbolo:\n");
		print_hash(h);
	}
	list_kill(l);
	hash_kill(&h);
#endif
	fclose(source);
	return 0;
}
