//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class BIT {
public:
    int size = 10005;
    vector<int> table;

    BIT() {
        table.resize(size, 0);
    }

    void update(int i) {
        while (i < size) {
            table[i] += 1;
            i += i & (-i);
        }
    }

    int sum(int i) {
        int total = 0;
        while (i > 0) {
            total += table[i];
            i -= i & (-i);
        }
        return total;
    }

    int cnt(int i) {
        return sum(size - 1) - sum(i);
    }
};

class Solution {
public:
    int inversionCount(vector<int> &arr) {
        int n = arr.size(), ans = 0;
        BIT bit;
        for (auto i : arr) {
            ans += bit.cnt(i);
            bit.update(i);
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends