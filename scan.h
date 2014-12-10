#ifndef _SCAN_H_
#define _SCAN_H_

#include "list.h"

#define MAXTOKENLEN 40

extern char tokenString[MAXTOKENLEN+1];
extern char next_token[MAXTOKENLEN+1];
extern char current_line[100];
extern List l;

int getToken(void);

#endif
