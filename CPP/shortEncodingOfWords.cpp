// https://leetcode.com/problems/short-encoding-of-words/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
  vector<string> words = {"me", "time"};

  sort(words.begin(), words.end(), [](const string& first, const string& second) {
    return first.size() > second.size();
  });

  unordered_multimap<char, int> map;
  string ans = "";
  int count = 0;
  bool found;

  for (auto word : words) {
    word = word + "#";
    auto it = map.equal_range(word[0]);
    if (it.first == it.second) {
      for (auto c : word) {
        map.insert({c, ans.length()});
        ans.push_back(c);
      }
    } else {
      found = 0;
      for (auto itr = it.first; itr != it.second; ++itr) {
        if (word == ans.substr(itr->second, word.length())) {
          found = 1;
          break;
        }
      }
      if (!found) {
        for (auto c : word) {
          map.insert({c, ans.length()});
          ans.push_back(c);
        }
      }
    }
  }

  cout << ans.length() << endl;
}


// int main()
// {
//   vector<string> words{"time", "me", "bell"};
//   unordered_set<string> set;
//   int ans = 0;

//   for (string word : words)
//   {
//     set.insert(word);
//   }
//   for (string word : words)
//   {
//     for (int i = 1; i < word.length(); i++)
//     {
//       //need to only check substring which go till the end as if a substring is found, the end of the substring should also have a hash character
//       set.erase(word.substr(i)); 
//     }
//   }
//   for (auto it = set.begin(); it != set.end(); it++)
//   {
//     ans += (*it).length() + 1; // 1 for the hash character
//   }
//   cout << ans;
// }