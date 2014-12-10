#include "ana_sem.h"

linkedList_t* createSymTable(TreeNode* syntaxTree)
{
	static linkedList_t* list;
	linkedList_t* listAux;
	char* lastEscopoDecl = "";
	int i;

	while(syntaxTree != NULL)
	{
		if (syntaxTree->nodekind == Stmt)
		{
			switch (syntaxTree->kind.stmt) {
			case If:
				lastEscopoDecl = "if";
				break;
			case Iter:
				lastEscopoDecl = "while";
				break;
			default:
				break;
			}
		}

		/* Verifica se eh declaracao de identificador */
		if( syntaxTree->nodekind == Decl )
		{
			listAux = createNewListNode();
			listAux->info = fillInfo(syntaxTree->name, lastEscopoDecl, "", "");
			addNodeEnd(&list, &listAux);

			/* Verificacao de scopo
			 * Nos irmao estao no mesmo escopo, entao nao podem
			 * existir duas declaracoes no mesmo nivel de escopo
			 * */

			switch(syntaxTree->kind.decl)
			{
			case Fun:
				lastEscopoDecl = syntaxTree->name;
				break;
			default: break;
			}
		}

		/* Verificacao de tipo na atribuicao */

		for (i = 0; i < MAXCHILDREN; i++)
			createSymTable(syntaxTree->child[i]);

		syntaxTree = syntaxTree->sibling;
	}

	return list;
}
