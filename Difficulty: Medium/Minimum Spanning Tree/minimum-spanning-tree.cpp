//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// class UnionFind {
// private:
//     vector<int> p, rank;
// public:
//     UnionFind(int n) {
//         rank.assign(n, 0);
//         p.assign(n, 0);
//         iota(p.begin(), p.end(), 0);
//     }

//     int findSet(int i) {
//         return (p[i] == i) ? i : (p[i] = findSet(p[i]));
//     }

//     bool isSameSet(int i, int j) {
//         return findSet(i) == findSet(j);
//     }

//     void unionSet(int i, int j) {
//         if (!isSameSet(i, j)) {
//             int x = findSet(i), y = findSet(j);
//             if (rank[x] > rank[y]) p[y] = x;
//             else {
//                 p[x] = y;
//                 if (rank[x] == rank[y]) rank[y]++;
//             }
//         }
//     }
// };

class UnionFind {
public:
    vector<int> parent, rank;
    
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    
    int find(int x) {
        if (parent[x] != x) 
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return false; // Already in the same set
        
        // Union by rank
        if (rank[rootX] > rank[rootY]) 
            parent[rootY] = rootX;
        else if (rank[rootX] < rank[rootY]) 
            parent[rootX] = rootY;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
};
class Solution {
    
  public:
    

int spanningTree(int V, vector<vector<int>> adj[]) {
    vector<vector<int>> edges;
    
    // Convert adjacency list to edge list
    for (int u = 0; u < V; u++) {
        for (auto &it : adj[u]) {
            int v = it[0], wt = it[1];
            if (u < v) // To avoid duplicate edges in an undirected graph
                edges.push_back({wt, u, v});
        }
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end());

    UnionFind dsu(V);
    int ans = 0, edgeCount = 0;
    
    for (auto &edge : edges) {
        int wt = edge[0], u = edge[1], v = edge[2];
        if (dsu.unite(u, v)) { // If the edge connects two different components
            ans += wt;
            edgeCount++;
            if (edgeCount == V - 1) break; // MST has exactly (V-1) edges
        }
    }
    
    return ans;
}
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends