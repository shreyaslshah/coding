// https://leetcode.com/problems/3sum/

#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  vector<int> nums{-1, 0, 1, 2, -1, -4};
  sort(nums.begin(), nums.end());
  int fixed;
  int i, j;
  int sum;
  vector<vector<int>> ans;
  if (nums.size() >= 3)
  {
    for (fixed = 0; fixed < nums.size() - 2; fixed++)
    {
      
      i = fixed + 1;
      j = nums.size() - 1;
      while (i < j)
      {
        sum = nums[i] + nums[j];
        if (sum == -(nums[fixed]))
        {
          vector<int> a{nums[fixed], nums[i], nums[j]};
          ans.push_back(a);
          while (i < j && nums[i] == a[1])
            i++;
          while (i < j && nums[j] == a[2])
            j--;
          // break;
        }
        else if (sum < (-nums[fixed]))
        {
          i++;
        }
        else
        {
          j--;
        }
      }

      while (fixed + 1 < nums.size() && nums[fixed + 1] == nums[fixed])
      {
        fixed++;
      }

    }
  }
  else
  {
    exit(0);
  }

  for (vector<int> vec : ans)
  {
    for (int x : vec)
    {
      cout << x << " ";
    }
    cout << endl;
  }
}