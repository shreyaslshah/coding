// https://leetcode.com/problems/trapping-rain-water/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int trap(vector<int>& height) {
    vector<pair<int, int>> vec(height.size());
    int ans = 0;
    vec[0].first = 0;
    vec[height.size() - 1].second = 0;
    int m = height[0];
    for (int i = 1; i < height.size(); i++) {
      vec[i].first = m;
      m = max(m, height[i]);
    }
    m = height[height.size() - 1];
    for (int i = height.size() - 2; i >= 0; i--) {
      vec[i].second = m;
      m = max(m, height[i]);
    }
    for (int i = 0; i < height.size(); i++) {
      if (min(vec[i].first, vec[i].second) - height[i] > 0) {
        ans += (min(vec[i].first, vec[i].second) - height[i]);
      }
    }
    return ans;
  }
};

// stack soln
/*
int trap(vector<int>& height) {
  int ans = 0, current = 0;
  stack<int> st;
  while (current < height.size()) {
    while (!st.empty() && height[current] > height[st.top()]) {
      int top = st.top();
      st.pop();
      if (st.empty())
        break;
      int distance = current - st.top() - 1;
      int bounded_height = min(height[current], height[st.top()]) - height[top];
      ans += distance * bounded_height;
    }
    st.push(current++);
  }
  return ans;
}
*/