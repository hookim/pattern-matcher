#ifndef _TOKENEIZER_H_
#define _TOKENEIZER_H_

#include <stdio.h>
#include "ds.h"

#define BUF_MAX 1024

void tokeneizer(char *fname1, char *fname2, Tlist *t1, Tlist* t2);
int get_tokens(Tlist *t, FILE *fp);

/* 
  skipping all the empty characters and return the number of newLines on the way.
  if reached EOF return -1. 
*/
int devourEmpty(char *next, FILE *fp);

#endif