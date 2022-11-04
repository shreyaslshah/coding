// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  void dfs(int v, vector<int> adj[], vector<bool> &marked, bool *ans, int parent) {
    marked[v] = 1;
    for (int i = 0; i < adj[v].size(); i++) {
      if (!marked[adj[v][i]]) {
        dfs(adj[v][i], adj, marked, ans, v);
      } else {
        if (parent != adj[v][i] or v==adj[v][i]) {
          *ans = true;
        }
      }
    }
  }
  // Function to detect cycle in an undirected graph.
  bool isCycle(int v, vector<int> adj[]) {
    vector<bool> marked(v, 0);
    bool ans = false;
    for (int i = 0; i < v; i++) {
      if (!marked[i] and !ans) {
        dfs(i, adj, marked, &ans, -1);
      }
    }
    return ans;
  }
};

// { Driver Code Starts.
int main() {
  int V, E;
  cin >> V >> E;
  vector<int> adj[V];
  for (int i = 0; i < E; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  Solution obj;
  bool ans = obj.isCycle(V, adj);
  if (ans)
    cout << "1\n";
  else
    cout << "0\n";

  return 0;
}  // } Driver Code Ends