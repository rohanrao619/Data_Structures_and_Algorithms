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

long long countWays(int n){
    
    vector<long long> DP(n+1,0);
    vector<int> Scores{3,5,10};
    DP[0] = 1;
    
    for(int j:Scores)
    for(int i=1;i<=n;i++)
    if(i>=j)
    DP[i] = (DP[i]+DP[i-j]);
    
    return DP[n];
    
}

