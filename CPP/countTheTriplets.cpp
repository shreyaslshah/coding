// https://practice.geeksforgeeks.org/problems/count-the-triplets4615/1

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int countTriplet(int arr[], int n) {
  sort(arr, arr + n);

  int j, k;

  int ans = 0;

  for (int i = n - 1; i > 1; i--) {
    j = 0;
    k = i - 1;

    while (j < k && k < i) {
      int sum = arr[j] + arr[k];
      if (sum < arr[i]) {
        j++;
      } else if (sum > arr[i]) {
        k--;
      } else {
        ans++;
        j++;
        k--;
      }
    }
  }

  return ans;
}

int main() {
  int arr[] = {3, 6, 8, 11, 14, 16};
  int n = 6;
  int ans = countTriplet(arr, n);
  cout << ans << endl;
}