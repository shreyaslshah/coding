// https://practice.geeksforgeeks.org/problems/unsorted-array4925/1

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int findElement(int arr[], int n) {
  int index = 0;
  int first = arr[0];
  bool solution = false;
  for (int i = 1; i < n; i++) {
    if (arr[i] < first) {
      solution = false;
    } else if (arr[i] >= first && solution == false) {
      solution = true;
      index = i;
      first = arr[i];
    }
  }

  if (index != 0 && index != n - 1 && solution == true) {
    return first;
  } else
    return -1;
}

int main() {
  int arr[] = {11, 5, 4, 11, 3, 12, 5, 7, 12, 3, 8, 5, 8, 11};
  int n = 14;
  int ans = findElement(arr, n);
  cout << ans << endl;
}