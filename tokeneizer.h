#ifndef _TOKENEIZER_H_
#define _TOKENEIZER_H_

#include <stdio.h>
#include "ds.h"

#define BUF_MAX 1024

int get_token(Tlist *t, FILE *fp);
void tokeneizer(Tlist *t1, Tlist* t2);


#endif