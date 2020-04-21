#include<bits/stdc++.h>
using namespace std;

pair<int,int> moves[] = {{-1,0},{1,0},{0,-1},{0,1}};

bool DFS(pair<int,int> curr,int **adj,bool **visited,int V)
{
    visited[curr.first][curr.second]=true;
    
    for(pair<int,int> move:moves)
    {
        int x=curr.first+move.first;
        int y=curr.second+move.second;
        
        if(x>=0 && y>=0 && x<V && y<V && (adj[x][y]==3 || adj[x][y]==2))
        {
            if(adj[x][y]==2)
            return true;
            
            if(visited[x][y]==false)
            {
                bool res= DFS({x,y},adj,visited,V);
                
                if(res==true)
                return true;
            }
        }
    }
    
    return false;
}

int main()
 {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    int V;
	    cin>>V;
	    int **adj;
	    bool **visited;
	    
	    pair<int,int> source;
	    
	    adj = new int *[V];
	    visited = new bool *[V];
	    
	    for(int i=0;i<V;i++)
	    {
	        adj[i] = new int[V];
	        visited[i] = new bool[V];
	    }
	    
	    for(int i=0;i<V;i++)
	    for(int j=0;j<V;j++)
	    {
	        visited[i][j]=false;
	        cin>>adj[i][j];
	        
	        if(adj[i][j]==1)
	        source = {i,j};
	    }
	    
	    if(DFS(source,adj,visited,V))
	    cout<<"1"<<endl;
	    else
	    cout<<"0"<<endl;
	    
	}
	return 0;
}
