// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

int findRank(string S) 
{
    //Your code here
    int res=0,fact=1;
    
    int count[26]={0},l=S.length(),i,j,k;
    
    for(i=1;i<l;i++)
    fact*=i;
    
    for(char c:S)
    {
        count[c-97]++;
        if(count[c-97]>1)
        return 0;
    }
    
    for(i=0;i<l-1;i++)
    {
        k=0;
        for(j=0;j<(S[i]-97);j++)
        k+=count[j];
        
        count[S[i]-97]--;
        
        res+=(k*fact);
        fact/=(l-1-i);
        
    }
    
    return (res+1)%1000000007;
}

// { Driver Code Starts.


int main()
{
    string S;
    int t;
    cin>>t;
    while(t--)
    {
     
        cin>>S;
    cout<<findRank(S)<<endl;
    }
}
  // } Driver Code Ends
