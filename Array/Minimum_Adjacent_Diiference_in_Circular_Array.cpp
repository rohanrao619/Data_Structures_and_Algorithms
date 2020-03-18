// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to find minimum adjacent difference
// arr[]: input array
// n: size of array
int minAdjDiff(int arr[], int n){    
    // Your code here
    int min = abs(arr[0]-arr[n-1]);
    
    for(int i =0;i<n-1;i++)
    if(abs(arr[i]-arr[i+1])<min)
    min = abs(arr[i]-arr[i+1]);
    
    return min;
}

// { Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin>>t; //Input testcases
    
    while(t--) //While testcases exist
    {
        int n;
        cin>>n; //Input size of array
        
        int arr[n]; //Array of size n
        
        for(int i = 0; i < n; i++)
        {
            cin>>arr[i]; //input elements of array
        }
        
        cout << minAdjDiff(arr, n) << endl;
    }
    return 0;
}  // } Driver Code Ends
