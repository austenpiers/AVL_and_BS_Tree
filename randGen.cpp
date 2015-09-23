#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string.h>
#include <time.h>
#include "vector"
using namespace std;

int main(int argc, char *argv[])
{
  vector<int> nums, num;
  srand(time(NULL));
  ofstream file;
  file.open("ran.txt");

  for(int i = 1; i < 10001; i++){
    nums.push_back(((rand()%10001)+1));
    file << "insert " << nums[nums.size()-1] << endl;
  }
  for(int i = 1; i < 10001; i++){
    int p= (rand()%nums.size());
    file << "access " << nums[p] << endl;
    num.push_back(nums[p]);
    nums[p] = nums[nums.size()-1];
    nums.pop_back();
  }
  for(int i = 1; i < 10001; i++){
    int p = (rand()%num.size());
    file << "delete " << num[p] << endl;
    num[p] = nums[num.size()-1];
    num.pop_back();
  }
  return 0;
}
