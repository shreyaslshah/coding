// https://practice.geeksforgeeks.org/problems/swapping-pairs-make-sum-equal4142/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  int findSwapValues(int a[], int n, int b[], int m) {
    unordered_set<int> setb;
    int suma = 0;
    int sumb = 0;
    for (int i = 0; i < n; i++) {
      suma += a[i];
    }
    for (int i = 0; i < m; i++) {
      setb.insert(b[i]);
      sumb += b[i];
    }
    int diff = abs(suma - sumb);
    if (diff == 0) {
      return 1;
    }
    if (diff % 2 == 1) {
      return -1;
    }
    diff /= 2;
    for (int i = 0; i < n; i++) {
      int toFind;
      if (suma > sumb) {
        toFind = a[i] - diff;
      } else {
        toFind = diff + a[i];
      }
      if (setb.find(toFind) != setb.end()) {
        return 1;
      }
    }
    return -1;
  }
};

//{ Driver Code Starts.

int main() {
  int n, m;
  cin >> n >> m;
  int a[n];
  int b[m];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++)
    cin >> b[i];

  Solution ob;
  cout << ob.findSwapValues(a, n, b, m);
  cout << "\n";

  return 0;
}

// } Driver Code Ends