// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return string after removing consecutive duplicates

// Function to remove pair of characters
string removePair(string str){
    // Your code here
    stack<char> stk;
    string res="";
    
    for(char c:str)
    {
        if(stk.empty() || stk.top()!=c)
        {
            stk.push(c);
        }
        else
        {
            stk.pop();
        }
    }
    
    while(!stk.empty())
    {
        res+=stk.top();
        stk.pop();
    }
    
    reverse(res.begin(),res.end());
    
    return res;
    
}

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        string s;
        cin>>s;
        
        string ans = removePair (s);
        
        if(ans=="")
            cout<<"Empty String"<<endl;
        else
            cout<<ans<<endl;
    }
    
	return 0;
}  // } Driver Code Ends
