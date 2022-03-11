// https://leetcode.com/problems/subarray-sum-equals-k/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int subarraySum(vector<int>& nums, int k) {
  unordered_map<int, int> map;
  int ans = 0;
  int runningSum = 0;

  for (int i = 0; i < nums.size(); i++) {
    runningSum += nums[i];

    if (map.find(runningSum - k) != map.end()) {
      ans += map[runningSum - k];
    }
    if (runningSum == k) {
      ans++;
    }
    map[runningSum]++;
  }

  return ans;
}

int main() {
  vector<int> nums = {1,1,1};
  int k = 2;
  int ans = subarraySum(nums, k);
  cout << ans << endl;
}