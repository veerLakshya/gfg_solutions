//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<int> vis(V, 0), temp(V, 0);
        
        vector<vector<int>> adj(V);
        
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
        }
        
        bool cycle = 0;
        
        auto dfs = [&](int cur, auto& self)->void{
            temp[cur] = vis[cur] = 1;
            for(auto nbr: adj[cur]){
                if(!vis[nbr]) self(nbr, self);
                else if(temp[nbr]) cycle = 1;
            }
            temp[cur] = 0;
        };
        
        for(int i = 0; i < V; i++){
            if(!vis[i]) dfs(i, dfs);
            if(cycle) return true;
        }
        
        return cycle;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends