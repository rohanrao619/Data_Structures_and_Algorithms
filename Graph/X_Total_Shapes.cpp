#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> neighbours{{0,1},{0,-1},{1,0},{-1,0}};

void DFS(pair<int,int> curr,string arr[],bool **vis,int n,int m)
{
    int x=curr.first;
    int y=curr.second;
    
    vis[x][y]=true;
    
    for(auto neighbour:neighbours)
    {
        int i = x+neighbour.first;
        int j = y+neighbour.second;
        
        if(i<n and i>=0 and j<m and j>=0)
        if(vis[i][j]==false and arr[i][j]=='X')
        DFS({i,j},arr,vis,n,m);
    }
}

int main()
{
	//code
	
	int T;
	cin>>T;
	
	while(T--)
	{
	    int n,m,count=0;
	    cin>>n>>m;
	    
	    string arr[n];
	    
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    
	    bool **vis;
	    vis = new bool *[n];
	    
	    for(int i=0;i<n;i++)
	    {
	        vis[i] = new bool[m];
	        
	        for(int j=0;j<m;j++)
	        vis[i][j]=false;
	    }
	    
	    for(int i=0;i<n;i++)
	    for(int j=0;j<m;j++)
	    {
	        if(vis[i][j]==false and arr[i][j]=='X')
	        {
	            count++;
	            DFS({i,j},arr,vis,n,m);
	        }
	    }
	    
	    cout<<count<<endl;
	}
	
	return 0;
}
