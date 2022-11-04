// https://leetcode.com/problems/remove-k-digits/

// Let's think about the simplest case: how to remove 1 digit from the number so that the new number is the smallest possible？ Well, one can simply scan from left to right, and remove the first "peak" digit; the peak digit is larger than its right neighbor.

// go as close as possible to ascending order

// https://www.youtube.com/watch?v=3QJzHqNAEXs

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
  string num = "10";
  int k = 2;
  stack<char> stck;

  for (int i = 0; i < num.length(); i++) {
    while (!stck.empty() && stck.top() > num[i] && k > 0) {
      stck.pop();
      k--;
    }
    if (!(stck.empty() && num[i] == '0')) {
      stck.push(num[i]);
    }
  }

  while (k > 0 && !stck.empty()) {
    stck.pop();
    k--;
  }

  string ans;
  while (!stck.empty()) {
    ans.push_back(stck.top());
    stck.pop();
  }

  reverse(ans.begin(), ans.end());

  cout << ans << endl;
}