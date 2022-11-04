// https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int minimumDifference(vector<int>& nums, int k) {
  sort(nums.begin(), nums.end());

  if (k == 1)
    return 0;

  int i = 0;
  int j = k - 1;

  int min = INT_MAX;

  for (; j < nums.size(); i++, j++) {
    if (nums[j] - nums[i] < min)
      min = nums[j] - nums[i];
  }

  return min;
}

int main() {
  vector<int> nums = {9, 4, 1, 7};
  int k = 2;
  cout << minimumDifference(nums, k) << endl;
}