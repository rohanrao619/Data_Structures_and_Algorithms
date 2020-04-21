// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<int> *adj;

  public:
    Graph(int V);
    void addEdge(int u, int v);
    int countPaths(int s, int d);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V + 1];
}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
}


 // } Driver Code Ends
// The Graph structure is as folows
/*
class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int V);
    void addEdge(int u, int v);
    int countPaths(int s, int d);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V+1];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}
*/

// Function to find paths between 2 nodes
void DFS(int s,int d,list<int> *adj,bool rstack[],int &count)
{
    if(s==d)
    {
        count++;
        return;
    }
    
    rstack[s]=true;
    
    for(int i:adj[s])
    {
        if(rstack[i]==false)
        DFS(i,d,adj,rstack,count);
    }
    
    rstack[s]=false;
}

int Graph::countPaths(int s, int d) {
    
    // Your code here
    int count = 0;
    bool rstack[V];
    
    for(int i=0;i<V;i++)
    rstack[i]=false;
    
    DFS(s,d,adj,rstack,count);
    
    return count;
}

// { Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        int u, v;
        Graph g(N);
        while (M--) {
            cin >> u >> v;
            g.addEdge(u, v);
        }
        int s, e;
        cin >> s >> e;
        cout << g.countPaths(s, e) << endl;
    }
    return 0;
}  // } Driver Code Ends
