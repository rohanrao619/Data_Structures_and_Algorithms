// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

// Function to check if Kth bit is set or not
bool checkKthBit(int n, int k){
    
    // Your code here
    // It can be a one liner logic!! Think of it!!
    
    return (n&(1<<k))!=0;
    
}

// { Driver Code Starts.

// Driver Code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    long long n;
	    cin>>n;
	    int k;
	    cin>>k;
	    
	    if(checkKthBit(n, k))
	        cout << "Yes" << endl;
	    else
	        cout << "No" << endl;
	}
	return 0;
}  // } Driver Code Ends
