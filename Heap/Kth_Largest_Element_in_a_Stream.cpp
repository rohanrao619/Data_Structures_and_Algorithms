// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
void kthLargest(int arr[], int n, int k)
{
	// your code here
	priority_queue<int,vector<int>,greater<int>> PQ(arr,arr+k);
	for(int i=0;i<k-1;i++)
	cout<<"-1 ";
	
	cout<<PQ.top()<<" ";
	
	for(int i=k;i<n;i++)
	{
	    if(arr[i]>PQ.top())
	    {
	        PQ.pop();
	        PQ.push(arr[i]);
	    }
	    
	    cout<<PQ.top()<<" ";
	}
	
}

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k, n;
		cin>>k>>n;
	    
	    int arr[n];
	    for(int i = 0; i<n ; ++i)
	        cin>>arr[i];
    
	    kthLargest(arr, n, k);
	    cout<<endl;
	    
	    
	}
	return 0;
}
  // } Driver Code Ends
