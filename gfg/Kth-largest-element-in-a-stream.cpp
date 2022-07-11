// https://practice.geeksforgeeks.org/problems/kth-largest-element-in-a-stream2220/1
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  vector<int> kthLargest(int k, int arr[], int n) {
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i = 0; i < k - 1; i++) {
      ans.push_back(-1);
      heap.push(arr[i]);
    }
    heap.push(arr[k - 1]);
    ans.push_back(heap.top());
    for (int i = k; i < n; i++) {
      if (arr[i] > heap.top()) {
        heap.pop();
        heap.push(arr[i]);
        ans.push_back(heap.top());
      } else {
        ans.push_back(heap.top());
      }
    }
  }
};

// { Driver Code Starts.
int main() {
  int k, n;
  cin >> k >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  Solution ob;
  vector<int> v = ob.kthLargest(k, arr, n);
  for (int i : v)
    cout << i << " ";
  cout << endl;

  return 0;
}  // } Driver Code Ends