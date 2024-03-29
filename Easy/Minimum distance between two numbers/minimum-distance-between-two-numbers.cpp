//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        int p = -1;
        int q = -1;
        int mini = INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(a[i]==x)
            p=i;
            else if(a[i]==y)
            q=i;
            
            if(p!=-1 && q!=-1){
                mini = min(mini,abs(p-q));
            }
        }
        return mini==INT_MAX? -1: mini;
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
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends