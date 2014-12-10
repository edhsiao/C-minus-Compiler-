#ifndef _UTIL_H_
#define _UTIL_H_

void printToken( int, const char* );

TreeNode * newStmtNode(StmtKind);

TreeNode * newExpNode(ExpKind);

TreeNode * newDeclNode(DeclKind);

TreeNode * newListNode(ListKind);

TreeNode * newErrNode();

char * copyString( char * );

void printTree( TreeNode * );

#endif
