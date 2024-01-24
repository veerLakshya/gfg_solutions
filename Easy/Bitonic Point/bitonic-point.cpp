//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int findMaximum(int arr[], int n) {
	    int x=INT_MIN;
	    for(int i=0;i<n;i++){
	        x=max(x,arr[i]);
	    }
	    return x;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Endshttps://media.geeksforgeeks.org/img-practice/fab-icon-new.gifhttps://media.geeksforgeeks.org/img-practice/fab-icon-new.gif