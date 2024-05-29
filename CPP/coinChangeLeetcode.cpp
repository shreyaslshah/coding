// https://leetcode.com/problems/coin-change/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> v(amount + 1, -1);
    v[0] = 0;

    for (int i = 1; i < v.size(); i++) {
      int mini = INT_MAX;
      for (int j = 0; j < coins.size(); j++) {
        if (i - coins[j] >= 0 and v[i - coins[j]] != -1) {
          mini = min(mini, v[i - coins[j]] + 1);
        }
      }
      if (mini != INT_MAX) {
        v[i] = mini;
      }
    }

    return v[amount];
  }
};