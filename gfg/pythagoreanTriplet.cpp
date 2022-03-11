// https://practice.geeksforgeeks.org/problems/pythagorean-triplet3018/1

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool checkTriplet(int arr[], int n) {
  sort(arr, arr + n);
  if (n >= 3) {
    for (int k = n - 1; k >= 0; k--) {
      int i = 0;
      int j = k - 1;
      while (i < j) {
        int lhs = arr[i] * arr[i] + arr[j] * arr[j];
        int rhs = arr[k] * arr[k];
        if (lhs > rhs) {
          j--;
        } else if (rhs > lhs) {
          i++;
        } else {
          return true;
        }
      }
    }
  }
  return false;
}

int main() {
  int arr[] = {3, 2, 4, 6, 5};
  int n = 5;
  bool ans = checkTriplet(arr, n);
  cout << ans << endl;
}