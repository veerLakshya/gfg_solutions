//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        vector<int> pre(n);
        pre[0]=A[0];
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1]+A[i];
        }
        int ans=0;
        unordered_map <int ,int> mp;
        
        for(int i=0;i<n;i++){
            if(pre[i]==0){
                ans=max(i+1,ans);
                continue;
            }
            if(mp.find(pre[i])!=mp.end()){
                ans = max(ans, i-mp[pre[i]]);
            mp[pre[i]]=min(i,mp[pre[i]]);
            }
            if(mp.find(pre[i])==mp.end())
            mp[pre[i]]= i;
        }
        // for(int i=0;i<n;i++)
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends