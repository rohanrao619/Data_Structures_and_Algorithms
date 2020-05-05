#include<bits/stdc++.h>
using namespace std;
#define SIZE 101

struct Comp
{
    bool operator()(pair<int,pair<int,int>> A,pair<int,pair<int,int>> B)
    {
        return A.first>B.first;
    }
};

int main()
 {
	//code
	int T;
	cin>>T;
	
	while(T--)
	{
	    int V;
	    cin>>V;
	    int adj[SIZE][SIZE],DIST[SIZE][SIZE],temp;
	    bool vis[SIZE][SIZE];
	    
	    for(int i=0;i<V;i++)
	    for(int j=0;j<V;j++)
	    {
	        cin>>temp;
	        adj[i][j] = temp;
	        vis[i][j] = false;
	        DIST[i][j] = INT_MAX;
	    }
	    
	    DIST[0][0] = adj[0][0];
	    
	    vector<pair<int,int>> moves{{0,1},{1,0},{0,-1},{-1,0}};
	    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,Comp> PQ;
	    
	    PQ.push({DIST[0][0],{0,0}});
	    
	    while(!PQ.empty())
	    {   
	        pair<int,pair<int,int>> curr = PQ.top();
	        
	        int x = curr.second.first;
	        int y = curr.second.second;
	        
	        if(vis[x][y]==false)
	        vis[x][y] = true;
	        else
	        {
	            PQ.pop();
	            continue;
	        }
	        
	        for(pair<int,int> move:moves)
	        {
	            int p = x+move.first,q=y+move.second;
	            if(vis[p][q]==false and p>=0 and q>=0 and p<V and q<V)
	            {
	                if(DIST[p][q]>(DIST[x][y]+adj[p][q]))
	                {
	                    DIST[p][q] = DIST[x][y]+adj[p][q];
	                    PQ.push({DIST[p][q],{p,q}});
	                }
	            }
	        }
	        
	        PQ.pop();
	    }
	    
	    cout<<DIST[V-1][V-1]<<endl;
	}
	
	return 0;
}
