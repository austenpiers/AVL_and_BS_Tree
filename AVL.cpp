#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <string.h>
#include "stack"
#include "string"
#include "AVL.h"

//PRINT : pre-, in-, and post- order
bool AVL::P(){	
  if(H==NULL)
    return false;
  
  using namespace std;
  
  AVLBN *h = H;
  stack<AVLBN *> SK;
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

  AVLBN *p = NULL;
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
bool AVL::A(int a){
  AVLBN *n = H;
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
bool AVL::I(int a){
  if(H!=NULL)
    return(I(H,a));		
  H = new AVLBN(a);
  return true;
}
//Insert into Tree
bool AVL::I(AVLBN* n,int a){
  bool f;

  if(n->V>a){
    if(n->L==NULL){
      n->L = new AVLBN(a);
      n->H = newHi(n);
      return true;
    }
    else
      f = (I(n->L,a));
  }
  else if(n->V<a){
    if(n->R==NULL){
      n->R = new AVLBN(a);
      n->H = newHi(n);
      return true;
    }
    else
      f = (I(n->R,a));
  }
  else
    return false;

  if(f){
    n->H = newHi(n);
    shuffle(n);    
  }
  return(f);
}
//Remove
bool AVL::R(int d, AVLBN* n){
  if(H==NULL)
    return false;
  if(H->L == H->R){
    if(H->V != d)
      return false;
  }
  if(H->V == d){
    if(H->L==NULL){
      AVLBN *temp = H;
      H = H->R;
      delete temp;
      return true;
    }
    if(H->R == NULL){
      AVLBN *temp = H;
      H = H->L;
      delete temp;
      return true;
    }
    if(Hi(H->L) > Hi(H->R)){
      AVLBN *tempora = H->L;
      if(tempora->R == NULL){
	tempora->R =  H->R;
	delete H;
	H = tempora;
        return true;
      }
      AVLBN *ni;
      while(tempora->R!=NULL){
	ni = tempora;
	tempora = tempora->R;
      }
      ni->R = NULL;
      H->V = tempora->V;
      delete tempora;
      return true;
    }
    else{ 
      AVLBN *tempora = H->R;
      if(tempora->L == NULL){
	tempora->L = H->L;
	delete H;
	H = tempora;
	return true;
	AVLBN *ni;
	while(tempora->L!=NULL){
	  ni = tempora;
	  tempora = tempora->L;
	}
	ni->L = NULL;
	H->V = tempora->V;
	delete tempora;
      }
    }
    H->H = newHi(H);
    shuffle(H);
    return true;
  }

  return(this->Rm(d, H));
}



bool AVL::Rm(int d, AVLBN *n)
{
  bool r;
  if(n == NULL)
    r = false;
  else if(n->V < d)
    {
      if(n->R == NULL)
	r = false;
      else if(n->R->V != d)
	r = Rm(d,n->R);
      else if(n->R->V == d)
	{
	  r = true;
	  if(n->R->L == NULL && n->R->R == NULL)
	    {
	      delete n->R;
	      n->R = NULL;
	    }
	  else if((n->R->L == NULL) != (n->R->R == NULL))
	    {
	      AVLBN *t = n->R;
	      if(n->R->R != NULL)
		n->R = n->R->R;
	      else if(n->R->L != NULL)
		n->R = n->R->L;
	      delete t;
	    }
	  else if(n->R->R != NULL && n->R->L != NULL)
	    {
	      n->R->V = ds(n->R);
	      shuffle(n->R);
	    }
	}
    }
  else if(n->V > d)
  {
    if(n->L == NULL)
      r = false;
    else if(n->L->V != d)
      r = Rm(d,n->L);
    else if(n->L->V == d)
      {
	r = true;
	if(n->L->L == NULL && n->L->R == NULL)
	  {
	    delete n->L;
	    n->L = NULL;
	  }
	else if((n->L->L == NULL) !=  (n->L->R == NULL))
	  {
	    AVLBN *t = n->L;
	    if(n->L->L != NULL)
	      n->L = n->L->L;
	    else if(n->L->R != NULL)
	      n->L = n->L->R;
	    delete t;
	  }
	else if(n->L->R != NULL && n->L->L != NULL)
	  {
	    n->L->V = ds(n->L);
	    shuffle(n->L);
	  }
      }
  }
  newHi(n);
  shuffle(n);

  return r;

}

int AVL::ds(AVLBN *n)
{
  int t;
  AVLBN *s;
  if(n->R->L == NULL){
      t = n->R->V;
      s = n->R;
      n->R = n->R->R;
      delete s;
    }
  else
    t = ds2(n->R);
  newHi(n);                                                       
  return t;
}

int AVL::ds2(AVLBN *n)
{
  int t;
  AVLBN *s;
  if(n->L->L == NULL){
    t = n->L->V;
    s = n->L;
    n->L = n->L->R;
    delete s;
  }
  else
    t = ds2(n->L);
  
  newHi(n);
  shuffle(n);
  return t;
}


void AVL::shuffle(AVLBN *n){
  //std::cout << "shuffle\n";
  if(Bal(n) == -2){
    //std::cout << "too heavy right\n";
    if(Hi(n->R->L) > Hi(n->R->R))
      RR(n->R);
    LL(n); 
    return; 
  } 
  if(Bal(n) == 2){ 
    if(Hi(n->L->R) > Hi(n->L->L))
      LL(n->L);
    RR(n); 
    return; 
  } 
} 

void AVL::RR(AVLBN *n){
  //std::cout << "RR\n";
  AVLBN *T1 = n->L->L, *T2 = n->L->R, *T3 = n->R;
  int t = n->V, st = n->L->V;
  delete n->L;
  
  n->V = st;
  n->R = new AVLBN(t);
  n->L = T1;  n->R->L = T2;  n->R->R = T3;
			       
  n->R->H = newHi(n->R); n->H = newHi(n);
} 

void AVL::LL(AVLBN *n){
  //std::cout << "RR\n";
  AVLBN *T3 = n->R->R, *T2 = n->R->L, *T1 = n->L;
  int t = n->V, st = n->R->V;
  delete n->R;
  
  n->V = st;
  n->L = new AVLBN(t);
  n->R = T3;  n->L->R = T2;  n->L->L = T1;

  n->L->H = newHi(n->L); n->H = newHi(n);
} 

int AVL::Hi(AVLBN *n){if(n!=NULL) return n->H; return -1;};

int AVL::newHi(AVLBN *n){
  //std::cout << "newHi\n";
  int RH = Hi(n->R), LH = Hi(n->L);
  if(LH > RH)
    return(LH+1);
  return(RH+1);
};

int AVL::Bal(AVLBN *n){
  //std::cout << "Bal\n";
  int RH = Hi(n->R), LH = Hi(n->L);
  return (LH - RH);
}
