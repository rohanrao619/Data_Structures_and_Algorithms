// { Driver Code Starts

// C++ implementation to find the character in first 
// string that is present at minimum index in second
// string
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
void printMinIndexChar(string str, string patt)
{
    // Your code here
    unordered_set<char> set;
    
    for(char x:patt)
    set.insert(x);
    
    for(char x:str)
    if(set.count(x)==1)
    {
        cout<<x;
        return;
    }
    
    cout<<"No character present";
}

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    string patt;
	    cin>>str;
	    cin>>patt;
	    printMinIndexChar(str, patt);
	    cout<<endl;
	}return 0;
}
  // } Driver Code Ends
