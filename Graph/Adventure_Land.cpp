#include<bits/stdc++.h>
using namespace std;
#define SIZE 1001

void dijkstra(int graph[SIZE][SIZE], int DIST[SIZE],int src, int V)
{
    // Your code here
    bool visited[V];
    
    for(int i=0;i<V;i++)
    {
        DIST[i] = INT_MAX;
        visited[i] = false;
    }
    
    DIST[src] = 0;
    
    for(int i=0;i<(V-1);i++)
    {
        int curr_min = INT_MAX,index = -1;
        for(int j=0;j<V;j++)
        {
            if(DIST[j]<curr_min and visited[j]==false)
            {
                index = j;
                curr_min = DIST[j];
            }
        }
        
        if(index==-1)
        break;
        
        visited[index] = true;
        
        for(int j=0;j<V;j++)
        {
            if(visited[j]==false and DIST[index]!=INT_MAX and 
            graph[index][j]!=INT_MAX and (DIST[j]>(DIST[index]+graph[index][j])))
            DIST[j] = DIST[index]+graph[index][j];
        }
    }
}

int main()
 {
	//code
	int T;
	cin>>T;
	
	while(T--)
	{
	    int V,E,a,b,c,S,K;
	    cin>>V>>E;
	    
	    int adj[SIZE][SIZE];
	    
	    for(int i=0;i<V;i++)
	    for(int j=0;j<V;j++)
	    {
	        if(i==j)
	        adj[i][j] = 0;
	        else
	        adj[i][j] = INT_MAX;
	    }
	    
	    for(int i=0;i<E;i++)
	    {
	        cin>>a>>b>>c;
	        adj[a-1][b-1] = c;
	        adj[b-1][a-1] = c;
	    }
	    
	    int maximum = -1,index,res=0 ;
	    cin>>S>>K;
	    
	    int DIST[V];
	    for(int i=0;i<V;i++)
	    DIST[V] = INT_MAX;
	    dijkstra(adj,DIST,S-1,V);
	    
	    for(int i=0;i<K;i++)
	    {
	        cin>>a;
	        res+=(2*DIST[a-1]);
	        
	        if(DIST[a-1]>maximum)
	        {
	            maximum = DIST[a-1];
	            index = a-1;
	        }
	    }
	    
	    res -= DIST[index];
	    
	    cout<<res<<endl;
	}
	
	return 0;
}
