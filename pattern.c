#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "ds.h"

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