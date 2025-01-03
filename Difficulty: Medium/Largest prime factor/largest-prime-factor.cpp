//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int largestPrimeFactor(int n) {
        int ans = 1;
        if(n % 2 == 0){
            ans = 2;
            while(n%2 == 0) n /= 2;
        }
        if(n % 3 == 0){
            ans = 3;
            while(n%3 == 0) n /= 3;
        }
        
        for(int i = 5; i <= sqrt(n); i++ ){
            if(n % i == 0){
                ans = i;
                while(n % i == 0) n /= i;
            }
        }
        if(n > 1) ans = n;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends