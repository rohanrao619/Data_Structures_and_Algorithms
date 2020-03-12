// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

/*  function to find position of first set 
    bit in the given number
 * n: given input for which we want to get
      the position of first set bit
 */
unsigned int getFirstSetBit(int n){
    
    // Your code here
    if(n==0)
    return 0;
    
    int pos=1;
    
    while((n&(1<<(pos-1)))==0)
    {
        n>>1;
        pos++;
    }
    
    return pos;
}

// { Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin>>t; // testcases
    while(t--)
    {
        int n;
        cin>>n; //input n
        printf("%u\n", getFirstSetBit(n)); // function to get answer
    }
	return 0;
}
  // } Driver Code Ends
