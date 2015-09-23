#ifndef BN_H
#define BN_H

class BN{
 public:
  int V;
  BN *R;
  BN *L;
  
 BN(int i):V(i),R(NULL),L(NULL){};
  ~BN(){};
};

#endif
