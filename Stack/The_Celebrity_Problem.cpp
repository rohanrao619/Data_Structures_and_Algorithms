// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 501

int getId(int M[MAX][MAX],int n);

int main()
{
    int T;
    cin>>T;
    int M[MAX][MAX];
    while(T--)
    {
        int N;
        cin>>N;
        memset(M,0,sizeof M);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin>>M[i][j];
            }
        }
        cout<<getId(M,N)<<endl;

    }
}

// } Driver Code Ends
// The task is to complete this function

// M[][]: input matrix
// n: size of matrix (n*n)
int getId(int M[MAX][MAX], int n)
{
    //Your code here
    stack<int> stk;
    int a,b,i;
    
    for(i=0;i<n;i++)
    stk.push(i);
    
    while(stk.size()>1)
    {
        a = stk.top();
        stk.pop();
        b=stk.top();
        stk.pop();
        
        if(M[a][b]^M[b][a]==1)
        stk.push((M[a][b]==0)?a:b);
    }
    
    if(stk.empty())
    return -1;
    
    for(i=0;i<n;i++)
    {
        if(i!=stk.top() && M[i][stk.top()]==0)
        return -1;
        
        if(M[stk.top()][i]==1)
        return -1;
        
    }
    
    return stk.top();
}
