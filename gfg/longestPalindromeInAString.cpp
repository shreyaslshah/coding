// https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestPalin(string s) {
  if (s.length() <= 1) {
    return s;
  }
  int maxLength = 1;
  int a = 0;
  int b = 0;
  int i, j, length;

  for (int k = 0; k < s.length() - 1; k++) {
    // check for odd length palindromes
    i = k;
    j = k;

    while (i - 1 >= 0 and j + 1 < s.length() and s[i - 1] == s[j + 1]) {
      i--;
      j++;
    }
    length = j - i + 1;
    if (length > maxLength) {
      maxLength = length;
      a = i;
      b = j;
    }

    // check for even length palindromes
    if (s[k] == s[k + 1]) {
      j = k + 1;
      i = k;

      while (i - 1 >= 0 and j + 1 < s.length() and s[i - 1] == s[j + 1]) {
        i--;
        j++;
      }

      length = j - i + 1;
      if (length > maxLength) {
        maxLength = length;
        a = i;
        b = j;
      }
    }
  }

  if (a == b) {
    return s.substr(a, b + 1);
  }

  return s.substr(a, maxLength);
}

int main() {
  string s = "ssyoqcjomwufbdfxudzhiftak";
  string ans = longestPalin(s);
  cout << ans << endl;
}