// https://practice.geeksforgeeks.org/problems/equilibrium-point-1587115620/1

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int equilibriumPoint(long long a[], int n) {
  if (n == 1)
    return 1;

  int i = 0;
  int j = n - 1;
  long long first = 0;
  long long second = 0;

  while (i <= j) {
    if (first < second) {
      first += a[i];
      i++;
    } else if (second < first) {
      second += a[j];
      j--;
    } else {
      if (i==j) {
        return (i + 1);
      } else {
        first += a[i];
        i++;
        second += a[j];
        j--;
      }
    }
  }

  return -1;
}

int main() {
  long long a[] = {1, 3, 5, 2, 2};
  int n = 5;
  int ans = equilibriumPoint(a, n);
  cout << ans << endl;
}