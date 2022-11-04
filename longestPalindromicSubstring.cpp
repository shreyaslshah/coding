// https://leetcode.com/problems/longest-palindromic-substring/

// https://www.youtube.com/watch?v=UflHuQj6MVA&t=13s

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestPalindrome(string s) {
  if (s.length() < 2) {
    return s;
  }

  vector<vector<bool>> table(s.length(), vector<bool>(s.length(), 0));
  int maxLength = 1;
  int startingIdx = 0;

  for (int i = 0; i < s.length(); i++) {
    table[i][i] = 1;
  }
  for (int i = 1; i < s.length(); i++) {
    if (s[i - 1] == s[i]) {
      table[i - 1][i] = 1;
      if (2 > maxLength) {
        maxLength = 2;
        startingIdx = i - 1;
      }
    }
  }

  
  // checking for all substrings of length greater than or equal to 3
  for (int substrlen = 3; substrlen <= s.length(); substrlen++) {
    int i = 0;
    int j = i + substrlen - 1;
    for (; j < s.length(); i++, j++) {
      if (s[i] == s[j] && table[i + 1][j - 1]) {
        table[i][j] = 1;
        if ((j - i + 1) > maxLength) {
          maxLength = j - i + 1;
          startingIdx = i;
        }
      }
    }
  }

  return s.substr(startingIdx, maxLength);
}

int main() {
  string s = "malayalam";
  string ans = longestPalindrome(s);
  cout << ans << endl;
}