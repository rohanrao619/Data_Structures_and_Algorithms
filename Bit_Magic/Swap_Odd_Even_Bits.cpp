// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

// function to swap odd and even bits
unsigned int swapBits(unsigned int n)
{
	
	// Your code here
	return ((n&(0b10101010))>>1)|((n&(0b01010101))<<1);
	
}

// { Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		unsigned int n;
		cin>>n;
		cout << swapBits(n) << endl;
	}
	return 0;
}  // } Driver Code Ends
