// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to store Next larger elements


void nextLargerElement(long long arr[], int n){
    // Your code here
    
    stack<long long> stk;
    
    long long result[n];
    
    stk.push(arr[n-1]);
    result[n-1]=-1;
    
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]<stk.top())
        {
            result[i]=stk.top();
            stk.push(arr[i]);
        }
        else
        {
            while(!stk.empty() && arr[i]>=stk.top())
            stk.pop();
            
            if(stk.empty())
            result[i]=-1;
            else
            result[i]=stk.top();
            
            stk.push(arr[i]);
        }
    }
    for(int j=0;j<n;j++)
    cout<<result[j]<<" ";
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
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        
        nextLargerElement(arr, n);
        
        cout<<endl;
    }
	return 0;
}
  // } Driver Code Ends
