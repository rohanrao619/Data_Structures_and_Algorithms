// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

#define SIZE 100


 // } Driver Code Ends
/*  Function to find sum of upper and lower triangles

*   n: row/col in matrix
*   mat[][]: input matrix
*/
void sumTriangles(int n, int mat[SIZE][SIZE]){
    
    // Your code here
    int upper_sum=0,lower_sum=0;
    
    for(int i=0;i<n;i++)
    for(int j=0;j<=i;j++)
    {
        lower_sum+=mat[i][j];
    }
    
    for(int i=0;i<n;i++)
    for(int j=i;j<n;j++)
    {
        upper_sum+=mat[i][j];
    }
    
    cout<<upper_sum<<" "<<lower_sum;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t; //input the testcases
    while(t--) //while testcases exist
    {
        long int r,n,c,us=0,ls=0;
        cin>>n; //input number of rows 
        r=n;
        c=r; //Since the matrix is a square matrix, number of cols=number of rows
        int i,j,mat[SIZE][SIZE];
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            cin>>mat[i][j]; //input the elements of matrix
        }
        
        sumTriangles(r, mat);
        
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
