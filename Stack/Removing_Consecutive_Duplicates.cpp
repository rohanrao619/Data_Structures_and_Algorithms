// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to print string after removing consecutive duplicates


string removeConsecutiveDuplicates(string s)
{
    // Your code here
    stack<char> stk;
    string res;
    
    for(char c:s)
    {
        if(stk.empty() || stk.top()!=c)
        {
            stk.push(c);
            res+=c;
        }
    }
    
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
        cout<<removeConsecutiveDuplicates(s)<<endl;
    }
    
	return 0;
}  // } Driver Code Ends
