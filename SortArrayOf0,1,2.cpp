// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void swap(int a[], int i, int j) {
  int temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}

void sort012(int a[], int n) {
  int low = 0;
  int high = n - 1;
  int i = 0;

  while (i <= high) {
    if (a[i] == 0) {
      swap(a, i, low);
      low++;
      i++;
    } else if (a[i] == 1) {
      i++;
    } else {
      swap(a, i, high);
      high--;
    }
  }
}

int main() {
  int a[] = {0, 2, 1, 2, 0};
  int n = 5;
  sort012(a, n);
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
}