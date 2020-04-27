// { Driver Code Starts
#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

int countWays(int);

// Driver program
int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin>>n;
        cout<<countWays(n)<<endl;
    }
    return 0;
}// } Driver Code Ends
// function to count number of ways in which n can
// be written as sum of two or more than two integers
int countWays(int n)
{
    // your code here
    vector<long long> DP(n+1,0);
    DP[0]=1;
    
    for(int i=1;i<n;i++)
    for(int j=1;j<=n;j++)
    if(j>=i)
    DP[j] = (DP[j]+DP[j-i])%1000000007;
    
    return DP[n];
}
