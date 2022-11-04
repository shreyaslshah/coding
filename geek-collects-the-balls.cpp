// https://practice.geeksforgeeks.org/problems/geek-collects-the-balls5515/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  int maxBalls(int n, int m, vector<int> a, vector<int> b) {
    int i = 0, j = 0, s1 = 0, s2 = 0, c1, c2;
    while (i < n && j < m) {
      if (a[i] < b[j]) {
        s1 += a[i++];
      } else if (a[i] > b[j]) {
        s2 += b[j++];
      } else {
        int x = a[i], oldS1 = s1, oldS2 = s2;
        for (c1 = 0; i < n && a[i] == x; ++c1, ++i)
          ;

        for (c2 = 0; j < m && b[j] == x; ++c2, ++j)
          ;

        s1 = oldS1 + ((c1 > 1 && c2 > 1) ? (c1 + c2 - 2) * x : c1 * x);
        s1 = max(s1, oldS2 + (c1 + c2 - 1) * x);

        s2 = oldS2 + ((c1 > 1 && c2 > 1) ? (c1 + c2 - 2) * x : c2 * x);
        s2 = max(s2, oldS1 + (c1 + c2 - 1) * x);
      }
    }
    for (; i < n; ++i) {
      s1 += a[i];
    }
    for (; j < m; ++j) {
      s2 += b[j];
    }
    return max(s1, s2);
  }
};

//{ Driver Code Starts.

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> a(N), b(M);
  for (int i = 0; i < N; i++)
    cin >> a[i];
  for (int i = 0; i < M; i++)
    cin >> b[i];

  Solution ob;
  cout << ob.maxBalls(N, M, a, b) << "\n";

  return 0;
}
// } Driver Code Ends