//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int ans = 0;
    int dp[1001][1001];
    
    int helper(vector<int>& a, int ind, int left){
        if(ind < 0) return left == 0 ? 1 : 0;
        if(dp[ind][left] != - 1) return dp[ind][left];
        int take = 0;
        if(left - a[ind] >= 0) take = helper(a, ind - 1, left - a[ind]);
        int nottake = helper(a, ind - 1, left);
        return dp[ind][left] = take + nottake;
    }
    int perfectSum(vector<int>& arr, int target) {
        memset(dp, -1, sizeof(dp));
        return helper(arr, arr.size() - 1, target);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends