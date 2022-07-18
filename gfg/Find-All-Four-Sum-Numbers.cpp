// https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1#

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
 public:
  // arr[] : int input array of integers
  // k : the quadruple sum required
  // vector<vector<int>> fourSum(vector<int> &arr, int b) {
  //   sort(arr.begin(), arr.end());
  //   unordered_map<int, int> map;
  //   vector<vector<int>> ans;
  //   unordered_set<long long int> set;

  //   for (int i = 0; i < arr.size(); i++) {
  //     map[arr[i]] = i;
  //   }

  //   for (int i = 0; i < arr.size(); i++) {
  //     for (int j = i + 1; j < arr.size(); j++) {
  //       for (int k = j + 1; k < arr.size(); k++) {
  //         int sum = arr[i] + arr[j] + arr[k];
  //         int rem = b - sum;
  //         if (map.find(rem) != map.end()) {
  //           if (map[rem] > k) {
  //             vector<int> a{arr[i], arr[j], arr[k], rem};
  //             long long int con =
  //                 arr[i] * 1000000000 + arr[j] * 1000000 + arr[k] * 1000 + rem;
  //             if (set.find(con) == set.end()) {
  //               set.insert(con);
  //               ans.push_back(a);
  //             }
  //           }
  //         }
  //       }
  //     }
  //   }

  //   return ans;
  // }

  vector<vector<int>> fourSum(vector<int> &arr, int sum) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for (int i = 0; i < arr.size(); i++) {
      if (i > 0 and arr[i] == arr[i - 1]) continue;
      for (int j = i + 1; j < arr.size(); j++) {
        if (j > i + 1 and arr[j] == arr[j - 1]) continue;
        int left = j + 1;
        int right = arr.size() - 1;
        while (left < right) {
          int s = arr[i] + arr[j] + arr[left] + arr[right];
          if (s > sum) {
            right--;
          } else if (s < sum) {
            left++;
          } else {
            vector<int> a{arr[i], arr[j], arr[left], arr[right]};
            ans.push_back(a);
            int rightElem = arr[right];
            int leftElem = arr[left];
            while (right > left and arr[right] == rightElem) right--;
            while (left < right and arr[left] == leftElem) left++;
          }
        }
      }
    }
    return ans;
  }
};

// { Driver Code Starts.
int main() {
  int n, k, i;
  cin >> n >> k;
  vector<int> a(n);
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  Solution ob;
  vector<vector<int>> ans = ob.fourSum(a, k);
  for (auto &v : ans) {
    for (int &u : v) {
      cout << u << " ";
    }
    cout << "$";
  }
  if (ans.empty()) {
    cout << -1;
  }
  cout << "\n";

  return 0;
}  // } Driver Code Ends