//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	void print(vector<vector<int>>& a){
        int n = a.size(), m = a[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)cout << a[i][j] <<" ";
            cout << endl;
        }
    }
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
        queue<pair<int,int>> q;
        vector<int> vis(1e4 + 1, 0);
        q.push({0,0});
        while(q.size()){
            pair<int,int> a = q.front();
            if(a.first == X) return a.second;
            q.pop();
            for(auto nbr: adj[a.first]){
                if(!vis[nbr]){
                    vis[nbr] = 1;
                    q.push({nbr, a.second + 1});
                }
            }
        }
        return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}


// } Driver Code Ends