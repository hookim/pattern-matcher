#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ds.h"
#include "tokeneizer.h"


void test_ds(){
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
    // tokSet(tok, buf);
    tlAdd(tl, tok);
  }

  printTlist(tl);

  tl2 = (Tlist *)malloc(sizeof(Tlist));
  tlInit(tl2);

  tlAdd(tl2, tlSlice(tl, 2, 3));

  printTlist(tl);
  printTlist(tl2);
};
void test_tokeneizer(){
  char *fname1, *fname2;
  Tlist * tl1, *tl2;
  tl1 = malloc(sizeof(Tlist));
  tl2 = malloc(sizeof(Tlist));
  fname1 = "test1.txt";
  fname2 = "test2.txt";

  tlInit(tl1);
  tlInit(tl2);

  tokeneizer(fname1, fname2, tl1, tl2);
  
  printf("<<<< tl1 >>>> \n");
  printf("total_line : %d, total_tokens : %d\n", tl1->tot_line, tl1->tot_tok);
  printTlist(tl1);

  printf("<<<< tl2 >>>> \n");
  printf("total_line : %d, total_tokens : %d\n", tl2->tot_line, tl2->tot_tok);
  printTlist(tl2);

}

int main(void){
  test_tokeneizer();
  return 0;
}