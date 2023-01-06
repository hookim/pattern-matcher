#include <stdio.h>
#include <stdlib.h>

#include "tokeneizer.h"
#include "ds.h"


int main(int argc, char ** argv){
  if(argc < 3){
    fprintf(stderr ,"usage : [program] [filename1] [filename2]");
    exit(1);
  }
  Tlist * tl1, *tl2;
  tl1 = (Tlist *)malloc(sizeof(Tlist));
  tl2 = (Tlist *)malloc(sizeof(Tlist));

  tlInit(tl1);
  tlInit(tl2);

  tokeneizer(argv[1], argv[2], tl1, tl2);
  
}