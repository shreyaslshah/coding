// https://practice.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool compare(string a, string b) {
  string temp1 = a + b;
  string temp2 = b + a;
  return (temp1 > temp2 ? 1 : 0);
}

string printLargest(vector<string> &arr) {
  string ans;
  sort(arr.begin(), arr.end(), compare);
  for (auto x : arr) {
    ans += x;
  }
  return ans;
}

int main() {
  vector<string> arr{"15", "153"};
  string ans = printLargest(arr);
  cout << ans << endl;
}