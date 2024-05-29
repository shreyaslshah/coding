// https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  // arr: input array
  // n: size of array
  // Function to find the sum of contiguous subarray with maximum sum.
  long long maxSubarraySum(int arr[], int n) {
    long long best = INT_MIN;
    long long localBest = INT_MIN;

    for (int i = 0; i < n; i++) {
      localBest = max((long long)arr[i], localBest + arr[i]);
      best = max(best, localBest);
    }

    return best;
  }
};

//{ Driver Code Starts.

int main() {
  int n;
  cin >> n;  // input size of array

  int a[n];

  for (int i = 0; i < n; i++)
    cin >> a[i];  // inputting elements of array

  Solution ob;

  cout << ob.maxSubarraySum(a, n) << endl;
}

// } Driver Code Ends