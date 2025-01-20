//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        
        vector<int> dx = {1, -1, 0, 0, 1, 1, -1, -1}, dy = {0, 0, 1, -1, 1, -1, 1, -1 };

        
        auto h = [&](int i, int j, auto& self) ->void {
            grid[i][j] = '0';
            for(int k = 0; k < 8; k++){
                int x = i + dx[k];
                int y = j + dy[k];
                if(x >= 0 && x < n && y >= 0 && y < m){
                    if(grid[x][y] == '1'){
                        grid[x][y] = '0';
                        self(x, y, self);
                    }
                }
            }
        };
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1') {
                    h(i, j, h);
                    ans++;
                    // for(auto i: grid){
                    //     for(auto j: i) cout << j << " ";
                    //     cout << endl; 
                    // }
                    //     cout << endl; 
                }
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
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends