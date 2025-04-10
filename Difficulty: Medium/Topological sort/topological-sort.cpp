//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<int> vis(V+1, 0);
        vector<int> adj[V];
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
        }
        function<void(int)> dfs = [&](int cur)->void{
            vis[cur] = 1;
            for(auto nbr: adj[cur]){
                if(vis[nbr]) continue;
                dfs(nbr);
            }
            ans.push_back(cur);
        };
        for(int i = 0; i < V; i++) if(!vis[i]) dfs(i);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int V, E;
        cin >> V >> E;

        int x = V;
        vector<vector<int>> adj(V);
        vector<vector<int>> edges;

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            edges.push_back({u, v});
        }

        Solution obj;
        vector<int> res = obj.topoSort(V, edges);
        bool ans = check(x, res, adj);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends