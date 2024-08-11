//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int N;
    int helper(int ind, vector<int>& a, vector<int>& dp){
        if(ind==0) return dp[0] = 0;
        if(ind == 1) return dp[1] = abs(a[1]-a[0]);
        if(dp[ind]!= -1)  return dp[ind];
        return dp[ind] = min(helper(ind-1,a,dp)+abs(a[ind]-a[ind-1]), helper(ind-2,a,dp)+abs(a[ind]-a[ind-2]));
    }
    int minimumEnergy(vector<int>& height, int n) {
       N=n;
       vector<int> dp(n, -1);
       return helper(n-1,height , dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends