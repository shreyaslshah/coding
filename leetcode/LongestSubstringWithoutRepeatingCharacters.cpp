// https://leetcode.com/problems/longest-substring-without-repeating-characters/

// the basic idea is, keep a hashmap which stores the characters in string as keys and their positions as values, and keep two pointers which define the max substring. move the right pointer to scan through the string , and meanwhile update the hashmap. If the character is already in the hashmap, then move the left pointer to the right of the same character last found. Note that the two pointers can only move forward.

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// int main() {
//   string s = "pwwkew";
//   size_t best = 0;

//   unordered_set<char> set;
//   deque<char> qu;

//   for (char c : s) {
//     if (qu.empty()) {
//       qu.push_back(c);
//       set.insert(c);
//       best = max(qu.size(), best);
//       continue;
//     }
//     if (set.count(c)) {
//       while (qu.front() != c) {
//         set.erase(qu.front());
//         qu.pop_front();
//       }
//       set.erase(qu.front());
//       qu.pop_front();
//       qu.push_back(c);
//       set.insert(c);
//       best = max(qu.size(), best);
//     } else {
//       qu.push_back(c);
//       set.insert(c);
//       best = max(qu.size(), best);
//     }
//   }

//   cout << best << endl;
// }

int main() {
  string s = "abba";
  int best = 0;

  unordered_map<char, int> map;

  for (int i = 0, j = 0; i < s.length(); i++) {
    if (map.empty()) {
      map.insert({s[i], i});
      best = max(best, i - j + 1);
      continue;
    }
    if (map.count(s[i])) {
      j = max(map[s[i]] + 1,j);  // so that j only moves forward
    }
    map[s[i]] = i;
    best = max(best, i - j + 1);
  }

  cout << best;
}