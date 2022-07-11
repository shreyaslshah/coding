// https://practice.geeksforgeeks.org/problems/number-of-paths0926/1#
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

void paths(int m, int n, long long *c, int currM, int currN) {
  if (currM + 1 <= m) {
    paths(m, n, c, currM + 1, currN);
  }
  if (currN + 1 <= n) {
    paths(m, n, c, currM, currN + 1);
  }
  if (currM == m and currN == n) {
    *c = *c + 1;
  }
}

long long numberOfPaths(int m, int n) {
  long long c = 0;

  paths(m, n, &c, 1, 1);

  return c;
}

// { Driver Code Starts.

int main() {
  int n, m;
  cin >> m >> n;
  cout << numberOfPaths(m, n) << endl;

  return 0;
}  // } Driver Code Ends