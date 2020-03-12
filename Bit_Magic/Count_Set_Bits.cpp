// { Driver Code Starts
//Initial Template for C++

#include<iostream>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

// Function to count set bits in the given number x
// n: input to count the number of set bits
int countSetBits(int n){
    
    // Your logic here
    int count=0,k;
    
    for (int i=1;i<=n;i++)
    {
        k = i;
        while(k!=0)
        {   
            count++;
            k= k&(k-1);    
        }
    }
    
    return count;
    
}

// { Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       
	       cout << countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}  // } Driver Code Ends
