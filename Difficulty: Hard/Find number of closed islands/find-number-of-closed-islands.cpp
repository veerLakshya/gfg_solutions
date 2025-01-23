//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    void print(vector<vector<int>>& a){
        int n = a.size(), m = a[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)cout << a[i][j] <<" ";
            cout << endl;
        }
    }
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        vector<vector<int>> vis = matrix;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                vis[i][j] = 0;
            }
        }
        
        vector<int> dx = {1,-1,0,0}, dy = {0,0,-1,1};
        auto dfs = [&](int i, int j, int val, auto self)->void{
            vis[i][j] = 1;
            for(int k = 0; k < 4; k++){
                int x = i + dx[k];
                int y = j + dy[k];
                if(x >= 0 && x < N && y>=0 && y < M && !vis[x][y] && matrix[x][y] == val){
                    self(x, y, val, self);
                }
            }
        };
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(!vis[i][j]  && (i == 0|| j == 0 || i == N-1 || j == M-1)) dfs(i, j, matrix[i][j], dfs);
            }
        }
        // print(vis);
        int ans = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(!vis[i][j]  && matrix[i][j]){
                    // cout << i <<" " << j<< endl;
                    ans++;
                    dfs(i, j, matrix[i][j], dfs);
                } 
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    
cout << "~" << "\n";
}
	
	return 0;
	
}


// } Driver Code Ends