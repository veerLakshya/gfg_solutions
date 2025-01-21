//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        int n = mat.size();
        vector<string> ans;
        vector<vector<int>> vis = mat;
        for(auto &i: vis){
            for(auto &j: i) if(j)j = -1;
        }
        vector<int> dx = {1,-1,0,0}, dy = {0,0,1,-1};
        string d = "DURL";
        
        auto h = [&](int i, int j, string s, auto self)-> void{
            if(i == n-1 && j == n - 1){
                ans.push_back(s);
                return;
            }
            for(int k = 0; k < 4; k++){
                int x = i + dx[k];
                int y = j + dy[k];
                // can visit if vis[x][y] = 1
                if(x >= 0 && x < n && y >= 0 && y < n && vis[x][y] == -1){
                    vis[x][y] = 1;
                    self(x, y, s + d[k], self);
                    vis[x][y] = -1;
                }
            }
        };
        vis[0][0] = 1;
        h(0, 0, "", h);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends