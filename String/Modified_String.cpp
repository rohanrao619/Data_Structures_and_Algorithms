// { Driver Code Starts
#include<bits/stdc++.h>
#define br char xx; cin>>xx; cout<<xx<<endl;
#define lli long long int
using namespace std;


 // } Driver Code Ends

int modified (string a){
    // Your code here
    
    int count=0,res=0;
    
    for(int i=1;i<a.length();i++)
    if(a[i]==a[i-1])
    count++;
    else
    {
        res+=ceil(count/2);
        count=0;
    }
    
    res+=ceil(count/2);
    
    return res;
}

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    string a;
    while(t--){
        cin>>a;
        cout<<modified(a)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
