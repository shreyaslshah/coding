// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void merge(int arr1[], int arr2[], int n, int m) {
  int i = n-1;
  int j = 0;

  while (arr1[i] > arr2[j] && i >= 0 && j < m) {
    swap(arr1[i], arr2[j]);
    // int temp = arr1[i];
    // arr1[i] = arr2[j];
    // arr2[j] = temp;
    i--;
    j++;
  }

  sort(arr1, arr1 + n);
  sort(arr2, arr2 + m);
}

int main() {
  int arr1[] = {1, 3, 5, 7};
  int n = 4;
  int arr2[] = {0, 2, 6, 8, 9};
  int m = 5;

  merge(arr1, arr2, n, m);

  for (int i = 0; i < n; i++) {
    cout << arr1[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < m; i++) {
    cout << arr2[i] << " ";
  }
  return 0;
}