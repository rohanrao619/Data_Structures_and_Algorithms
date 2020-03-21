// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

long long int floorSqrt(long long int x);
  

 // } Driver Code Ends
// Function to find square root
// x: element to find square root
long long int floorSqrt(long long int x) 
{
    // Your code goes here   
    long long low=1,high=x,mid;
    
    while(low<=high)
    {
        mid=low+((high-low)/2);
        
        if((mid*mid)==x)
        return mid;
        
        ((mid*mid)<x)?(low=mid+1):(high=mid-1);
    }
    
    return floor(sqrt(x));
}

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		cout << floorSqrt(n) << endl;
	}
    return 0;   
}
  // } Driver Code Ends
