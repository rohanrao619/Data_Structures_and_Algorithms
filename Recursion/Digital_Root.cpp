// { Driver Code Starts
//Initial Template for C++


#include <iostream>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

int sumDigits(int n)
{
    if(n==0)
    return 0;
    
    return n%10+sumDigits(n/10);
}

//Complete this function
int digitalRoot(int n)
{
    //Your code here
    if(n<10)
    return n;
    
    return digitalRoot(sumDigits(n));
}

// { Driver Code Starts.


int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    int n;
	    cin>>n;
	    
	    cout<<digitalRoot(n)<<endl;
	    
	    
	}
	return 0;
}  // } Driver Code Ends
