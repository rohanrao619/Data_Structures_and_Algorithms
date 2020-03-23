// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

#define SIZE 100


 // } Driver Code Ends
/*  Function to exchange columns
*   n1, m1: rows and cols of matrix
*   SIZE: defined globally for matrix
*   arr1[][]: input matrix
*/
void exchangeColumns(int n1, int m1, int arr1[SIZE][SIZE]){
    
    // Your code here
    int temp;
    
    for(int i=0;i<n1;i++)
    {
        temp = arr1[i][0];
        arr1[i][0] = arr1[i][m1-1]; 
        arr1[i][m1-1] = temp;
    }
    
    for(int i=0;i<n1;i++)
    for(int j=0;j<m1;j++)
    cout<<arr1[i][j]<<" ";
    
}

// { Driver Code Starts.

int main() {
    long long t;
    cin>>t;
    while(t--)
    {
        int n1,m1;
        cin>>n1>>m1;
        int arr1[SIZE][SIZE];
        for(int i=0;i<n1;i++)
        for(int j=0;j<m1;j++)
        cin>>arr1[i][j];
        
        exchangeColumns(n1, m1, arr1);
        cout<<endl;
    }
    
	return 0;
}  // } Driver Code Ends
