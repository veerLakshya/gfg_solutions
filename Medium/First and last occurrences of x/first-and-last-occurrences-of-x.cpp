//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int firstocc(int arr[], int n, int x)
    {
        int low =0;
        int high= n-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(arr[mid]>x) high = mid-1;
            else if(arr[mid]<x) low = mid+1;
            else
            {
                if(mid==0|| arr[mid-1]!= arr[mid])
                return mid;
                else high = mid-1;
            }
        }
        return -1;
    }
    int lastocc(int arr[], int n, int x)
    {
        int low=0;int high=n-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(arr[mid]>x) high = mid-1;
            else if(arr[mid]<x) low = mid+1;
            else
            {
                if(mid==n-1|| arr[mid]!= arr[mid+1])
                return mid;
                else low = mid+1;
            }
        }
        return -1;
    }
    vector<int> find(int arr[], int n , int x )
    {
        return{firstocc(arr, n, x), lastocc(arr, n, x)};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends