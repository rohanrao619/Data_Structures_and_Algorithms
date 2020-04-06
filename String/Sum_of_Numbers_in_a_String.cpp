// { Driver Code Starts
// C++ program to calculate sum of all numbers present
// in a string containing alphanumeric characters
#include <iostream>
using namespace std;


 // } Driver Code Ends

// Function to calculate sum of all numbers present
// in a string containing alphanumeric characters
int findSum(string str)
{
	
	// Your code here
	int sum=0,d=1;
	
	for(auto i=str.rbegin();i<str.rend();i++)
	if(!isalpha(*i))
	{
	    sum+=(d*((*i)-48));
	    d*=10;
	}
	else
	d=1;
	
	return sum;
	
}

// { Driver Code Starts.

// Driver code
int main()
{
	// input alphanumeric string
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    cout << findSum(str);
        cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends
