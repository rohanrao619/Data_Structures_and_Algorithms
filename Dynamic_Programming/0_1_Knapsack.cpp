// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Returns the maximum value that  
// can be put in a knapsack of capacity W 
int knapSack(int W, int wt[], int val[], int n) 
{ 
   // Your code here
   int DP[n+1][W+1];
   
   for(int i=0;i<=n;i++)
   for(int j=0;j<=W;j++)
   {
       if(i==0 || j==0)
       {
           DP[i][j]=0;
           continue;
       }
       
       if(wt[i-1]>j)
       DP[i][j]=DP[i-1][j];
       else
       DP[i][j] = max(DP[i-1][j],val[i-1]+DP[i-1][j-wt[i-1]]);
   }
   
   return DP[n][W];
}





// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n, w;
        cin>>n>>w;
        int val[n];
        int wt[n];
        
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        for(int i=0;i<n;i++)
            cin>>wt[i];
        
        cout<<knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
