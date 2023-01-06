#ifndef _DS_H_
#define _DS_H_

#define NULL 0

struct _TextList{
  int tot_line; 
  int tot_tok;
  struct _Token *root;
};

struct _Token{
  int line_no;
  int col_no;
  char *data;
  struct _Token *next;
};

struct _Matched{
  struct _Token *A;
  struct _Token *B;
  struct _Matched *next;
};

typedef struct _TextList Tlist;
typedef struct _Token Token;
typedef struct _Matched Matched;

// TextList methods
void tlAdd(Tlist *tl, Token *tok);
void tlInit(Tlist *tl);
Token *tlSlice(Tlist *tl, int begin, int end);
void printTlist(Tlist *tl);

//Token methods
void tokInit(Token *tok);
void tokSet(Token *tok, char* buf, int line_no, int col_no);

//Matched methods
void mInit(Matched * head);
void mPair(Matched * head, Token *A, Token *B);

#endif
