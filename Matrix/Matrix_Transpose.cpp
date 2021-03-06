// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

#define N 30


 // } Driver Code Ends
/*  Function which converts A[][] to its transpose
*   n: size of matrix
*   N: globally defined for matrix
*   A: input matrix
*/
void transpose( int A[][N],int n) 
{ 
	// Your code here
	int temp;
	
	for(int i=0;i<n;i++)
	for(int j=0;j<i;j++)
	{
	    temp=A[i][j];
	    A[i][j]=A[j][i];
	    A[j][i]=temp;
	}
}

// { Driver Code Starts.

int main() 
{ 
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n;
	    cin >> n;
	    int A[N][N];
	    for(int i = 0;i<n;i++){
	        for(int j = 0;j<n;j++){
	            cin >> A[i][j];
	        }
	    }
	    
	    transpose(A, n);
	    
	    for (int i = 0; i < n; i++) 
    	{ 
    		for (int j = 0; j < n; j++) 
    		printf("%d ", A[i][j]); 
    	
    	}
    	cout<<endl;
	    
	}

	return 0; 
} 
  // } Driver Code Ends
