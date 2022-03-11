// https://leetcode.com/problems/contains-duplicate/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  vector<int> nums{1, 1, 1, 3, 3, 4, 3, 2, 4, 2};

  sort(nums.begin(), nums.end());

  for (int i = 0; i < nums.size() - 1; i++)
  {
    if (nums.at(i) == nums.at(i + 1))
    {
      cout<< "true";
      return 0;
    }
  }
  cout<<"false";
}