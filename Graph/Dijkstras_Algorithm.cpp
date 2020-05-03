// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<int>> , int ,int );


int main()
{
    int t;
    int V;
    cin>>t;
    while(t--){
        cin>>V;
        
        vector<vector<int>> g(V);
        
        for(int i = 0;i<V;i++){
            vector<int> temp(V);
            g[i] = temp;
        }
        
        for(int i=0;i<V;i++)
        {
      	    for(int j=0;j<V;j++)
      	    {
      		    cin>>g[i][j];
      	    }
        }
        
        int s;
        cin>>s;
        
        dijkstra(g, s, V);
        cout<<endl;
       }
        return 0;
}// } Driver Code Ends


/*  Function to implement Dijkstra
*   graph: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/
void dijkstra(vector<vector<int>> graph, int src, int V)
{
    // Your code here
    int DIST[V];
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
            if(visited[j]==false and (DIST[j]>(DIST[index]+graph[index][j])) and graph[index][j]!=0)
            DIST[j] = DIST[index]+graph[index][j];
        }
    }
    
    for(int i=0;i<V;i++)
    cout<<DIST[i]<<" ";
}
