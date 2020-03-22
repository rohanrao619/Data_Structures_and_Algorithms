// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to find the minimum element in sorted and rotated array
// arr: input array
// low and high are 0 and n-1, where n is the size of arr
int minNumber(int arr[], int low, int high)
{
    // Your code here
    if(arr[low]<arr[high])
    return arr[low];
    
    int mid = low+((high-low)/2);
    
    if(arr[mid]>arr[mid+1])
    return arr[mid+1];
    
    if(arr[mid]<arr[mid-1])
    return arr[mid];
    
    if(arr[mid]>arr[low])
    return minNumber(arr,mid+1,high);
    else
    return minNumber(arr,low,mid-1);
    
}

// { Driver Code Starts.


int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];		
		cout << minNumber(a,0,n-1) << endl;
	}
	return 0;
}  // } Driver Code Ends
