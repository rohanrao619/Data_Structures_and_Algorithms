// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

char nonrepeatingCharacter(string S);

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    
        char ans = nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
// Complete this function
char nonrepeatingCharacter(string S)
{
   //Your code here
   int hash[256];
   
   for(int i=0;i<256;++i)
   hash[i]=-1;
   
   for(int i=0;i<S.length();++i)
   {
       if(hash[S[i]]==-1)
       hash[S[i]]=i;
       else if(hash[S[i]]>=0)
       hash[S[i]]=-999;
   }
   int res=INT_MAX;
   
   for(int i=0;i<256;++i)
   if(hash[i]>=0)
   res = min(res,hash[i]);
   
   return (res==INT_MAX?'$':S[res]);
   
}

