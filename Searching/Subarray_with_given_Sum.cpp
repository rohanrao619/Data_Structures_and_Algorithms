// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to find the subarray with given sum k
// arr: input array
// n: size of array
void subarraySum(int arr[], int n, int s){
    
    // Your code here
    int start=0,end=0,sum;
    
    int prefix[n+1];
    prefix[0]=0;
    prefix[1]=arr[0];
    
    for(int i=1;i<n;i++)
    prefix[i+1]=prefix[i]+arr[i];
    
    while(true)
    {
        if(end==n)
        {
            cout<<"-1";
            break;
        }
        
        sum = prefix[end+1]-prefix[start];
        
        if(sum==s)
        {
            cout<<start+1<<" "<<end+1;
            break;
        }
        
        if(sum>s)
        start++;
        else
        end++;
        
    }
    
}

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        subarraySum(arr, n, s);
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
