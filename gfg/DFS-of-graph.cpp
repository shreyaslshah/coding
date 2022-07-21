//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  void dfs(int v, vector<int> &ans, vector<int> adj[], vector<bool> &marked) {
    ans.push_back(v);
    marked[v] = 1;
    for (int i = 0; i < adj[v].size(); i++) {
      if (!marked[adj[v][i]]) {
        dfs(adj[v][i], ans, adj, marked);
      }
    }
  }
  // Function to return a list containing the DFS traversal of the graph.
  vector<int> dfsOfGraph(int v, vector<int> adj[]) {
    vector<int> ans;
    vector<bool> marked(v, 0);    
    for (int i = 0; i < v; i++) {
      if (!marked[i]) {
        dfs(i, ans, adj, marked);
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.
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
  // string s1;
  // cin>>s1;
  Solution obj;
  vector<int> ans = obj.dfsOfGraph(V, adj);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;

  return 0;
}
// } Driver Code Ends