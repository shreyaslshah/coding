// https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
// User function template for C++

class Solution {
 public:
  // Function to count subarrays with sum equal to 0.
  ll findSubarray(vector<ll> arr, int n) {
    unordered_map<ll, ll> map;
    ll ans = 0;
    ll sum = 0;
    map[sum]++;
    for (ll i = 0; i < arr.size(); i++) {
      sum += arr[i];
      map[sum]++;
    }
    sum = 0;
    map[sum]--;
    ans += map[sum];
    if (map[sum] == 0) {
      map.erase(sum);
    }
    for (ll i = 0; i < arr.size(); i++) {
      sum += arr[i];
      map[sum]--;
      ans += map[sum];
      if (map[sum] == 0) {
        map.erase(sum);
      }
    }
    return ans;
  }

  // asu code
  // ll findSubarray(vector<ll> arr, int n) {
  //   unordered_map<int, int> map;
  //   map[0]++;
  //   ll prefixSum = 0;
  //   ll ans = 0;
  //   for (int i = 0; i < n; i++) {
  //     prefixSum += arr[i];
  //     if (map.find(prefixSum) != map.end()) {
  //       ans += map[prefixSum];
  //     }
  //     map[prefixSum]++;
  //   }
  //   return ans;
  // }
};

//{ Driver Code Starts.
int main() {
  int n;
  cin >> n;  // input size of array

  vector<ll> arr(n, 0);

  for (int i = 0; i < n; i++)
    cin >> arr[i];  // input array elements
  Solution ob;
  cout << ob.findSubarray(arr, n) << "\n";

  return 0;
}
// } Driver Code Ends