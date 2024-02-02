//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool matching(char a, char b){
        return(
            (a=='(' && b ==')')||
            (a=='{' && b =='}')||
            (a=='[' && b ==']')
            );
    }
    bool ispar(string x)
    {
        stack <char> st;
        for(char i:x){
            if(i=='(' || i=='{' ||i== '[')
            st.push(i);
            else{
                if(st.empty()==true) return false;
                if(matching(st.top(),i)==false)
                return false;
                else st.pop();
            }
        }
        return st.empty()==true;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends