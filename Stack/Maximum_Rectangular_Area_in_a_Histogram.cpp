// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return Maximum Rectangular area in a histogram
// arr[]: input array
// n: size of array
long getMaxArea(long long arr[], int n){
    
    // Your code here
    stack<long long> stk;
    long max=-1,curr,area,i=0;
    
    while(i<n)
    {
        if(stk.empty() || arr[i]>=arr[stk.top()])
        {
            stk.push(i);
            i++;
        }
        else 
        {
            curr = stk.top();
            stk.pop();
            area = arr[curr]*(stk.empty()?i:(i-1-stk.top()));
            if(area>max)
            max=area;
        }
        
        
    }
    
    while(!stk.empty())
    {
        curr = stk.top();
        stk.pop();
        area = arr[curr]*(stk.empty()?n:(n-1-stk.top()));
        if(area>max)
        max=area;
    }
    
    return max;
}

// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        cout<<getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends
