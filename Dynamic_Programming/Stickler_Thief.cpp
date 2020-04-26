// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


 // } Driver Code Ends
// Function to return maximum of sum without adjacent elements
ll FindMaxSum(ll arr[], ll n)
{
    // Your code here
    
    ll first = arr[0];
    
    if(n==1)
    return first;
    
    ll second = max(arr[0],arr[1]);
    ll res = second;
    
    for(int i=2;i<n;i++)
    {
        res = max(arr[i]+first,second);
        
        first = second;
        second = res;
    }
    
    return res;
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
		ll a[n];
		for(ll i=0;i<n;++i)
			cin>>a[i];
		cout<<FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends
