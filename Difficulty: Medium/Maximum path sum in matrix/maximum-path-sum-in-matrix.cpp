//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maximumPath(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                int maxi = mat[i-1][j];
                if(j-1 >= 0) maxi = max(maxi, mat[i-1][j-1]);
                if(j+1 < m) maxi = max(maxi, mat[i-1][j+1]);
                mat[i][j] += maxi;
            }
        }
        return *max_element(mat[n-1].begin(), mat[n-1].end());
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        cout << ob.maximumPath(mat) << "\n";
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends