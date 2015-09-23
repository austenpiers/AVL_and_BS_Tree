#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include "AVL.h"

using namespace std;

int main(int argc, char *argv[])
{
  clock_t myClock;
  double duration;
  myClock = clock();
  AVL *myAVL = new AVL();
  char buffer[256];
  bool result;
  int o;
  
  while(cin.getline(buffer, 256))
    {
      string command(buffer);
      
      if(command.compare(0,6,"insert") == 0){
	o = atoi(&(command[7]));
	if(myAVL->I(o)){
	  cout << "Element inserted" << endl;
	  continue;
	}
	cout << "Element already present" << endl;
	continue;
      }
      if(command.compare("print") == 0){
	if(!(myAVL->P()))
	  cout << "Empty tree" << endl;
	continue;
      }
      if(command.compare(0,6,"access") == 0){
	o = atoi(&(command[7]));
	if(result = myAVL->A(o)){
	  cout << "Element accessed" << endl;
	  continue;
	}
	cout << "Element not found" << endl;
	continue;
      }
      if(command.compare(0,6,"delete") == 0){
	o = atoi(&(command[7]));
	if(myAVL->R(o, myAVL->H)){
	  cout << "Element deleted" << endl;
	  continue;
	}
	cout << "Element not found" << endl;
	continue;
      }
      else
	cout << "Invalid Command" << endl;
    }
  duration = (((double)(clock()-myClock))/CLOCKS_PER_SEC);
  cout << "fuck that was annoying.. Time: " << duration << endl;
}
