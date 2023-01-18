#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "ds.h"

void red()   { printf("\033[0;31m");}
void white() { printf("\033[0;37m");}
void blue()  { printf("\033[0;34m");}
void yellow(){ printf("\033[0;33m");}


void matcher(Matched *pair,  Tlist *tl1, Tlist *tl2){
  int cur1, cur2, idx1, idx2, len, max_len, slice_begin1, slice_begin2, skip;
  Token *beg1, *beg2, *end1, *end2;
  
  cur1 = 0; cur2 = 0;
  idx1 = -1; idx2 = -1;
  beg1 = tlHead(tl1); 
  beg2 = tlHead(tl2);
  end1 = beg1;
  end2 = beg2;
  len = 0;
  max_len = 0;

  // cur1 variable is not reset along the process
  while(beg1){
    while(beg2){
      if(end1 && end2 && strcmp(end1->data, end2->data) == 0){
        
        if(idx1 < 0) idx1 = cur1;
        if(idx2 < 0) idx2 = cur2;

        if(end1 && end2){
          end1 = end1->next;
          end2 = end2->next;
          len++;
          continue;
        }
        else{
          if(max_len < len){
            max_len = len;
            slice_begin1 = idx1;
            slice_begin2 = idx2;
          }
        }
      }
      else{
        if(max_len < len){
            max_len = len;
            slice_begin1 = idx1;
            slice_begin2 = idx2;
        }
      } 
      len = 0;
      end1 = beg1;
      beg2 = beg2->next;
      end2 = beg2;
      cur2++;
      idx1 = -1; idx2 = -1;
    }
    
    // only when there was match
    if(max_len > 0){
      for(skip = 0; beg1 && skip < max_len; skip++){
        beg1 = beg1->next;
      }  
      mPair(pair, tlSlice(tl1, slice_begin1, slice_begin1 + max_len -1),tlSlice(tl2, slice_begin2, slice_begin2 + max_len -1));
    }
    else if(max_len == 0){
      if(beg1)
        beg1 = beg1->next;
      // cur_1 is only incremented when there is no match
      cur1++; 
    }

    beg2 = tlHead(tl2);
    cur2 = 0;
    end1 = beg1; end2 = beg2;
    max_len = 0; len = 0;
    idx1 = -1; idx2 = -1;
  }
}

void printRes(Matched *m, char * f1, char *f2){
  int idx, ln, cn, tot_len, tok_idx;
  Matched * cur;
  Token * cur_tok;
  cur = m->next;
  idx = 1; tok_idx = 0;
  if(!cur){
    red();
    printf("found no match!\n");
    white();
  }

  while(cur){
    printf("* %d match\n", idx++);
    printf("--> ");
    yellow();
    cur_tok = cur->A;
    if((tot_len = tokLen(cur_tok)) > 6){
      while(cur_tok){
        if(tok_idx < 3 || tok_idx >= tot_len - 3)
          printf("%s ", cur_tok->data); 
        if(tok_idx == 3)
          printf(" ...  "); 
        cur_tok = cur_tok->next;
        tok_idx++;
      }
    }
    else{
      while(cur_tok){
        printf("%s ", cur_tok->data);
        cur_tok = cur_tok->next;
      }
    }
    printf("\n");
    white();
    cur_tok = cur->A;
    printf("    [%s] : from ", f1);
    blue();
    printf("(%d, %d) ", cur_tok->line_no, cur_tok->col_no);
    white();
    while(cur_tok->next)
      cur_tok = cur_tok -> next;
    printf("to ");
    blue();
    printf("(%d, %d)\n", cur_tok->line_no, cur_tok->col_no);
    white();
    
    cur_tok = cur->B;
    printf("    [%s] : from ", f2);
    blue();
    printf("(%d, %d) ", cur_tok->line_no, cur_tok->col_no);
    white();
    while(cur_tok->next)
      cur_tok = cur_tok -> next;
    printf("to ");
    blue();
    printf("(%d, %d)\n", cur_tok->line_no, cur_tok->col_no);
    white();

    cur = cur->next;
  }
}