// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

//Complete this function
long long maximumSum(int arr[], int sizeOfArray)
{
  //Your code here
    long long DP[sizeOfArray];
    DP[0] = arr[0];
    
    if(sizeOfArray==1)
    return DP[0];
    
    DP[1] = max(arr[0],arr[1]);
    
    for(int i=2;i<sizeOfArray;i++)
    {
        if(DP[i-2]<0)
        DP[i] = max((long long)arr[i],DP[i-1]);
        else
        DP[i] = max(DP[i-1],DP[i-2]+arr[i]);
        
        
    }
    
    // long long res = INT_MIN;
    
    // for(int i=0;i<sizeOfArray;i++)
    // res = max(res,DP[i]);
    
    return DP[sizeOfArray-1];
}


// { Driver Code Starts.


int main() {
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
	    int sizeOfArray;
	    cin>>sizeOfArray;
	    
	    int arr[sizeOfArray];
	    
	    for(int i=0;i<sizeOfArray;i++)
	    cin>>arr[i];
	    
	    cout<<maximumSum(arr,sizeOfArray)<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends
