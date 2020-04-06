// { Driver Code Starts
// C++ program for Naive Pattern 
// Searching algorithm 
#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
/*  function to search for a pattern with distinct characters
*   pat: pattern(to be searched in txt) given in the input
*   txt: string given in the input
*/
bool search(string pat, string txt) 
{ 
	
	// Your code here
	int i=0,j;
	int n = txt.length();
	int m = pat.length();
	while(i<(n-m+1))
	{
	    j=0;
	    while(j<m)
	    {
	        if(txt[i+j]!=pat[j])
	        break;
	        
	        j++;
	        
	        if(j==m)
	        return 1;
   
	    }
	    if(j==0)
	    i++;
	    else
	    i+=j;
	}
	
	return 0;
	
} 

// { Driver Code Starts.

// Driver Code 
int main() 
{ 
	
	int t;
	cin >> t;
	
	while(t--){
	    string s, p;
	    cin >> s >> p;
	    if(search(p, s)) cout << "Yes"; else cout << "No"; cout << endl;
	}
	
	return 0; 
}  // } Driver Code Ends
