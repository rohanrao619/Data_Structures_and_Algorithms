// { Driver Code Starts
// C++ program to evaluate value of a postfix expression
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// The main function that returns value of a given postfix expression

int isOperator(char c)
{
    if(c>=48 && c<=57)
    return 0;
    else
    return 1;
}

int calculate(int a,int b,char c)
{
    switch(c)
    {
        case '+' : return a+b;
        case '-' : return a-b;
        case '*' : return a*b;
        case '/' : return a/b;
        case '^' : return int(pow(a,b));
    }
}

int evaluatePostfix(string &str)
{
    // Your code here
    stack<int> stk;
    
    int a,b,i;
    
    for(i=0;i<str.length();i++)
    {
        if(isdigit(str[i]))
        stk.push(str[i]-48);
        else
        {
            b=stk.top();
            stk.pop();
            a=stk.top();
            stk.pop();
            
            stk.push(calculate(a,b,str[i]));
        }
    }
    
    return stk.top();
}


// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string str;
        cin>>str;
    
    cout<<evaluatePostfix(str)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
