// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

#define SIZE 100


 // } Driver Code Ends
/*  Function to find the area of 1s
*   SIZE: declared globally for matrix definition
*   n, m: row and column of matrix
*   g[][]: 2D matrix from input
*/
void DFS(pair<int,int> s,int g[SIZE][SIZE],bool vis[SIZE][SIZE],int n,int m,int &count)
{
    int x=s.first;
    int y=s.second;
    count++;
    
    vis[x][y]=true;
    for(int i=-1;i<=1;i++)
    for(int j=-1;j<=1;j++)
    {
        if((x+i)<n and (x+i)>=0 and (y+j)<m and (y+j)>=0)
        if(vis[x+i][y+j]==false and g[x+i][y+j]==1)
        DFS({x+i,y+j},g,vis,n,m,count);
    }
}

int findMaxArea(int n, int m, int g[SIZE][SIZE] )
{
    // Your code here
    bool vis[SIZE][SIZE];
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    vis[i][j]=false;
    
    int count,largest=INT_MIN;
    
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    {
        if(vis[i][j]==false and g[i][j]==1)
        {
            count=0;
            DFS({i,j},g,vis,n,m,count);
            largest = max(count,largest);
        }
    }
    
    return largest;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int g[SIZE][SIZE];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> g[i][j];

        cout << findMaxArea(n, m, g) << endl;
    }

    return 0;
}  // } Driver Code Ends
