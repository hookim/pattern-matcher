#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tokeneizer.h"
#include "ds.h"


void tokeneizer(char *fname1, char *fname2, Tlist *t1, Tlist *t2){
  FILE *fp1 = fopen(fname1, "r");
  FILE *fp2 = fopen(fname2, "r");

  get_tokens(t1, fp1);
  get_tokens(t2, fp2);

  fclose(fp1);
  fclose(fp2);
}

int get_tokens(Tlist * t, FILE *fp){
  Token *tok;
  char buf[BUF_MAX];
  char next;
  int line_no, tok_line, idx, nl;
  buf[0] = 0;
  idx = 0;
  line_no = 1;

  while(fread(&next, sizeof(char), 1, fp)){
    if(isspace(next)){
      if(buf[0]){
        buf[idx] = 0;
        tok = malloc(sizeof(Token));
        tokInit(tok);
        tokSet(tok, buf, tok_line, 0);
        tlAdd(t, tok);
        idx = 0;
        buf[0] = 0;
      }

      nl = devourEmpty(&next, fp);
      if(nl < 0)
        break;

      line_no += nl;
      buf[idx++] = next;
      tok_line = line_no;
    }
    else{
      if(!buf[0])
        tok_line = line_no;        
      buf[idx++] = next;
    }
  }

  if(buf[0]){
    buf[idx] = 0;
    tok = malloc(sizeof(Token));
    tokInit(tok);
    tokSet(tok, buf, tok_line, 0);
    tlAdd(t,tok);
  }

  t->tot_line = line_no;
}

int devourEmpty(char * next, FILE *fp){
  int newLine = 0;
  if (*next == '\n')
    newLine++;
  while(fread(next, sizeof(char), 1, fp)){
    if(!isspace(*next)) 
      break;
    if(*next == '\n')
      newLine++;
  }
  
  if(feof(fp))
    return -1;
  else
    return newLine;
} 
