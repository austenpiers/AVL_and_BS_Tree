#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string.h>
using namespace std;

int main(int argc, char *argv[])
{
  ofstream file;
  file.open("in.txt");
  for(int i = 1; i < 10001; i++)
    file << "insert " << i << endl;
  for(int i = 1; i < 10001; i++)
    file << "access " << i << endl;
  for(int i = 1; i < 10001; i++)
    file << "delete " << i << endl;
  return 0;
}
