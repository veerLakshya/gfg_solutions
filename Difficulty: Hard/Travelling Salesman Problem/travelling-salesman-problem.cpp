//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    const int INF = INT_MAX;
    int total_cost(vector<vector<int>>& cost, int start, int mask, vector<vector<int>> &dp){
        
        int n = cost.size();
        if(mask == (1<<n) - 1)
          return cost[start][0];
          
        if(dp[start][mask] != -1)
          return dp[start][mask];
          
        int ans = INF;
        
        for(int nextCity = 0; nextCity<n; nextCity++){
            if((mask & (1<<nextCity)) == 0){
                int newMask = mask | (1 << nextCity);
                ans = min(ans, cost[start][nextCity] + total_cost(cost, nextCity, newMask, dp));
            }
        }
        
        return dp[start][mask] = ans;
    }
    int tsp(vector<vector<int>> &cost){

        int n = cost.size();
        vector<vector<int>> dp(n, vector<int>(1<<n, -1));
        return total_cost(cost, 0, 1, dp);
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