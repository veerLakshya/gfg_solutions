//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the smallest window in the string s1 consisting
    // of all the characters of string s2.
    string smallestWindow(string &s1, string &s2) {
        vector<int> fs1(26, 0), fs2(26, 0);
        for(auto i: s2) fs2[i - 'a']++;
        
        int r = 0, n = s1.size(), cur = 0, total = 0;
        string ans = s1;
        
        for(auto i: fs2) total += (i > 0);
        
        for(int i = 0; i < n; i++){
            int ci = s1[i] - 'a';
            while(r < n && cur != total){
                int ch = s1[r] - 'a';
                fs1[ch]++;
                if(fs2[ch] == fs1[ch])cur++;
                r++;
            }
            if(cur == total && ans.size() > r - i ){
                ans = s1.substr(i, r-i);
                // cout << r - i << " "<< ans <<endl;
            }
            if(fs1[ci] == fs2[ci]){
                cur--;
                fs1[ci]--;
            }
            else{
                fs1[ci]--;
            }
        }
        return (ans == s1 ? "" : ans);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        cin >> s1;
        string s2;
        cin >> s2;
        Solution obj;
        string str = obj.smallestWindow(s1, s2);
        if (str.size() == 0) {
            cout << "\"\"" << endl;
        } else {
            cout << str << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends