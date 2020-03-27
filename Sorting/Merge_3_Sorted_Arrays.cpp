// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 

typedef vector<int> Vector;

void printVector(const Vector& a) 
{ 
    for (auto e : a) { 
        cout << e << " "; 
    }
    cout<<endl;
} 

 // } Driver Code Ends
// Function to merge three sorted arrays
// A, B, and C: input sorted arrays
Vector mergeThree(Vector& A, Vector& B, Vector& C) 
{ 
    //Your code here
    vector<int> merged;
    int i;
    
    for(i=0;i<A.size();i++)
    merged.push_back(A[i]);
    
    for(i=0;i<B.size();i++)
    merged.push_back(B[i]);
    
    for(i=0;i<C.size();i++)
    merged.push_back(C[i]);
    
    sort(merged.begin(),merged.end());
    
    return merged;
} 


// { Driver Code Starts.

int main() 
{ 


    int t;
    cin>>t;
    while(t--){
    int n,m,o;
    cin>>n>>m>>o;
    Vector A,B,C;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        A.push_back(x);
    }
    
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        B.push_back(x);
    }
    
    for(int i=0;i<o;i++){
        int x;
        cin>>x;
        C.push_back(x);
    }

  
    printVector(mergeThree(A, B, C)); 
    
    }
   
    return 0; 
} 
  // } Driver Code Ends
