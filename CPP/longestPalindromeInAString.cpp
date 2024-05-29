// https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1
// https://www.youtube.com/watch?v=UflHuQj6MVA

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// my method
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

// using dp
// string longestPalin(string s) {
//   if (s.length() < 2) {
//     return s;
//   }

//   vector<vector<bool>> table(s.length(), vector<bool>(s.length(), 0));
//   int maxLength = 1;
//   int startingIdx = 0;

//   for (int i = 0; i < s.length(); i++) {
//     table[i][i] = 1;
//   }
//   for (int i = 1; i < s.length(); i++) {
//     if (s[i - 1] == s[i]) {
//       table[i - 1][i] = 1;
//       if (2 > maxLength) {
//         maxLength = 2;
//         startingIdx = i - 1;
//       }
//     }
//   }

//   // checking for all substrings of length greater than or equal to 3
//   for (int substrlen = 3; substrlen <= s.length(); substrlen++) {
//     int i = 0;
//     int j = i + substrlen - 1;
//     for (; j < s.length(); i++, j++) {
//       if (s[i] == s[j] && table[i + 1][j - 1]) {
//         table[i][j] = 1;
//         if ((j - i + 1) > maxLength) {
//           maxLength = j - i + 1;
//           startingIdx = i;
//         }
//       }
//     }
//   }

//   return s.substr(startingIdx, maxLength);
// }

int main() {
  string s = "ssyoqcjomwufbdfxudzhiftak";
  string ans = longestPalin(s);
  cout << ans << endl;
}