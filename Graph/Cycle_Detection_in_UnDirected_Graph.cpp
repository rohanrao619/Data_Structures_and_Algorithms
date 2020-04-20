// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
/* This function is used to detect a cycle in undirected graph
*  adj[]: array of vectors to represent graph
*  V: number of vertices
*/
bool DFS(int curr,int parent,vector<int> adj[],bool visited[])
{
    visited[curr] = true;
    
    for(int i:adj[curr])
    {
        if(i==curr)
        return true;
        
        if(visited[i]==true && parent!=-1 && i!=parent)
        return true;
        
        if(visited[i]==false)
        {   
            bool res = DFS(i,curr,adj,visited);
            if(res==true)
            return true;
        }
    }
    
    return false;
}

bool isCyclic(vector<int> adj[], int V)
{
   // Your code here
   bool visited[V],result;
   
   for(int i=0;i<V;i++)
   visited[i]=false;
   
  for(int i=0;i<V;i++)
  {
      if(visited[i]==false)
      result = DFS(i,-1,adj,visited);
      
      if(result==true)
      return true;
  }
  
   return false;
}

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}
  // } Driver Code Ends
