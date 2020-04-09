// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long


 // } Driver Code Ends
// Function to print all binary numbers upto n
void generate(ll n)
{
	// Your code here
	queue<string> q;
	
	q.push("1");
	
	string a,b;
	
	while(n--)
	{
	    cout<<q.front()<<" ";
	    
	    a= q.front()+"0";
	    b= q.front()+"1";
	    
	    q.push(a);
	    q.push(b);
	    
	    q.pop();
	}
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		generate(n);
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends
