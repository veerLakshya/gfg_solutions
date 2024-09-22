//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minSteps(int N) 
	{ 
	    int dp[N+1];
	    dp[0] = 0;
	    dp[1] = 0;
	    for(int i = 2; i <= N; i++)
	    {
	        dp[i] = 1 + dp[i-1];
	        if(i%3 == 0) dp[i] = min(dp[i], dp[i/3]+1);
	        if(i%2 == 0) dp[i] = min(dp[i], dp[i/2]+1);
	    }
	   // for(int i = 0; i <= N; i++) cout<<i<<" "<<dp[i]<<endl;
	    return dp[N];
	} 
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.minSteps(n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends