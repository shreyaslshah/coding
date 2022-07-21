//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  // Function to return Breadth First Traversal of given graph.
  vector<int> bfsOfGraph(int v, vector<int> adj[]) {
    queue<int> q;
    vector<bool> marked(v, 0);
    vector<int> ans;

    for (int i = 0; i < v; i++) {
      if (!marked[i]) {
        ans.push_back(i);
        marked[i] = 1;
        q.push(i);

        while (!q.empty()) {
          int a = q.front();
          q.pop();

          for (int j = 0; j < adj[a].size(); j++) {
            if (!marked[adj[a][j]]) {
              q.push(adj[a][j]);
              marked[adj[a][j]] = 1;
              ans.push_back(adj[a][j]);
            }
          }
        }
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
    // 		adj[v].push_back(u);
  }
  // string s1;
  // cin>>s1;
  Solution obj;
  vector<int> ans = obj.bfsOfGraph(V, adj);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;

  return 0;
}
// } Driver Code Ends