// https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> subarraySum(int arr[], int n, long long s) {
  vector<int> ans;
  int i = 0;
  int j = 0;
  int runningSum = arr[0];

  if (s == arr[0]) {
    ans.push_back(1);
    ans.push_back(1);
    return ans;
  }

  while (1) {
    while (runningSum < s && j + 1 < n) {
      j++;
      runningSum = runningSum + arr[j];
    }

    while (runningSum > s && i <= j) {
      runningSum = runningSum - arr[i];
      i++;
    }

    if (j >= n - 1 || runningSum == s)
      break;
  }

  if (runningSum == s) {
    ans.push_back(i + 1);
    ans.push_back(j + 1);
    return ans;
  }

  ans.push_back(-1);
  return ans;
}

int main() {
  int arr[] = {1, 2, 3, 7, 5};
  int n = 5;
  long long s = 12;
  vector<int> ans;
  ans = subarraySum(arr, n, s);
  for (auto x : ans)
    cout << x << " ";
}