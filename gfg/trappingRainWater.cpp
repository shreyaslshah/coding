// https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long trappingWater(int arr[], int n) {
  long long ans = 0;
  int maximum = INT_MIN;
  int left[n], right[n];
  for (int i = 0; i < n; i++) {
    maximum = max(maximum, arr[i]);
    left[i] = maximum;
  }
  maximum = INT_MIN;
  for (int i = n - 1; i >= 0; i--) {
    maximum = max(maximum, arr[i]);
    right[i] = maximum;
  }
  for (int i = 0; i < n; i++) {
    ans += min(left[i], right[i]) - arr[i];
  }

  return ans;
}

int main() {
  int arr[] = {8, 8, 2, 4, 5, 5, 1};
  int n = 6;
  long long ans = trappingWater(arr, n);
  cout << ans << endl;
}