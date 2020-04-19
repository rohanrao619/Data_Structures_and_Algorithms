// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
// Function to print the k numbers with most occurrences 
int print_N_mostFrequentNumber(int arr[],int n, int k) 
{ 
	// Your code here	 
	unordered_map<int,int> m;
	priority_queue<int,vector<int>,greater<int>> PQ;
	int sum=0;
	
	for(int i=0;i<n;i++)
	m[arr[i]]++;
	
	for(auto i:m)
	{
	    if(PQ.size()<k)
	    PQ.push(i.second);
	    
	    else if(PQ.top()<i.second)
	    {
	        PQ.pop();
	        PQ.push(i.second);
	    }
	}
	
	while(!PQ.empty())
	{
	    sum+=PQ.top();
	    PQ.pop();
	}
	return sum;
} 

// { Driver Code Starts.
// Driver program to test above 
int main() 
{
	int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n;
        int arr[n];
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        cin >> k;
        cout << print_N_mostFrequentNumber(arr, n, k) << endl; 
    }

	return 0; 
} 
  // } Driver Code Ends
