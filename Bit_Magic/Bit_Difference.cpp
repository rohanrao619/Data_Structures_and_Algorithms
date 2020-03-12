// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

// Function to find number of bits to be flip
// to convert A to B
int countBitsFlip(int a, int b){
    
    // Your logic here
    int num = a^b,count=0;
    
    while(num!=0)
    {
        num=num&(num-1);
        count++;
    }
    
    return count;
}

// { Driver Code Starts.

// Driver Code
int main()
{
	int t;
	cin>>t;// input the testcases
	while(t--) //while testcases exist
	{
		int a,b;
		cin>>a>>b; //input a and b

		cout<<countBitsFlip(a, b)<<endl;
	}
	return 0;
}  // } Driver Code Ends
