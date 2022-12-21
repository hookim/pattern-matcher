#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokeneizer.h"
#include "ds.h"

int countA, countB;
int line_noA, line_noB;
char buf[BUF_MAX];

int get_token(Tlist * t, FILE *fp){
  char c;
  int idx;
  memset(buf, 0, BUF_MAX);

  idx = 0;
  while(fread(&c , sizeof(char), 1, fp)){
    buf[idx++] = c;
  }
  
}