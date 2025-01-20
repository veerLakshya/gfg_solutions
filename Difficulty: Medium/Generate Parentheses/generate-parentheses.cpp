//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    vector<string> ans;
    int N;
    void helper(int index,int open,string st){
        if(index==N && open==0){
            ans.push_back(st);
            return;
        }
        if(index==N)return;
        helper(index+1,open+1,st+'(');
        if(open)
        helper(index+1,open-1,st+')');
    }
    vector<string> AllParenthesis(int n)
    {
        N = 2*n;
        helper(0,0,"");
        return ans;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	
cout << "~" << "\n";
}
	return 0; 
} 

// } Driver Code Ends