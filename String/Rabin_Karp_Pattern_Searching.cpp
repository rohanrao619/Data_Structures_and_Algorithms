// { Driver Code Starts
//Initial Template for C++

/* Following program is a C implementation of 
Rabin Karp. Algorithm given in the CLRS book */
#include<bits/stdc++.h>

using namespace std;

bool search(string, string, int);


 // } Driver Code Ends
//User function Template for C++

// d is the number of characters in the input alphabet 
#define d 256 

/* pat -> pattern 
	txt -> text 
	q -> A prime number 
*/
bool search(string pat, string txt, int q) 
{ 
	// Your code here
	int i=0,j=0;
	int n = txt.length();
	int m = pat.length();
	
	int pat_hash = 0,window_hash=0;
	int h=pow(d,m-1);
	
	h=h%q;
	
	while(i<m)
	{
	    pat_hash+=(int(pat[i])*int(pow(d,m-1-i)));
	    window_hash+=(int(txt[i])*int(pow(d,m-1-i)));
	    i++;
	}
	
	pat_hash=pat_hash%q;
	window_hash=window_hash%q;
	
	i=0;
	
// 	cout<<pat_hash<<endl;
	
	while(i<(n-m+1))
	{
	    if(pat_hash==window_hash)
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
	    }
	   // cout<<window_hash<<endl;
	    
	    i++;
	    if((i+m)<=n)
	    window_hash = (d*(window_hash-(h*txt[i-1]))+txt[i+m-1])%q;
	    
	    if(window_hash<0)
	    window_hash=q+window_hash;
	}
	
	return 0;
} 

// { Driver Code Starts.

/* Driver program to test above function */
int main() 
{ 
    int t;
    cin >> t;
    
    while(t--){
	    string s, p;
	    cin >> s >> p;
	    int q = 101; // A prime number 
	    if(search(p, s, q)) cout << "Yes" << endl;
	    else cout << "No" << endl;
    }
	return 0; 
} 
  // } Driver Code Ends
