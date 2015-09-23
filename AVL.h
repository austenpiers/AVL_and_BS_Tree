#ifndef AVL_H
#define AVL_H
#include "AVLBN.h"

class AVL{
 public:
	
  AVLBN *H;
  	
 AVL():H(NULL){};
  ~AVL(){};
  
  bool P();
  bool A(int);
  bool I(int);
  bool I(AVLBN*,int);
  bool R(int, AVLBN*);

  void shuffle(AVLBN*);
  void RR(AVLBN*);
  void LL(AVLBN*);

  int ds(AVLBN *);
  int ds2(AVLBN*);
  
  int Hi(AVLBN *n);
  int newHi(AVLBN *n);
  int Bal(AVLBN *n);

  bool Rm(int, AVLBN*);
};

#endif
