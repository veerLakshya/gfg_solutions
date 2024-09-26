//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int mod = 1e9 + 7;
    long long h(int n, vector<long long>& dp){
        if(n == 0) return 1;
        if(dp[n] != -1) return dp[n];
        long long way1 = h(n-1, dp)%mod;
        long long way2 = ((n-1)*h(n-2,dp)%mod)%mod;
        return dp[n] = (way1 + way2) % mod;
    }
    int countFriendsPairings(int n) 
    { 
        vector<long long> dp(n+1, -1);
        return h(n, dp);
    }
};    
 


//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends