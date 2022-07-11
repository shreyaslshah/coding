// https://practice.geeksforgeeks.org/problems/special-keyboard3018/1
// https://www.youtube.com/watch?v=c_y7H7qZJRU

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  long long int optimalKeys(int n) {
    if (n < 7)
      return n;

    vector<int> v;
    v.push_back(-1);  // for 1 indexing

    for (int i = 1; i <= 6; i++) {
      v.push_back(i);
    }

    for (int i = 7; i <= n; i++) {
      int multiple = 2;
      int largest = 0;
      for (int j = i - 3; j >= 1; j--) {
        largest = max(largest, v[j] * multiple);
        multiple++;
      }
      v[i] = largest;
    }
    return v[n];
  }
};

// { Driver Code Starts.

int main() {
  int N;
  cin >> N;

  Solution ob;
  cout << ob.optimalKeys(N) << "\n";

  return 0;
}  // } Driver Code Ends