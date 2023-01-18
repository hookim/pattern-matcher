#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tokeneizer.h"
#include "ds.h"


void tokeneizer(char *fname1, char *fname2, Tlist *t1, Tlist *t2){
  FILE *fp1, *fp2;
  if(!(fp1 = fopen(fname1, "r"))){
    fprintf(stderr, "file open error for %s\n", fname1);
    exit(1);
  }

  if(!(fp2 = fopen(fname2, "r"))){
    fprintf(stderr, "file open error for %s\n", fname2);
    exit(1);
  }
  
  get_tokens(t1, fp1);
  get_tokens(t2, fp2);

  fclose(fp1);
  fclose(fp2);
}

int get_tokens(Tlist * t, FILE *fp){
  Token *tok;
  char buf[BUF_MAX];
  char next;
  int line_no, col_no, tok_line, tok_col, idx, nl;
  buf[0] = 0;
  idx = 0;
  line_no = 1; 
  col_no = 0;
  while(fread(&next, sizeof(char), 1, fp)){
    col_no++;
    if(!isalpha(next) && !isdigit(next)){
      // if any previous work left, save it.
      if(buf[0]){
        buf[idx] = 0;
        tok = malloc(sizeof(Token));
        tokInit(tok);
        tokSet(tok, buf, tok_line, tok_col);
        tlAdd(t, tok);
        idx = 0;
        buf[0] = 0;
      }
      // if cur next is empty space devour trailing empty spaces 
      if(isspace(next)){
        nl = devourEmpty(&next, &col_no, fp);
        if(nl < 0)
          break;
        line_no += nl;
        //if encounter new line then col_no is reset to 0
        buf[idx++] = next;
        tok_line = line_no;
        tok_col = col_no;
      }
      // if not (special characters like . / ' * " \ { [ ... ) save this as well 
      if(!isalpha(next) && !isdigit(next)){
        tok_line = line_no; tok_col = col_no;
        buf[0] = next;
        buf[1] = 0;
        tok = malloc(sizeof(Token));
        tokInit(tok);
        tokSet(tok, buf, tok_line, tok_col);
        tlAdd(t, tok);
        buf[0] = 0;
        idx = 0;
      }
    }
    else{
      if(!buf[0]){
        tok_line = line_no; 
        tok_col = col_no;       
      }
      buf[idx++] = next;
    }
  }

  if(buf[0]){
    buf[idx] = 0;
    tok = malloc(sizeof(Token));
    tokInit(tok);
    tokSet(tok, buf, tok_line, tok_col);
    tlAdd(t,tok);
  }

  t->tot_line = line_no;
}

int devourEmpty(char * next, int* col, FILE *fp){
  int newLine = 0;
  if (*next == '\n'){
    *col = 0;
    newLine++;
  }
  while(fread(next, sizeof(char), 1, fp)){
    (*col)++;
    if(!isspace(*next)) 
      break;
    if(*next == '\n'){
      *col = 0;
      newLine++;
    }
  }
  
  if(feof(fp))
    return -1;
  else
    return newLine;
} 
