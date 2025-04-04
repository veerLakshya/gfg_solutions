//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int dp[2001][1001];
    bool h(int ind,int tar, vector<int>& a){
        if(tar == 0) return 1;
        if(ind < 0 || tar < 0) return 0;
        if(dp[ind][tar] != -1) return dp[ind][tar];
        
        bool take = h(ind - 1, tar - a[ind], a);
        bool nottake = h(ind - 1, tar, a);
        return dp[ind][tar] = (take ||nottake);
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        memset(dp, -1, sizeof dp);
        return h(arr.size() - 1, sum, arr);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends