//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    long long subarraySum(vector<int>& arr) {
        long long ans = 0, n = arr.size(), mod = 1e9 + 7;
        for(int i = 0; i < n; i++){
            int el = arr[i];
            ans += ((i+1)*(n-i)*arr[i]);
            // (n-i) subarrays with starting point as arr[i]
            // (n-i)*i subarrays with arr[i] not as starting point
            ans %= mod;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        long long res = obj.subarraySum(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends