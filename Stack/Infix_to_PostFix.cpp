// { Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// The main function to convert infix expression
//to postfix expression

int precedence(char c)
{
    if(c=='*'||c=='/')
    return 1;
    else if(c=='+'||c=='-')
    return 0;
    else if(c=='^')
    return 2;
    else
    return -1;
}

string infixToPostfix(string s)
{
    // Your code here
    s = s+")";
    stack<char> stk;
    stk.push('(');
    
    string res="";
    
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(')
        stk.push('(');
        
        else if(s[i]==')')
        {
            while(stk.top()!='(')
            {
                res+=stk.top();
                stk.pop();
            }
            
            stk.pop();
        }
        
        else if(precedence(s[i])==-1)
        res+=s[i];
        
        else
        {
            while(stk.top()!='(' && (precedence(stk.top())>=precedence(s[i])))
            {
                res+=stk.top();
                stk.pop();
            }
            
            stk.push(s[i]);
        }
        
    }
    
    return res;
}


// { Driver Code Starts.
//Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string exp;
        cin>>exp;
        cout<<infixToPostfix(exp)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
