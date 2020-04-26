// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int maximizeTheCuts(int n, int x, int y, int z);

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        
        int x,y,z;
        cin>>x>>y>>z;
        
        cout<<maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}// } Driver Code Ends
//Complete this function
int maximizeTheCuts(int n, int x, int y, int z)
{
    //Your code here
    int DP[n+1];
    DP[0]=0;
    int res;
    
    for(int i=1;i<=n;i++)
    {
        res = max({((x>i)?INT_MIN:DP[i-x]),((y>i)?INT_MIN:DP[i-y]),((z>i)?INT_MIN:DP[i-z])});
        DP[i]=(res<=-1?-1:1+res);
    }
    
    return (DP[n]==-1?0:DP[n]);
}
