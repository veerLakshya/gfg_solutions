//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template for C++ solution

class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n)
    {
        vector<long long> v;
        stack <long long> st;
        st.push(arr[n-1]);
        v.push_back(-1);
        for(long long i=n-2; i>=0 ; i--)
        {
            while(st.empty()!=true && st.top()<=arr[i])
            st.pop();
            long long ans = st.empty()? -1: st.top();
            v.push_back(ans);
            st.push(arr[i]);
        }
        reverse(v.begin(),v.end());
        return v;
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
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution ob;
        
        vector <long long> res = ob.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends