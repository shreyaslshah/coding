// https://leetcode.com/problems/climbing-stairs/submissions/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int climbStairs(int n) {
    vector<int> v(n + 1);
    v[0] = v[1] = 1;
    for (int i = 2; i <= n; i++) {
      v[i] = v[i - 2] + v[i - 1];
    }
    return v[n];
  }
};