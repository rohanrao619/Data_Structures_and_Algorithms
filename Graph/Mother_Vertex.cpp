// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
/*
 * Function to find if there is a mother vertex in the given graph 
 * V: number of vertices in the graph
 * adj[]: graph representation
 */
 
void DFS(int s, vector<int> g[], bool vis[])
{
    // Your code here
    vis[s]=true;
    
    for(int i:g[s])
    {
        if(vis[i]==false)
        {
            DFS(i,g,vis);
        }
    }
} 

int findMother(int V, vector<int> adj[]) 
{ 
    // Your code here	
    bool vis[V];
    int mother;
    
    for(int i=0;i<V;i++)
    vis[i]=false;
    
    for(int i=0;i<V;i++)
    {
        if(vis[i]==false)
        {
            DFS(i,adj,vis);
            mother = i;
        }
    }
    
    for(int i=0;i<V;i++)
    vis[i]=false;
    
    DFS(mother,adj,vis);
    
    for(int i=0;i<V;i++)
    if(vis[i]==false)
    mother = -1;
    
    return mother;
    
} 

// { Driver Code Starts.

int main() 
{ 
    int T;
    cin>>T;
    while(T--){
        int num, edges;
        cin>>num>>edges;
        
        vector<int> adj[num];
        
        int u, v;
        while(edges--){
            cin>>u>>v;
            adj[u].push_back(v);
        }
        
        cout<<findMother(num, adj)<<endl;
    }

	return 0;
}   // } Driver Code Ends
