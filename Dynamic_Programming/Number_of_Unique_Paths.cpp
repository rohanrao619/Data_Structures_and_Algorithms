#include<iostream>
using namespace std;

int countPossiblePaths(int m,int n)
{
    int DP[m+1][n+1];
    
    for(int i=0;i<=m;i++)
    for(int j=0;j<=n;j++)
    {
        if(i==1 && j==1)
        DP[i][j] = 1;
        
        else if(i==0||j==0)
        DP[i][j] = 0;
        
        else
        DP[i][j] = DP[i-1][j] + DP[i][j-1];
    }
    
    return DP[m][n];
}

int main()
 {
	int T;
	cin>>T;
	
	while(T--)
	{
	    int m,n;
	    cin>>m>>n;
	    
	    cout<<countPossiblePaths(m,n)<<endl;
	}
	return 0;
}
