//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minTime(vector<int>& arr, int k) {
        int l = *max_element(arr.begin(),arr.end());
        int r = accumulate(arr.begin(),arr.end(), 0);
        int ans = INT_MAX;
        
        auto h = [&](int x) -> bool{
            int cnt = 1, cur = 0;
            for(auto i: arr){
                cur += i;
                if(cur > x){
                    cur = i;
                    cnt++;
                }
            }
            return cnt <= k;
        };
        
        while(l <= r){
            int mid = l + (r-l) / 2;
            if(h(mid)){
                ans = min(ans, mid);
                r = mid - 1;
            } 
            else l = mid + 1;
        }
        return ans;
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
        int k;
        cin >> k;
        cin.ignore();
        Solution obj;
        cout << obj.minTime(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends