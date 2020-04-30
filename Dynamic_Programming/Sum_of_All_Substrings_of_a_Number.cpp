// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

long long sumSubstrings(string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        cout << sumSubstrings(s) << endl;
        
    }
    return 0;
}
// } Driver Code Ends
// function to find sum of all possible substrings of the given string
long long sumSubstrings(string s){
    
    // your code here
    int n = s.length();
    
    long long DP[n];
    DP[0] = int(s[0])-48;
    
    long long sum = DP[0];
    
    for(int i=1;i<n;i++)
    {
        DP[i] = (10*DP[i-1] + (i+1)*(int(s[i])-48))%1000000007;
        sum = (sum + DP[i])%1000000007;
    }
    
    return sum;
}

