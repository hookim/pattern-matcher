#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ds.h"
#include "tokeneizer.h"


int main(void){
  Tlist * tl, *tl2;
  Token * tok;
  char buf[32];

  tl = (Tlist *) malloc(sizeof(Tlist));
  tlInit(tl);

  for(int i = 0 ; i < 5; i++){
    memset(buf, 0 , 32);
    printf(">> ");
    scanf("%s", buf);
    tok = (Token *) malloc(sizeof(Token));
    tokInit(tok);
    tokSet(tok, buf);
    tlAdd(tl, tok);
  }

  printTlist(tl);

  tl2 = (Tlist *)malloc(sizeof(Tlist));
  tlInit(tl2);

  tlAdd(tl2, tlSlice(tl, 2, 3));

  printTlist(tl);
  printTlist(tl2);

  return 0;
}