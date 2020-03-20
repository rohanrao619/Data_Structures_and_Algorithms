// { Driver Code Starts
// C++ program to rearrange an array in minimum 
// maximum form 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// This function wants you to modify the given input
// array and no need to return anything
// arr: input array
// n: size of array
void rearrange(int *arr, int n) 
{ 
	int max=arr[n-1]+1;
	// Your code here
	int front=0,back=n-1;
	
	for(int i=0;i<n;i++)
	{
	    if(i%2==0)
	    {
	        arr[i]+=((arr[back]%max)*max);
	        back--;
	    }
	    else
	    {
	        arr[i]+=((arr[front]%max)*max);
	        front++;
	    }
	}
	
	for(int i=0;i<n;i++)
	arr[i]/=max;
}

// { Driver Code Starts.

// Driver program to test above function 
int main() 
{
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        rearrange(arr, n);
        
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
} 
  // } Driver Code Ends
