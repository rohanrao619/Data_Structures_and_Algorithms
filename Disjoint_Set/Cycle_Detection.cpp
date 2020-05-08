// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// User function Template for C++

/*  Function to check if there is cycle in graph
*   adj[]: array of vectors to represent graph
*   n and e are number of nodes and edges respectively
*   parent[]: array to store parent of nodes. Each index stores its node value
* initially
*   rank1[]: Each node from 1 to n store initial size as 1.
*/

int find(int a,int par[])
{
    if(par[a]==a)
    return a;
    
    par[a] = find(par[a],par);  // Path Compression
    return par[a];
}

void unionNodes( int a, int b, int arr[], int rank[]) {
    
    int par_a = find(a,arr);
    int par_b = find(b,arr);
    
    if(par_a!=par_b)
    {
        if(rank[par_a]>rank[par_b])
        arr[par_b] = par_a;
        else if(rank[par_a]<rank[par_b])
        arr[par_a] = par_b;
        else
        {
            arr[par_b] = par_a;
            rank[par_a]++;
        }
    }
}

bool findCycle(vector<int> adj[], int parent[], int rank[], int n, int e) {

    // your code here
    for(int i=1;i<=n;i++)
    for(int j:adj[i])
    {
        if(i<j)
        {
            if(find(i,parent)==find(j,parent))
            return true;
        
            unionNodes(i,j,parent,rank);
        }
    }
    
    return false;
}


// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, e;
        cin >> n >> e;
        vector<int> adj[n + 1];

        int parent[n + 1];

        int rank1[n + 1];

        for (int i = 0; i < e; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // makeSet operation
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            rank1[i] = 1;
        }

        if (findCycle(adj, parent, rank1, n, e)) {
            cout << "1";
        } else
            cout << "0";

        cout << endl;
    }

    return 0;
}
  // } Driver Code Ends
