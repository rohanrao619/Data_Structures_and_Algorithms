// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
void nearlySorted(int arr[], int num, int K){
    // Your code here
    priority_queue<int,vector<int>,greater<int>> PQ(arr,arr+K);
    
    for(int i=K;i<num;i++)
    {
        if(arr[i]<=PQ.top())
        cout<<arr[i]<<" ";
        else
        {
            cout<<PQ.top()<<" ";
            PQ.pop();
            PQ.push(arr[i]);
        }
    }
    
    while(!PQ.empty())
    {
        cout<<PQ.top()<<" ";
        PQ.pop();
    }
}

// { Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    
	    nearlySorted(arr, num, K);
	    cout<<endl;
	}
	
	return 0;
}
  // } Driver Code Ends
