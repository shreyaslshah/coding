// https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  // arr[] : the input array
  // N : size of the array arr[]

  // Function to return length of longest subsequence of consecutive integers.
  int findLongestConseqSubseq(int arr[], int n) {
    unordered_set<int> set;
    for (int i = 0; i < n; i++) {
      set.insert(arr[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int count = 0;
      if (set.find(arr[i]) != set.end()) {
        set.erase(arr[i]);
        count++;
        int next = arr[i]+1;
        while (set.find(next) != set.end()) {
          count++;
          set.erase(next);
          next++;
        }
        int prev = arr[i]-1;
        while (set.find(prev) != set.end()) {
          count++;
          set.erase(prev);
          prev--;
        }
        ans = max(ans, count);
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.

// Driver program
int main() {
  int n, i, a[100001];

  cin >> n;
  for (i = 0; i < n; i++)
    cin >> a[i];
  Solution obj;
  cout << obj.findLongestConseqSubseq(a, n) << endl;

  return 0;
}
// } Driver Code Ends