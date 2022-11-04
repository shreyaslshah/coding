// https://leetcode.com/problems/time-needed-to-buy-tickets/

// explanation -> https://www.youtube.com/watch?v=Q6IL1567HeE


#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  vector<int> tickets{5, 1, 1, 1};
  int k = 0;

  int time = 0;
  queue<pair<int, int>> qu;
  for (int i = 0; i < tickets.size(); i++) {
    qu.push(make_pair(i, tickets[i]));
  }

  while (!(qu.front().first == k && qu.front().second == 1)) {
    qu.front().second--;
    time++;
    auto x = qu.front();
    if (x.second != 0) {
      qu.push(x);
    }
    qu.pop();
  }
  time++;

  cout << time << endl;
}