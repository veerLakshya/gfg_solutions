//{ Driver Code Starts
// Program to find maximum guest at any time in a party
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	
	public:
	vector<int> findMaxGuests(int Entry[], int Exit[], int N)
	{
	    map<int,int> mp;
	    for(int i = 0; i < N; i++){
	        mp[Entry[i]]++;
	        mp[Exit[i]+1]--;
	    }
	    int time = -1, ans = 0, cur = 0;;
	    for(auto i: mp){
	        cur += i.second;
	        if(cur > ans){
	            ans = cur;
	            time = i.first;
	        }
	    }
	    return {ans, time};
	}

};


//{ Driver Code Starts.

 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        int entry[n],exit1[n];
        for(i=0;i<n;i++)
        cin>>entry[i];
        for(i=0;i<n;i++)
        cin>>exit1[i];
        Solution obj;

	    vector<int> p = obj.findMaxGuests(entry, exit1, n);
	    cout<<p[0]<<' '<<p[1];
	    cout<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends