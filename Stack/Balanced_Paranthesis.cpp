// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return if the paranthesis are balanced or not

bool compare(char a,char b)
{
    if(a=='(' && b==')')
    return 1;
    
    if(a=='[' && b==']')
    return 1;
    
    if(a=='{' && b=='}')
    return 1;
    
    return 0;
}

bool ispar(string x)
{
    // Your code here
    stack<char> stk;
    
    for(char c:x)
    {
        if(c=='('||c=='{'||c=='[')
        stk.push(c);
        
        else 
        {
            if(stk.empty())
            return 0;
            
            if(compare(stk.top(),c))
            stk.pop();
            else
            return 0;
        }
    }
    
    return stk.empty();
}


// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       if(ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends
