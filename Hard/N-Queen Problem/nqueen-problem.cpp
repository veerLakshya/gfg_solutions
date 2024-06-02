//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int N;
    bool valid(int i, int j, vector<string>& board) {
        int row = i;
        int col = j;
        while (row >= 0 &&
               col >= 0) { // checking if there is any queen in left diagonal
            if (board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }
        col = j;
        row = i;
        while (col < N &&
               row >= 0) { // checking if there is any queen in right diagonal
            if (board[row][col] == 'Q')
                return false;
            col++;
            row--;
        }
        col = j;
        row = i;
        while (row >= 0) { // checking if there is any queen in current colmn
            if (board[row][col] == 'Q')
                return false;
            row--;
        }
        return true;
    }
    void helper(int row, vector<string>& board, vector<int>& curr_ans,vector<vector<int>>& all_ans) {
        if (row == N) {
            all_ans.push_back(curr_ans); 
            return;
        }
        for (int col = 0; col < N; col++) {
            if (valid(row, col, board) == true) {
                board[row][col] = 'Q';
                curr_ans[col]=row+1;
                helper(row + 1, board, curr_ans,all_ans);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        N = n;
        vector<vector<int>> all_ans;
        vector<string> board(n);
        vector<int> curr_ans(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
            board[i] = s;
        helper(0, board, curr_ans, all_ans);
        sort(all_ans.begin(),all_ans.end());
        return all_ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends