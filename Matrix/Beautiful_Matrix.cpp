// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findMinOpeartion(int matrix[][100], int n);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int mat[n][100];
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>mat[i][j];
        cout << findMinOpeartion(mat, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
//Complete this function

// Function to find minimum number of operation
int findMinOpeartion(int matrix[][100], int n)
{
    //Your code here
    int sum=0,rsum,csum,max=0,i,j;
    
    for(i=0;i<n;i++)
    {   
        rsum=0;
        csum=0;
        for(j=0;j<n;j++)
        {
            sum+=matrix[i][j];
            rsum+=matrix[i][j];
            csum+=matrix[j][i];
        }    
        
        if(rsum>max)
        max=rsum;
        
        if(csum>max)
        max=csum;
    }
    
    return (n*max)-sum;
}


