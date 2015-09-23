#ifndef AVLBN_H
#define AVLBN_H

class AVLBN{
 public:
  int V;
  int H;
  AVLBN *R;
  AVLBN *L;
  
 AVLBN(int i):V(i),R(NULL),L(NULL),H(0){};
  ~AVLBN(){};
};

#endif
