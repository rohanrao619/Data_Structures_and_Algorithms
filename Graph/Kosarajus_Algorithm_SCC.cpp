// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/*  Function to find the number of strongly connected components
*   using Kosaraju's algorithm
*   V: number of vertices
*   adj[]: array of vectors to represent graph
*/
void DFS(int curr,vector<int> adj[],stack<int> &res,bool visited[],int V)
{
    visited[curr] = true;
    
    for(int i:adj[curr])
    {
        if(visited[i]==false)
        DFS(i,adj,res,visited,V);
    }
    
    res.push(curr);
}

int kosaraju(int V, vector<int> adj[])
{
    // Your code here
    bool visited[V];
    vector<int> trans[V];
    stack<int> dfs_res,_;
    int count = 0;
    
    for(int i=0;i<V;i++)    
    {
        vector<int> temp;
        trans[i] = temp;
        visited[i] = false;
    }
    
    for(int i=0;i<V;i++)
    if(visited[i]==false)
    DFS(i,adj,dfs_res,visited,V);
    
    for(int i=0;i<V;i++)
    for(int j:adj[i])
    trans[j].push_back(i);
    
    for(int i=0;i<V;i++)
    visited[i] = false;
    
    while(!dfs_res.empty())
    {
        if(visited[dfs_res.top()]==false)
        {
            DFS(dfs_res.top(),trans,_,visited,V);
            count++;
        }
        
        dfs_res.pop();
    }
    
    return count;
}

// { Driver Code Starts.

int main()
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int a,b ;
   	    cin>>a>>b;
   	    int m,n;
   	    vector<int> adj[a+1];
        for(int i=0;i<b;i++){
            cin>>m>>n;
            adj[m].push_back(n);
        }
        // exit(0);
        cout<<kosaraju(a, adj)<<endl;
    }
    return 0;
}  // } Driver Code Ends
