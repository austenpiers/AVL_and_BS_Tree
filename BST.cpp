#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string.h>
#include "stack"
#include "string"
#include "BST.h"

//PRINT : pre-, in-, and post- order
bool BST::P(){	
  if(H==NULL)
    return false;
  
  using namespace std;
  
  BN *h = H;
  stack<BN *> SK;
  string i;
  ostringstream T;
  
  while(1){
    while(h!=NULL){
      cout << h->V << " ";
      SK.push(h);
      h=h->L;
    }
    if(SK.empty()==true)
      break;
    
    T << (SK.top())->V << " ";
    
    h = (SK.top())->R;
    SK.pop();
  }
  cout << endl << T.str() << endl; //prints newline and in-order
  
  SK.push(H);
  BN *p = NULL;
  while (!SK.empty()) {
    h = SK.top();

    if (!p || p->L == h || p->R == h)
      {
	if(h->L){
	  SK.push(h->L);
	  p = h;
	  continue;
	}
	if(h->R){
	  SK.push(h->R);
	  p = h;
	  continue;
	} 
	cout << h->V << " ";
        SK.pop();
	p = h;
	continue;
      } 
    if(h->L==p){
      if(h->R){
        SK.push(h->R);
	p = h;
	continue;
      }
      cout << h->V << " ";
      SK.pop();
      p = h;
      continue;
    }
    if(h->R==p) {
      cout << h->V << " ";
      SK.pop();
      p = h;
      continue;
    }
  }
  cout << endl;
  return true;
}
//accessor
bool BST::A(int a){
  BN *n = H;
  while(n!=NULL){
    if(n->V<a){
      n=n->R;  continue;
    }
    if(n->V>a){
      n=n->L;  continue;
    }
    return true;
  }
  return false;
}

//Insert into root
bool BST::I(int a){
  if(H!=NULL)
    return(I(H,a));		
  H = new BN(a);
  return true;
}
//Insert into Tree
bool BST::I(BN* n,int a){
  if(n->V>a){
    if(n->L==NULL){
      n->L = new BN(a);
      return true;
    }
    return(I(n->L,a));
  }
  if(n->V<a){
    if(n->R==NULL){
      n->R = new BN(a);
      return true;
    }
    return(I(n->R,a));
  }
  return false;
}
//Remove
bool BST::R(int d, BN* n){
  BN **P = &(H);
  while(n!=NULL){
    if(n->V < d){
      P = &(n->R);  n=n->R;  continue;
    }
    if(n->V > d){
      P = &(n->L);  n=n->L; continue;
    }
    break;
  }
  if(n==NULL)
    return false;
  if(n->L==NULL){
    (*P)=n->R;  delete n;  return true;
  }
  if(n->R == NULL){
    (*P)=n->L;  delete n;  return true;
  }
	
  BN *C = n->R, **PC;
  if(C->L==NULL){
    (*P)=C;  C->L=n->L;  return true;
  }
  while(C->L!=NULL){
    PC = &(C->L);  C=C->L;
  }
  
  *(PC)=NULL;
  *P = C;
  C->L=n->L;
  delete n;
  return true;
}





