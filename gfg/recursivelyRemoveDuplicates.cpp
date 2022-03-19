// https://practice.geeksforgeeks.org/problems/recursively-remove-all-adjacent-duplicates0744/1

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string recursion(string s, int i, int j, string* ans) {
  if (j >= s.size()) {
    return *ans;
  }
  if (s[i] == s[j]) {
    return recursion(s, i, j + 1, ans);
  }
  if (s[i] != s[j] && j - i != 1) {
    *ans += s[j];
    return recursion(s, j, j + 1, ans);
  }
  if (j - i == 1) {
    if (i == 0) {
      *ans += s[i];
    } else {
      *ans += s[j];
    }
    return recursion(s, j, j + 1, ans);
  }
  return *ans;
}

string remove(string s) {
}

int main() {
}