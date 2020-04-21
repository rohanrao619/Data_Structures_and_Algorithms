// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// The Graph structure is as folows

/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*   NOTE: You must return dynamically allocated array
*/
int* topoSort(int V, vector<int> adj[]) {
    // Your code here
    
    int indegree[V] = {0};
    int *res = new int[V],index=0;
    queue<int> Q;
    
    for(int i=0;i<V;i++)
    for(int j:adj[i])
    {
        indegree[j]++;
    }
    
    for(int i=0;i<V;i++)
    if(indegree[i]==0)
    Q.push(i);
    
    while(!Q.empty())
    {
        int curr = Q.front();
        Q.pop();
        res[index++] = curr;
        
        for(int i:adj[curr])
        {
            indegree[i]--;
            
            if(indegree[i]==0)
            Q.push(i);
        }
    }
    
    return res;
}


// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
bool check(int V, int* res, vector<int> adj[]) {
    bool flag = true;
    for (int i = 0; i < V && flag; i++) {
        int n = adj[res[i]].size();
        for (auto j : adj[res[i]]) {
            for (int k = i + 1; k < V; k++) {
                if (res[k] == j) n--;
            }
        }
        if (n != 0) flag = false;
    }
    if (flag == false) return 0;
    return 1;
}

// Driver Code
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        int* res = topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
}
  // } Driver Code Ends
