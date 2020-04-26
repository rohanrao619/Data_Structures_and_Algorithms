// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
long long maximumAmount(int arr[], int n) 
{
    // Your code here
    long long DP[n][n];
    int distance = 3; 
    
    for(int i=0;i<n;i++)
    DP[i][i] = arr[i];
    
    for(int i=0;i<n-1;i++)
    DP[i][i+1] = max(arr[i],arr[i+1]);
    
    while(distance<=n)
    for(int i=0;i<n;i++)
    {
        if(!((i+distance)<n))
        {
            distance+=2;
            break;
        }
        
        DP[i][i+distance] = max(arr[i]+min(DP[i+1][i+distance-1],DP[i+2][i+distance]),
                            arr[i+distance]+min(DP[i+1][i+distance-1],DP[i][i+distance-2]));
    }
    
    return DP[0][n-1];
}

// { Driver Code Starts.

int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    int N;
	    cin>>N;
	    
	    int A[N];
	    
	    for(int i=0;i<N;i++)
	    cin>>A[i];
	    
	    cout<<maximumAmount(A,N)<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends
