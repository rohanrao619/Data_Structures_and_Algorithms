// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function Template for C++


/* This function does union of 2 nodes a and b */
// a : node 1 
// b : node 2
// par : empty array (n+1) size with all elements as i
// rank1 : empty array (n+1) size with all elements as 1
int find(int a,int par[])
{
    if(par[a]==a)
    return a;
    
    par[a] = find(par[a],par);  // Path Compression
    return par[a];
}

void union_( int a, int b, int par[], int rank1[]) {
    
    int par_a = find(a,par);
    int par_b = find(b,par);
    
    if(par_a!=par_b)
    {
        if(rank1[par_a]>rank1[par_b])
        par[par_b] = par_a;
        else if(rank1[par_a]<rank1[par_b])
        par[par_a] = par_b;
        else
        {
            par[par_b] = par_a;
            rank1[par_a]++;
        }
    }
    
}

/* This function checks whether 2 nodes x and y are connected or not */
// x : node 1 
// y : node 2
// par : empty array (n+1) size with all elements as i
// rank1 : empty array (n+1) size with all elements as 1
bool isConnected(int x,int y, int par[], int rank1[]) {
    
    return find(x,par)==find(y,par);
}

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        
        int par[n+1];
        int rank1[n+1];

        for(int i=1; i<=n; i++) {
            par[i] = i;
            rank1[i] = 1;
    }
    
    int q;
    cin>>q;
    while(q--) {
        int a,b;
        char c;
        cin>>c>>a>>b;
        if(c=='U')
        {
            union_(a,b, par, rank1);
        }
        else
        cout<<isConnected(a,b, par, rank1)<<endl;
    }
    }
    return 0;
}
  // } Driver Code Ends
