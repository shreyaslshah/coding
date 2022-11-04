// https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m) {
  sort(a.begin(), a.end());
  long long i = 0;
  long long j = m - 1;
  long long diff = LONG_MAX;
  while (j < n) {
    diff = min(diff, (a[j] - a[i]));
    j++;
    i++;
  }
  return diff;
}

int main() {
  vector<long long> a = {3, 4, 1, 9, 56, 7, 9, 12};
  long long n = 8;
  long long m = 5;
  long long ans = findMinDiff(a, n, m);
  cout << ans << endl;
}