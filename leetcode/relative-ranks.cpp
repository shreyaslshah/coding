// https://leetcode.com/problems/relative-ranks/

#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
  vector<int> score{10, 3, 8, 9, 4};

  priority_queue<pair<int, int>> qu;

  for (int i = 0; i < score.size(); i++)
  {
    qu.push(make_pair(score.at(i), i));
  }

  vector<string> position(score.size(), "");

  int count = 0;

  while (!qu.empty())
  {
    int x = qu.top().first;
    int pos = qu.top().second;
    qu.pop();

    if (count == 0)
      position.at(pos) = "Gold Medal";
    else if (count == 1)
      position.at(pos) = "Silver Medal";
    else if (count == 2)
      position.at(pos) = "Bronze Medal";
    else
      position.at(pos) = to_string(count + 1);

    count++;
  }

  for (string p : position)
  {
    cout << p << " ";
  }
}