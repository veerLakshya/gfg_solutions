//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        if(K==1 || N==1) return *max_element(Arr.begin(),Arr.end());
        long sum=0;
        int i;
        for(i=0;i<K;i++){
            sum+=Arr[i];
        }
        if(K==N)return sum;
        long ans=sum;
        for(int j=i;j<N;j++){
            sum+=Arr[j];
            sum-=Arr[j-K];
            ans=max(ans,sum);
        }
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
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends