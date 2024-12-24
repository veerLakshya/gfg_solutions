//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int helper(vector<vector<int>>& cost, int cur, int mask, vector<vector<int>>& dp){
        int n = cost.size();
        if(mask == (1 << n) - 1) return cost[cur][0];
        if(dp[cur][mask] != -1) return dp[cur][mask];
        
        int ans = INT_MAX;
        for(int j = 0; j < n; j++){
            if((mask & (1 << j)) == 0){
                int newMask = mask | (1 << j);
                ans = min(ans, cost[cur][j] + helper(cost, j, newMask, dp));
            }
        }

        return dp[cur][mask] = ans;
    }
    int tsp(vector<vector<int>>& cost) {
        int n = cost.size();
        vector<vector<int>> dp(n, vector<int> (1<<n, -1));
        return helper(cost, 0, 1, dp);
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> cost(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> cost[i][j];
        Solution obj;
        int ans = obj.tsp(cost);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends