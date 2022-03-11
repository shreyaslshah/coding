// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int findPlatform(int arr[], int dep[], int n) {
  pair<int, int> pairArr[n];
  for (int i = 0; i < n; i++) {
    pairArr[i].first = arr[i];
    pairArr[i].second = dep[i];
  }
   sort(pairArr, pairArr + n);
  priority_queue<int, vector<int>, greater<int>> q;
  int maxPlatforms = 0;
  q.push(pairArr[0].second);
  maxPlatforms = max(maxPlatforms, (int)q.size());
  for (int i = 1; i < n; i++) {
    if (!q.empty() && q.top() <pairArr[i].first) {
      q.pop();
    }
    q.push(pairArr[i].second);
    maxPlatforms = max(maxPlatforms, (int)q.size());
  }
  return maxPlatforms;
}

int main() {
  int arr[] = {900, 940, 950, 1100, 1500, 1800};
  int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
  int ans = findPlatform(arr, dep, 6);
  cout << ans << endl;
}