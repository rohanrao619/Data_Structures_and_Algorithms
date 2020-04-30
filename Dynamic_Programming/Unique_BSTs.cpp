// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return number of trees
int numTrees(int n) {
    
    // Your code here
    long long DP[n+1];
    long long mod = 1000000007; 
    DP[0] = 1;
    
    for(int i=1;i<=n;i++)
    {   
        int res = 0;
        
        for(int j=0;j<i;j++)
        res = (res+((DP[j]*DP[i-1-j])%mod))%mod;
        
        DP[i] = res;
    }
    
    return DP[n]; 
}

// { Driver Code Starts.
#define mod (int)(1e9+7)
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<numTrees(n)<<"\n";
    }
}	  // } Driver Code Ends
