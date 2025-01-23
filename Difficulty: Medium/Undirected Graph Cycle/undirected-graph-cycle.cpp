//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n, 0);
    
        auto bfs = [&](int start) -> bool {
            queue<pair<int, int>> q;
            q.push({start, -1});
            vis[start] = 1; 
    
            while (!q.empty()) {
                pair<int,int> a = q.front();
                int cur = a.first;
                int parent = a.second;
                q.pop();
    
                for (auto nbr : adj[cur]) {
                    if (!vis[nbr]) {
                        vis[nbr] = 1;
                        q.push({nbr, cur});
                    } else if (nbr != parent) return true;
                }
            }
            return false;
        };
    
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (bfs(i)) return true;
            }
        }
        return false; 
    }

};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends