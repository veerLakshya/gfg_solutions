//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> ans;
    void h(vector<int>& a, int ind, int cur){
        if(ind < 0){
            ans.push_back(cur);
            return;
        }
        h(a, ind - 1, cur + a[ind]);
        h(a, ind - 1, cur);
    }
    
    vector<int> subsetSums(vector<int>& arr) {
        h(arr, arr.size() - 1, 0);
        // vector<int> ans1;
        // for(auto i: ans) ans1.push_back(i);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after the integer input

    while (t--) {
        vector<int> inputArray;
        string inputLine;

        // Input format: first number n followed by the array elements
        getline(cin, inputLine);
        stringstream inputStream(inputLine);
        int num;
        while (inputStream >> num) {
            inputArray.push_back(num); // Read the array elements from input string
        }

        Solution solutionObject;
        vector<int> result = solutionObject.subsetSums(inputArray);
        sort(result.begin(), result.end());

        for (int i = 0; i < result.size(); i++) {
            if (i != 0)
                cout << " ";
            cout << result[i];
        }
        cout
            << endl
            << "~\n"; // Print results in list format with new line after each test case
    }

    return 0;
}

// } Driver Code Ends