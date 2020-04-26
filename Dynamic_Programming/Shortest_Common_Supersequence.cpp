
#include<bits/stdc++.h>
using namespace std;

int lcs(int, int, string, string);

int main()
{
    int t,n,k;
    
    cin>>t;
    while(t--)
    {
        string s1,s2;
        cin>>s1>>s2;   
        int m = s1.length();
        int n = s2.length();
        
        cout << max(m,n)+(min(m,n)-lcs(m,n,s1,s2)) << endl;
    }
    return 0;
}

int lcs(int x, int y, string s1, string s2){
    
    int DP[x+1][y+1];
    
    for(int i=0;i<=x;i++)
    DP[i][0] = 0;
    
    for(int j=0;j<=y;j++)
    DP[0][j] = 0;
    
    for(int i=1;i<=x;i++)
    for(int j=1;j<=y;j++)
    {
        if(s1[i-1]==s2[j-1])
        DP[i][j] = (1+DP[i-1][j-1]);
        else
        DP[i][j] = max(DP[i][j-1],DP[i-1][j]);
    }
    
    return DP[x][y];
    
}

