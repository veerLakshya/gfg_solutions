//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    

  public:
    int f(vector<int> &dp, vector<int> &coins, int n){
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        dp[n] = 1e9;
        
        for(auto coin: coins){
            if(coin <= n)
            dp[n] = min(dp[n], f(dp, coins, n - coin) + 1);
        }
        return dp[n];
    }
    int minCoins(vector<int> &coins, int sum) {
        vector<int> dp(sum+1, -1);
        
        int ans = f(dp, coins, sum);
        return (ans == 1e9 ? -1 : ans);
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int v, m;
        cin >> v >> m;

        vector<int> coins(m);
        for (int i = 0; i < m; i++)
            cin >> coins[i];

        Solution ob;
        cout << ob.minCoins(coins, v) << "\n";
    }
    return 0;
}

// } Driver Code Ends