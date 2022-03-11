// https://leetcode.com/problems/contains-duplicate-ii/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
  unordered_map<int, int> map;
  for (int i = 0; i < nums.size(); i++) {
    if (map.find(nums[i]) == map.end()) {
      map.insert({nums[i], i});
    } else {
      if (abs(map[nums[i]] - i) <= k) {
        return true;
      } else {
        map[nums[i]] = i;
      }
    }
  }
  return false;
}

int main() {
  vector<int> nums = {1, 2, 3, 1, 2, 3};
  int k = 2;
  cout << containsNearbyDuplicate(nums, k) << endl;
}