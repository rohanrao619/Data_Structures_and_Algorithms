// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>

using namespace std;

int arr[100001];
int rank1[100001];


 // } Driver Code Ends


//User function Template for C++


/* This function does union of 2 nodes a and b */
// a : node 1 
// b : node 2
// arr : array (n+1) size with elements from 1 to N equal to its index.
// rank1 : array (n+1) size with all elements equal to 1. 
// n : Number of nodes
int find(int a,int par[])
{
    if(par[a]==a)
    return a;
    
    par[a] = find(par[a],par);  // Path Compression
    return par[a];
}

void unionNodes( int a, int b, int arr[], int rank1[], int n) {
    
    int par_a = find(a,arr);
    int par_b = find(b,arr);
    
    if(par_a!=par_b)
    {
        if(rank1[par_a]>rank1[par_b])
        arr[par_b] = par_a;
        else if(rank1[par_a]<rank1[par_b])
        arr[par_a] = par_b;
        else
        {
            arr[par_b] = par_a;
            rank1[par_a]++;
        }
    }
}

/* This function returns number of connected components */
// arr : array (n+1) size with elements from 1 to N equal to its index.
// rank1 : array (n+1) size with all elements equal to 1. 
// n : Number of nodes
int findNumberOfConnectedNodes( int n, int arr[], int rank1[]) {
    
    int count=0;
    
    for(int i=1;i<=n;i++)
    {
        if(arr[i]==i)
        count++;
    }
    
    return count;
}

// { Driver Code Starts.



int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        for(int i=1; i<=n; i++) {
            arr[i] = i;
            rank1[i] = 1;
        }

        int q;
        cin>>q;
        while(q--) {
            int a,b;
            cin>>a>>b;
            unionNodes(a,b, arr, rank1, n);
        }

        cout<<findNumberOfConnectedNodes(n, arr, rank1)<<endl;
    }
    return 0;
}  // } Driver Code Ends
