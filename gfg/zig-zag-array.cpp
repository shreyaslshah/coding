// https://practice.geeksforgeeks.org/problems/convert-array-into-zig-zag-fashion1638/1

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void zigZag(int arr[], int n) {
  bool todo = 0;
  for (int i = 1; i < n; i++) {
    if (todo == 0) {
      if (arr[i - 1] > arr[i])
        swap(arr[i - 1], arr[i]);
    } else {
      if (arr[i - 1] < arr[i])
        swap(arr[i - 1], arr[i]);
    }
    todo = !todo;
  }
}

int main() {
  int arr[] = {4, 3, 7, 8, 6, 2, 1};
  int n = 7;
  zigZag(arr, n);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << endl;
  }
}