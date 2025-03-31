//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int n, m;
    int h(int i, int j, string& s, string& t, vector<vector<int>>& dp){
        if(i == n || j == m) return  0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]) dp[i][j] = 1 + h(i + 1, j + 1, s, t, dp);
        else dp[i][j] = 0;
        h(i+1, j, s, t, dp);
        h(i, j + 1, s, t, dp);
        return dp[i][j];
    }
    int longestCommonSubstr(string& s1, string& s2) {
        n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        h(0,0,s1,s2,dp);
        int ans = 0;
        for(auto i: dp){
            for(auto j: i) ans = max(ans, j);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends