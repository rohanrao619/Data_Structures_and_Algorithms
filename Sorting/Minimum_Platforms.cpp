// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
int findPlatform(int arr[], int dep[], int n)
{
	// Your code here
	int prefix[2400],i,max=0;
	
	for(i=0;i<2400;i++)
	prefix[i]=0;
	
	for(i=0;i<n;i++)
	{
	    prefix[arr[i]]++;
	    prefix[dep[i]+1]--;
	}
	
	for(i=1;i<2400;i++)
	{
	    prefix[i]+=prefix[i-1];
	    if(prefix[i]>max)
	    {
	        max=prefix[i];   
	    }
	}
	
	return max;
}


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
           for(int i=0;i<n;i++)
        cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
    cout <<findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends
