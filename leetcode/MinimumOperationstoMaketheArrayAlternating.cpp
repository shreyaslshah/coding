// https://leetcode.com/problems/minimum-operations-to-make-the-array-alternating/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
  vector<int> nums{2, 2, 2, 2};

  if (nums.size() == 1) {
    cout << 0 << endl;
    return 0;
  }

  if (nums.size() == 2 && nums[0] == nums[1]) {
    cout << 1 << endl;
    return 1;
  }

  if (nums.size() == 2 && nums[0] != nums[1]) {
    cout << 0 << endl;
    return 0;
  }

  unordered_map<int, int> evenIndicesMap;
  unordered_map<int, int> oddIndicesMap;

  for (int i = 0; i < nums.size(); i += 2) {
    if (evenIndicesMap.find(nums[i]) != evenIndicesMap.end()) {
      evenIndicesMap[nums[i]]++;
    } else {
      evenIndicesMap.insert({nums[i], 1});
    }
  }

  for (int i = 1; i < nums.size(); i += 2) {
    if (oddIndicesMap.find(nums[i]) != oddIndicesMap.end()) {
      oddIndicesMap[nums[i]]++;
    } else {
      oddIndicesMap.insert({nums[i], 1});
    }
  }

  unordered_map<int, int>::iterator emi = evenIndicesMap.end();
  int emf = 0;
  unordered_map<int, int>::iterator esmi = evenIndicesMap.end();
  int esmf = 0;
  for (auto it = evenIndicesMap.begin(); it != evenIndicesMap.end(); it++) {
    if (it->second > emf) {
      esmi = emi;
      esmf = (emi == evenIndicesMap.end()) ? 0 : emi->second;
      emi = it;
      emf = it->second;
    } else if (it->second > esmf) {
      esmi = it;
      esmf = it->second;
    }
  }

  unordered_map<int, int>::iterator omi = oddIndicesMap.end();
  int omf = 0;
  unordered_map<int, int>::iterator osmi = oddIndicesMap.end();
  int osmf = 0;
  for (auto it = oddIndicesMap.begin(); it != oddIndicesMap.end(); it++) {
    if (it->second > omf) {
      osmi = omi;
      osmf = (omi == oddIndicesMap.end()) ? 0 : omi->second;
      omi = it;
      omf = it->second;
    } else if (it->second > osmf) {
      osmi = it;
      osmf = it->second;
    }
  }

  int ans = INT_MAX;

  if (omi->first == emi->first && evenIndicesMap.size() == 1 && oddIndicesMap.size() == 1) {
    ans = nums.size() / 2;
  } else if (omi->first == emi->first) {
    if (osmi != oddIndicesMap.end()) {
      ans = min(ans, (int)(nums.size() - osmi->second - emi->second));
    }
    if (esmi != evenIndicesMap.end()) {
      ans = min(ans, (int)(nums.size() - omi->second - esmi->second));
    }
  } else {
    ans = nums.size() - omi->second - emi->second;
  }

  cout << ans << endl;
}