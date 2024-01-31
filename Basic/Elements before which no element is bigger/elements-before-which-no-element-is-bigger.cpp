//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    long long countElements(long long arr[], long long n) 
    {
        long long count =1;
        long long prev = arr[0];
        for(long long i=1;i<n;i++){
            if(arr[i]>prev) {
                count++;
                // cout<<count<<" ";
            };
            prev = max(arr[i],prev);
        }
        // cout<<"*";
        return count;
    }
};


//{ Driver Code Starts.
int main()
 {
	long long t;
	cin>>t;
	while(t--)
	{
	    long long n;
	    cin>>n;
	    long long a[n];
	    for(long long i=0;i<n;i++)
	        cin>>a[i];
	    Solution ob;
	    cout<<ob.countElements(a, n)<<endl;
	    
	}
	return 0;
}
// } Driver Code Ends