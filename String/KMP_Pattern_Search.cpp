// { Driver Code Starts
//Initial Template for C++

// C++ program for implementation of KMP pattern searching 
// algorithm 
#include <bits/stdc++.h> 

using namespace std;


 // } Driver Code Ends
//User function Template for C++

// Fills lps[] for given patttern pat[0..M-1] 
void computeLPSArray(string pat, int M, int* lps) 
{ 
	// Your code here
	int len=0,i=1;
	
	lps[0]=0;
	
	while(i<M)
	{
	    if(pat[len]==pat[i])
	    {
	        len++;
	        lps[i]=len;
	        i++;
	    }
	    else if(len==0)
	    {
	        lps[i]=0;
	        i++;
	    }
	    else
	    {
	        len=lps[len-1];
	    }
	}
} 

// Returns true if pat found in txt
bool KMPSearch(string pat, string txt) {
    // Your code here
    int i=0,j=0,m=pat.length(),n=txt.length();
    
    int lps[m];
    computeLPSArray(pat,m,lps);
    
    while(i<n)
    {
        if(txt[i]==pat[j])
        {
            i++;
            j++;
            
            if(j==m)
            return 1;
        }
        else
        {
            if(j==0||lps[j]==0)
            {
                j=0;
                i++;
            }
            else
            j=lps[j-1];
        }
        
    }
    
    return 0;
    
}

// { Driver Code Starts.

// Driver program to test above function 
int main() 
{ 
    int t;
    std::cin >> t;
    
    while(t--){
        string s, pat;
        cin >> s >> pat;
        if(KMPSearch(pat, s)){
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }
    
	return 0;
} 
  // } Driver Code Ends
