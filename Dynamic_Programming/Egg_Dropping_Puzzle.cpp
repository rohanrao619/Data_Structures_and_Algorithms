// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

/* Function to get minimum number of trials needed in worst 
  case with n eggs and k floors */
int eggDrop(int n, int k) 
{
    // your code here
    
    int DP[k+1][n+1];
    
    for(int i=0;i<=n;i++)
    DP[0][i] = 0;
    
    for(int i=1;i<=k;i++)
    DP[i][0] = INT_MAX;
    
    for(int i=1;i<=k;i++)
    for(int j=1;j<=n;j++)
    {
        int res = INT_MAX;
        
        for(int x=1;x<=i;x++)
        {
            res = min(res,max(DP[x-1][j-1],DP[i-x][j]));
        }
        
        DP[i][j] = 1+res;
    }
    
    return DP[k][n];
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;

        cout<<eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
