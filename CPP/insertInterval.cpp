// https://leetcode.com/problems/insert-interval/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval);

class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> ans;

    bool firstInserted = false;
    bool secondInserted = false;
    int first = newInterval[0];
    int second = newInterval[1];

    for (int i = 0; i < intervals.size(); i++) {
      if (!firstInserted and !secondInserted) {
        if (intervals[i][0] > first) {
          intervals.insert(intervals.begin() + i, vector<int>{first});
          firstInserted = true;
        } else if (intervals[i][0] <= first and intervals[i][1] >= first) {
          intervals[i].insert(intervals[i].begin() + 1, first);
          firstInserted = true;
          if (second <= intervals[i][2]) {
            intervals[i].insert(intervals[i].begin() + 2, first);
            secondInserted = true;
          }
        }

      } else if (firstInserted and !secondInserted) {
        if (intervals[i][0] > second) {
          intervals.insert(intervals.begin() + i, vector<int>{second});
          secondInserted = true;
        } else if (intervals[i][0] <= second and intervals[i][1] >= second) {
          intervals[i].insert(intervals[i].begin() + 1, second);
          secondInserted = true;
        }
      }
    }

    if (!firstInserted) {
      intervals.push_back(vector<int>{first});
      firstInserted = true;
    }

    if (!secondInserted) {
      intervals.push_back(vector<int>{second});
      secondInserted = true;
    }

    int i = 0;

    while (i < intervals.size()) {
      if (intervals[i].size() == 2) {
        ans.push_back(intervals[i]);
        i++;
      } else if (intervals[i].size() == 4) {
        ans.push_back({intervals[i][0], intervals[i][3]});
        i++;
      } else {
        first = intervals[i][0];
        if (i < intervals.size() - 1) {
          i++;
        }
        while (i < intervals.size() and intervals[i].size() == 2) {
          i++;
        }
        second = intervals[i][intervals[i].size() - 1];
        ans.push_back({first, second});
        i++;
      }
    }

    return ans;
  }
};

int main() {
  Solution s;
  vector<vector<int>> intervals{{4,5}};
  vector<int> newInterval{2,3};

  vector<vector<int>> ans = insert(intervals, newInterval);

  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}

// better soln
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
  if (intervals.size() == 0) {
    return vector<vector<int>>{newInterval};
  }

  int a = 0;
  int b = intervals.size() - 1;

  while (a < intervals.size() and intervals[a][1] < newInterval[0]) {
    a++;
  }

  while (b >= 0 and intervals[b][0] > newInterval[1]) {
    b--;
  }

  int lower = newInterval[0];
  int upper = newInterval[1];

  for (int i = a; i < intervals.size(); i++) {
    lower = min(intervals[i][0], lower);
  }

  for (int i = b; i >= 0; i--) {
    upper = max(intervals[i][1], upper);
  }

  vector<vector<int>> ans;

  for (int i = 0; i < a; i++) {
    ans.push_back(intervals[i]);
  }
  ans.push_back({lower, upper});
  for (int i = b + 1; i < intervals.size(); i++) {
    ans.push_back(intervals[i]);
  }

  return ans;
}