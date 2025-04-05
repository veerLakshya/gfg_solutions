//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int dp[1001][1001];
    int h(int i, int cap, vector<int>& wt, vector<int>& c){
        if(cap <= 0 || i == c.size()) return 0;
        if(dp[i][cap] != -1) return dp[i][cap];
        int take = 0;
        if(wt[i] <= cap) take = c[i] + h(i, cap - wt[i], wt, c);
        int nottake = h(i+1, cap, wt, c);
        return dp[i][cap] = max(take, nottake);
        
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        memset(dp, -1, sizeof dp);
        return h(0, capacity, wt, val);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int W;
        cin >> W;
        cin.ignore();
        string str;
        getline(cin, str);
        stringstream ss(str);
        vector<int> val;
        int num;
        while (ss >> num) {
            val.push_back(num);
        }
        string str2;
        getline(cin, str2);
        stringstream ss2(str2);
        vector<int> wt;
        int num2;
        while (ss2 >> num2) {
            wt.push_back(num2);
        }
        Solution ob;
        cout << ob.knapSack(val, wt, W) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends