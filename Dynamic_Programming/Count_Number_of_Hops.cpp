// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 
long long countWays(int);
 
int main()
{
	int t;
	cin >> t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		cout << countWays(n) << endl;
	}
    
    return 0;
    
}
// } Driver Code Ends
// function to count number of ways to reach top of the stair
long long countWays(int n){
    
    // your code here
    vector<long long> DP(n+1,0);
    DP[0] = 1;
    
    for(int i=1;i<=n;i++)
    for(int j=1;j<=3;j++)
    if(i>=j)
    DP[i] = (DP[i]+DP[i-j])%1000000007;
    
    return DP[n];
    
}

