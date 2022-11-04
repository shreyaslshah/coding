// https://leetcode.com/problems/minimum-window-substring/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string minWindow(string s, string t) {
    unordered_map<char, pair<int, int>> present;  // character /no. in t / no. in substr
    int remaining = 0;
    int min = INT_MAX;
    int minfront, minrear;
    for (auto c : t) {
      if (present.find(c) == present.end()) {
        remaining++;
        present[c] = {0, 0};
      }
      present[c].first++;
    }

    int front = 0, rear = 0;
    while (present.find(s[rear]) == present.end() and rear<s.size()) {
      rear++;
      front++;
    }

    while (front < s.size()) {
      if (present.find(s[front]) != present.end()) {
        present[s[front]].second++;
        if (present[s[front]].second == present[s[front]].first) {
          remaining--;
        }
        // while (present[q.front().first].second > present[q.front().first].first) {
        //   present[q.front().first].second--;
        //   q.pop();
        //   rear = q.front().second;
        // }
        while (present.find(s[rear]) == present.end() or present[s[rear]].second > present[s[rear]].first) {
          if (present.find(s[rear]) != present.end()) {
            present[s[rear]].second--;
          }
          rear++;
        }
        if (min > front - rear + 1 and remaining == 0) {
          minfront = front;
          minrear = rear;
          min = front - rear + 1;
        }
      }
      front++;
    }

    return remaining ? "" : string(&s[minrear], &s[minfront + 1]);
  }
};

int main() {
  Solution s;
  cout << s.minWindow("a", "b") << endl;
}