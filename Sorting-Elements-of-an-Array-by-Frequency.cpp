//https://practice.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency/0
#include <bits/stdc++.h>
using namespace std;

bool sortbyCond(const pair<int, int>& a,
                const pair<int, int>& b) {
  if (a.first != b.first)
    return (a.first > b.first);
  else
    return (a.second < b.second);
}

void solve(int n, vector<int> arr) {
  unordered_map<int, int> um;
  for (int i = 0; i < n; i++) {
    um[arr[i]]++;
  }
  vector<pair<int, int>> vec;
  for (auto it = um.begin(); it != um.end(); it++) {
    vec.push_back({it->second, it->first});
  }
  sort(vec.begin(), vec.end(), sortbyCond);
  for (int i = 0; i < vec.size(); i++) {
    int s = vec[i].first;
    while (s--) {
      cout << vec[i].second << " ";
    }
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      arr[i] = a;
    }
    solve(n, arr);
    cout << endl;
  }
  return 0;
}