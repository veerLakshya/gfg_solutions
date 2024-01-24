//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
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
    int firstIndex(int a[], int n) 
    {
        return firstocc(a, n,1);
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

        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        cout << ob.firstIndex(a, n) << endl;
    }
}
// } Driver Code Ends