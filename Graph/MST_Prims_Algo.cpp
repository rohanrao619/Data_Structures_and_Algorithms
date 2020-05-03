// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V,int E,vector<vector<int> > graph);
// Driver code

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int V,E;
        cin>>V>>E;
        vector< vector<int> > graph(V,vector<int>(V,INT_MAX));

        while(E--)
        {
            int u,v,w;
            cin>>u>>v>>w;
            u--,v--;
            graph[u][v] = w;
            graph[v][u] = w;
        }

        cout<<spanningTree(V,E,graph)<<endl;
    }
    return 0;
}

// } Driver Code Ends


// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation, with V vertices.
// graph[i][j] = weight if edge exits else INT_MAX
int spanningTree(int V,int E,vector<vector<int>> graph)
{
    // code here
    int DIST[V],result = 0;
    bool visited[V];
    
    for(int i=0;i<V;i++)
    {
        DIST[i] = INT_MAX;
        visited[i] = false;
    }
    
    DIST[0] = 0;
    
    for(int i=0;i<V;i++)
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
        
        visited[index] = true;
        result += DIST[index];
        
        for(int j=0;j<V;j++)
        {
            if(visited[j]==false and (DIST[j]>graph[index][j]))
            DIST[j] = graph[index][j];
        }
    }
    
    return result;
}
