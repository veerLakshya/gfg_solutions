//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    set<string> a;
    string x, y;
    unordered_map<string,bool> mp;
    void helper(int i, int j, string cur, vector<vector<int>>& dp){
        if(i == 0|| j == 0){
            reverse(cur.begin(), cur.end());
            a.insert(cur);
            return;
        }
        string now = to_string(i) + '_' + to_string(j) + '_' + cur;
        if(mp.find(now) != mp.end()) return;
        mp[now] = 1;
        if(x[i-1] == y[j-1]) helper(i - 1, j - 1, cur + x[i-1], dp);
        else{
            if(dp[i][j] == dp[i-1][j]) helper(i - 1, j, cur, dp);
            if(dp[i][j] == dp[i][j-1]) helper(i, j - 1, cur, dp);
        }
    }
    vector<string> all_longest_common_subsequences(string s, string t) {
        int n = s.size(), m = t.size();
        x = s, y = t;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                // cout << dp[i][j] << " ";
            }
            // cout << endl;
        }
        helper(n , m, "", dp);
        vector<string> ans;
        for(auto i: a) ans.push_back(i);
        
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        vector<string> ans = ob.all_longest_common_subsequences(s, t);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends