#include <stdio.h>
#include <stdlib.h>

#include "tokeneizer.h"
#include "ds.h"
#include "pattern.h"


int main(int argc, char ** argv){
  if(argc < 3){
    fprintf(stderr ,"usage : [program] [filename1] [filename2]\n");
    exit(1);
  }
  Tlist * tl1, *tl2;
  Matched * pair; 
  tl1 = (Tlist *)malloc(sizeof(Tlist));
  tl2 = (Tlist *)malloc(sizeof(Tlist));
  pair = (Matched *) malloc(sizeof(Matched));

  tlInit(tl1);
  tlInit(tl2);
  mInit(pair);

  tokeneizer(argv[1], argv[2], tl1, tl2);
  matcher(pair, tl1, tl2);
  printRes(pair, argv[1],argv[2]);
  
}