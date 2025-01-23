//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>>& mat) {
        int ans = 0, m = mat.size(), n = mat[0].size();
        vector<int> dx = {1,-1,0, 0}, dy = {0,0,1,-1};
        vector<vector<int>> vis = mat;
        for(auto &i: vis) for(auto &j: i) j = 0;
        queue<pair<pair<int,int>,int>> q; // current orange(x,y) and its min distance from any rotten orange 
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        while(q.size()){
            pair<pair<int,int>,int> a = q.front();
            ans = max(ans, a.second);
            q.pop();
            for(int k = 0; k < 4; k++){
                int x = a.first.first + dx[k];
                int y = a.first.second + dy[k];
                if(x >= 0 && y >= 0 && x < m && y < n && mat[x][y] == 1 && !vis[x][y]){
                    vis[x][y] = 1;
                    q.push({{x,y}, a.second + 1});
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1 && !vis[i][j])return -1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends