// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

//Return the index of the character or return -1
int repeatedCharacter (string s) 
{ 
    //Your code here
    int res=INT_MAX;
    
    int hash[256];
    
    for(int i=0;i<256;i++)
    hash[i]=-1;
    
    for(int i=0;i<s.length();i++)
    if(hash[s[i]]==-1)
    hash[s[i]]=i;
    else
    res=min(res,hash[s[i]]);
    
    return (res==INT_MAX?-1:res);
} 

// { Driver Code Starts.


int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    string s;
	    cin>>s;
	    int index = repeatedCharacter(s); 
        if (index == -1) 
            cout<<-1<<endl;
        else
            cout<<s[index]<<endl;
	}
	return 0;
}
  // } Driver Code Ends
