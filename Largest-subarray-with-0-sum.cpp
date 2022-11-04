// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1#
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
 public:
  int maxLen(vector<int>& a, int n) {
    unordered_map<int, pair<int, int>> map;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum = sum + a[i];
      if (map.find(sum) != map.end()) {
        map[sum].second = i;
      } else {
        map[sum] = {i, -1};
      }
    }
    int ans = 0;
    for (auto it = map.begin(); it != map.end(); it++) {
      if (it->second.second != -1) {
        ans = max(ans, (it->second.second - it->second.first));
      }
      if (it->first == 0) {
        ans = max(ans, max(it->second.first + 1, it->second.second + 1));
      }
    }
    return ans;
  }
};

// int maxLen(int arr[], int n) {
//   // Map to store the previous sums
//   unordered_map<int, int> presum;

//   int sum = 0;      // Initialize the sum of elements
//   int max_len = 0;  // Initialize result

//   // Traverse through the given array
//   for (int i = 0; i < n; i++) {
//     // Add current element to sum
//     sum += arr[i];

//     if (arr[i] == 0 && max_len == 0)
//       max_len = 1;
//     if (sum == 0)
//       max_len = i + 1;

//     // Look for this sum in Hash table
//     if (presum.find(sum) != presum.end()) {
//       // If this sum is seen before, then update max_len
//       max_len = max(max_len, i - presum[sum]);
//     } else {
//       // Else insert this sum with index in hash table
//       presum[sum] = i;
//     }
//   }

//   return max_len;
// }

// { Driver Code Starts.

int main() {
  int m;
  cin >> m;
  vector<int> array1(m);
  for (int i = 0; i < m; ++i) {
    cin >> array1[i];
  }
  Solution ob;
  cout << ob.maxLen(array1, m) << endl;

  return 0;
}

// } Driver Code Ends