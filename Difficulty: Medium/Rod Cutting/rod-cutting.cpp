//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int helper(int n, int price[], vector<int> &dp, int size){
        if(n == 0) return 0;
        if(dp[n]!=-1) return dp[n];
        int res = 0;
        for(int i = 0; i < n; i++){
            int cut = i + 1;
            res = max(res, price[i] + helper(n-cut, price, dp, size));
        }
        return dp[n] = res;
        
    }
    int cutRod(int price[], int n) {
        vector<int> dp(n+1,-1);
        helper(n, price, dp, n);
        return dp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends