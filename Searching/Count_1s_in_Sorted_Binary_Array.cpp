// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int arr[5000001];


 // } Driver Code Ends
// Function to count number of Ones
// arr: input array declared globally
// n: size of input array
int countOnes(int n)
{
    
    // Your code here
    if(arr[n-1]==1)
    return n;
    
    int low=0,high=n-1,mid;
    
    while(low<=high)
    {
        
        mid=low+((high-low)/2);
        
        if(arr[mid]==1)
        if(arr[mid+1]==0)
        return mid+1;
        else
        low=mid+1;
        else
        high=mid-1;
        
    }
    
    return 0;
    
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
                
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        
        cout <<countOnes(n)<<endl;
    }
    return 0;
}  // } Driver Code Ends
