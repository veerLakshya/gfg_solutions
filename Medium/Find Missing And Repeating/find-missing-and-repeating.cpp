//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        int repeat=arr[0];
        int miss;
        sort(arr.begin(),arr.end());
        if(arr[0]!=1)
        miss = 1;
        else miss = n;
        for(int i=1;i<n;i++)
        {
            if(arr[i]==arr[i-1])repeat=arr[i];
            if(arr[i]-arr[i-1]==2)miss =arr[i]-1;
        }
        return {repeat,miss};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends