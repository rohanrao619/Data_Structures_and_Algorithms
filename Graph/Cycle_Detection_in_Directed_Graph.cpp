// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
bool DFS(int curr,vector<int> adj[],bool visited[],bool rstack[])
{
    visited[curr] = true;
    rstack[curr]=true;
    
    for(int i:adj[curr])
    {
        if(rstack[i]==true)
        return true;
        
        if(visited[i]==false)
        {
            bool res = DFS(i,adj,visited,rstack);
            
            if(res==true)
            return true;
        }
    }
    
    rstack[curr] = false;
    return false;
}


bool isCyclic(int V, vector<int> adj[])
{
    // Your code here
    bool visited[V],rstack[V];
    
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
        rstack[i]=false;
    }
    
    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
        {
            bool res = DFS(i,adj,visited,rstack);
            
            if(res == true)
            return true;
        }
    }
    
    return false;
}

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
