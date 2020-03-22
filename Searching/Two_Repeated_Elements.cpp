// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to find the two repeated element
// arr: input array
// n: size of array
void twoRepeated(int arr[], int n){
    
    // Your code here
    for(int i=0;i<(n+2);i++)
    {
        arr[arr[i]%(n+1)-1]+=(n+1);
        if((arr[arr[i]%(n+1)-1]/(n+1))==2)
        cout<<arr[i]%(n+1)<<" ";
    }
}

// { Driver Code Starts.

int main()
{
    int t,n;
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        
        int a[n+2];
        
        for(int i=0;i<n+2;i++)
            cin>>a[i];
        
        twoRepeated(a, n);
        cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends
