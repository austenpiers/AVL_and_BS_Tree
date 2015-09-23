#ifndef BST_H
#define BST_H
#include "BN.h"

class BST{
 public:
	
  	BN *H;
  	
 	BST():H(NULL){};
  	~BST(){};

  	bool P();
  	bool A(int);
  	bool I(int);
  	bool I(BN*,int);
  	bool R(int, BN*);
};

#endif
