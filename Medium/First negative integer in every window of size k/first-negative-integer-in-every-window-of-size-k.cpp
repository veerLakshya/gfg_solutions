//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
        vector<long long> ans;
        map<long long,long long> mp;
        for(int i=0;i<N;i++){
            if(A[i]<0)mp[i]=A[i];
            
            if(i>=K){
                if(A[i-K]<0)mp.erase(i-K);
            }
                if(i >= (K-1)){
                    if( mp.size()>0)
                    ans.push_back(mp.begin()->second);
                    else
                    ans.push_back(0);
                }
        }
        return ans;
 }