#include "globals.h"
#include "ana_sem.h"

#define NO_PARSE FALSE

#include "util.h"
#include "list.h"
#include "scan.h"
#include "parse.h"

int lineno = 0;
int col = 0;
FILE * source;
FILE * listing;
FILE * code;
linkedList_t* sym_tab;

int TraceScan = TRUE;
int TraceParse = TRUE;
int TraceAnalyze = TRUE;
int TraceCode = TRUE;

int main( int argc, char * argv[] )
{
	TreeNode* syntaxTree;
	char prog[120];
	if (argc < 2)
	{;
		fprintf(stderr,"Uso: %s <nomeArquivo>\n",argv[0]);
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
	{
		fprintf(stderr,"Arquivo %s nao encontrado\n",prog);
		exit(1);
	}
	listing = stdout;
	fprintf(listing,"\nArquivo C Menos: %s\n",prog);

	syntaxTree = parse();

	if (TraceParse) {
		fprintf(listing,"\nArvore Sintatica:\n");
		printTree(syntaxTree);
	}

	sym_tab = createSymTable(syntaxTree);
	printList(sym_tab);

	list_kill(l);
	fclose(source);

	return 0;
}
