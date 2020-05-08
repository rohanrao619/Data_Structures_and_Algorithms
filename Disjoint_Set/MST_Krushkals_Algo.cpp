// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


//User function Template for C++


/**
 *  ith value in adj vector contains information between the node connected to it and weight between them.
 *  Example. for a value 2 3 1, Node 2 and Node 3 has weight 1. adj[2] = {3,1} and adj[3] = {2,1}.
 *  n -> number of nodes
 *  m -> total number of edges
 *  return the mst value
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

bool comparator(pair<pair<int,int>,long long int> A,pair<pair<int,int>,long long int> B)
{
    return A.second<B.second;
}

long long int kruskalDSU(vector<pair<int, long long int>> adj[], int n, int m) {
       
       long long result = 0,count =0;
       int parent[n+1],rank[n+1];
       
       for(int i=0;i<=n;i++)
       {
           parent[i] = i;
           rank[i] = 1;
       }
       
       vector<pair<pair<int,int>,long long int>> edges;
       
       for(int i=1;i<=n;i++)
       for(auto j:adj[i])
       {
           if(i<j.first)
           edges.push_back({{i,j.first},j.second});
       }
       
       sort(edges.begin(),edges.end(),comparator);
       
       for(auto i:edges)
       {
           if(count==m)
           break;
           
           if(find(i.first.first,parent)==find(i.first.second,parent))
           continue;
           
           result += i.second;
           count++;
           unionNodes(i.first.first,i.first.second,parent,rank);
       }
       
       return result;
}

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;

    vector<pair<int, long long int>> adj[100009];

    while(t--) {

        int n,m;
        cin>>n>>m;

        int u,v;
        long long w;
        for(int i=0; i<m; i++) {
            cin>>u>>v>>w;
            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
        }

        cout<<kruskalDSU(adj, n, m)<<endl;

        for(int i=0; i<=n; i++) {
            adj[i].clear();
        }
    }
    return 0;
}
  // } Driver Code Ends
