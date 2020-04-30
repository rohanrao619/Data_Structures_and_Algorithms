// { Driver Code Starts
// A Dynamic Programming based solution to compute nCr % p 
#include<bits/stdc++.h> 
using namespace std; 

const int p = 1e9+7;

int nCrModp(int, int);

// Driver program 
int main() 
{ 
  int t, n, r;
  cin >> t;
  
  while(t--){
      cin >> n >> r;
      cout << nCrModp(n, r) << endl;
  }
  
  return 0; 
}
// } Driver Code Ends
// Returns nCr % p

int nCrModp(int n, int r) 
{
    int DP[r][n];
    
    if(r>n)
    return 0;
    
    for(int i=0;i<n;i++)
    DP[0][i] = i+1;
    
    for(int i=1;i<r;i++)
    DP[i][i]=1;
    
    for(int i=1;i<r;i++)
    for(int j=i+1;j<n;j++)
    DP[i][j] = (DP[i-1][j-1]+DP[i][j-1])%p;
        
    return DP[r-1][n-1];
} 

