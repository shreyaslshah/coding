// https://leetcode.com/problems/first-unique-character-in-a-string/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  string s = "loveleetcode";

  unordered_map<char, pair<int, int>> map;  // char, freq, index

  for (int i = 0; i < s.length(); i++) {
    if (map.count(s[i])) {
      map[s[i]].first++;
    } else {
      map[s[i]].first = 1;
      map[s[i]].second = i;
    }
  }

  int index = s.length();
  for (auto it = map.begin(); it != map.end(); it++) {
    if (it->second.first == 1) {
      index = min(it->second.second, index);
    }
  }
  cout << ((index == s.length()) ? -1 : index);
}