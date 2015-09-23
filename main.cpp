#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

using namespace std;

int main(int argc, char *argv[])
{
  BST *myBST = new BST();
  char buffer[256];
  bool result;
  int o;
  
  while(cin.getline(buffer, 256))
    {
      string command(buffer);
      
      if(command.compare(0,6,"insert") == 0){
	o = atoi(&(command[7]));
	if(myBST->I(o)){
	  cout << "Element inserted" << endl;
	  continue;
	}
	cout << "Element already present" << endl;
	continue;
      }
      if(command.compare("print") == 0){
	if(!(myBST->P()))
	  cout << "Empty tree" << endl;
	continue;
      }
      if(command.compare(0,6,"access") == 0){
	o = atoi(&(command[7]));
	if(result = myBST->A(o)){
	  cout << "Element accessed" << endl;
	  continue;
	}
	cout << "Element not found" << endl;
	continue;
      }
      if(command.compare(0,6,"delete") == 0){
	o = atoi(&(command[7]));
	if(myBST->R(o, myBST->H)){
	  cout << "Element deleted" << endl;
	  continue;
	}
	cout << "Element not found" << endl;
	continue;
      }
      else
	cout << "Invalid Command" << endl;
    }
}
