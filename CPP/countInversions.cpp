// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void merge(long long arr[], long long l, long long mid, long long r, long long int *inversions) {
  long long int n1 = mid - l + 1;
  long long int n2 = r - mid;

  long long int arr1[n1], arr2[n2];

  for (int i = 0; i < n1; i++)
    arr1[i] = arr[l + i];

  for (int i = 0; i < n2; i++)
    arr2[i] = arr[mid + 1 + i];

  long long int i = 0, j = 0;
  long long int k = l;

  while (i < n1 && j < n2) {
    if (arr1[i] <= arr2[j]) {
      arr[k] = arr1[i];
      i++;
    } else {
      arr[k] = arr2[j];
      j++;
      *inversions = *inversions + (n1 - i);
    }
    k++;
  }

  while (i < n1) {
    arr[k] = arr1[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = arr2[j];
    j++;
    k++;
  }
}

void mergeSort(long long arr[], long long l, long long r, long long int *inversions) {
  if (l < r) {
    long long mid = (l + r) / 2;
    mergeSort(arr, l, mid, inversions);
    mergeSort(arr, mid + 1, r, inversions);
    merge(arr, l, mid, r, inversions);
  }
}

long long int inversionCount(long long arr[], long long n) {
  long long int inversions = 0;
  mergeSort(arr, 0, n - 1, &inversions);
  return inversions;
}

int main() {
  long long arr[] = {1, 20, 6, 4, 5};
  int n = 5;
  long long int ans = inversionCount(arr, n);

  cout << ans << endl;
}