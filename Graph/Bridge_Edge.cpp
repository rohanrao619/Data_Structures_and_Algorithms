// { Driver Code Starts
//Initial template
#include<bits/stdc++.h>
using namespace std;
class Graph
{
	int V;
	list<int> *adj;
public:
	Graph(int V); 
	int addEdge(int v, int w);
	bool isBridge(int u, int v);
};
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}
int Graph::addEdge(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

// Driver Program
int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        int s,N;
        cin>>s>>N;
        Graph *g = new Graph(s);
        for(int i=0;i<N;i++)
        {
            int u,v;
            cin>>u>>v;
            g->addEdge(u,v);
        }
        int a,b;
        cin>>a>>b;
        
         if(g->isBridge(a, b))
            cout<<1<<endl;
        else
             cout<<0<<endl;
         }
}
// } Driver Code Ends


// your task is to complete this function


/*The structure of the class is as follows 
which contains an integer V denoting the no 
of vertices and a list of adjacency vertices.
class Graph
{
    int V;
    list<int> *adj;
public :
    Graph(int V);
    void addEdge(int v,int w);
    bool isBridge();
};*/

bool DFS(int curr,list<int> *adj,bool vis[],int target,int source)
{
    bool result = true;
    vis[curr] = true;
    
    for(int i:adj[curr])
    {
        if(i==target and curr!=source)
        return false;
        
        if(vis[i]==false and i!=target)
        result = result&&DFS(i,adj,vis,target,source);
    }
    
    return result;
}

bool Graph::isBridge(int u, int v )
{
  //Code here
  bool vis[V];
  
  for(int i=0;i<V;i++)
  vis[i] = false;
  
  return DFS(v,adj,vis,u,v);
}
