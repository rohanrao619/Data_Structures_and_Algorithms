// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
 
int findCount(int pattern,int arr[],int n)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
     if((arr[i]&pattern)==pattern)
     count++;
    }
    
    return count;
}
 
// Function for finding maximum and value pair
int maxAND (int arr[], int n)
{
    int res=0,count;
    
    for (int i=31;i>=0;i--)
    {
        count = findCount((res|(1<<i)),arr,n);
        if(count>=2)
        res|=(1<<i);
    }
    
    return res;
    
    // Your code here
    
}

// { Driver Code Starts.
 
// Driver function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        cout <<  maxAND(arr,n)<<endl;
    }
    return 0;
}  // } Driver Code Ends
