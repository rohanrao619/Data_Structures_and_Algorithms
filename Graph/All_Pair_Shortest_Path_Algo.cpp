#include<bits/stdc++.h>
using namespace std;
#define SIZE 1001

void Warshall(int adj[SIZE][SIZE],int V)
{
    for(int k=0;k<V;k++)
    for(int i=0;i<V;i++)
    for(int j=0;j<V;j++)
    {
        if(adj[i][k]!=INT_MAX and adj[k][j]!=INT_MAX)
        adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
    }
}

int main()
 {
	//code
	int T;
	cin>>T;
	
	while(T--)
	{
	    int V,E,a,b,c;
	    cin>>V>>E;
	    
	    int adj[SIZE][SIZE],shortPaths[SIZE][SIZE];
	    
	    for(int i=0;i<V;i++)
	    for(int j=0;j<V;j++)
	    {
	        if(i==j)
	        {
	        	adj[i][j] = 0;
	        	shortPaths[i][j] = 0;	
			}
	        else
	        {
	        	adj[i][j] = INT_MAX;
	        	shortPaths[i][j] = INT_MAX;	
			}
	    }
	    
	    for(int i=0;i<E;i++)
	    {
	        cin>>a>>b>>c;
	        adj[a-1][b-1] = c;
	        adj[b-1][a-1] = c;
	    }
	    
	    Warshall(shortPaths,V);
	    
	    for(int i=0;i<V;i++)
	    {
	    	for(int j=0;j<V;j++)
			cout<<shortPaths[i][j]<<" ";
			
			cout<<endl;	
		}
	}
	
	return 0;
}
