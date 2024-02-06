//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
int equilibriumPoint(long long arr[], int n) 
    {
        int prefix=0,sum=0;
        for(int i=0; i<n; i++)
            prefix=prefix+arr[i];
        for(int j=0; j<n; j++)
        {
            if(sum==(prefix-sum-arr[j]))
            {
                return j+1;
            }
            sum+=arr[j];
        }
        return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends