// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
// Function to find the index of x
// arr[]: input array
// n: size of array
// x: element to find index
int closer(int arr[],int n, int x)
{
    //Your code here
    if(arr[0]==x)
    return 0;
    
    if(arr[n-1]==x)
    return n-1;
    
    int low=1,high=n-2,mid;
    
    while(low<=high)
    {
        mid=low+(high-low)/2;
        if(arr[mid]==x)
        return mid;
        if(arr[mid+1]==x)
        return mid+1;
        if(arr[mid-1]==x)
        return mid-1;
        
        if(x>=arr[mid-1])
        {
            low=mid+1;
            continue;
        }
        else
        {
            high=mid-1;
            continue;
        }
    }
    
    return -1;
}

// { Driver Code Starts.

int main() {
    
    cin.tie(NULL);
    
	int t;
	cin >> t;
	
	while(t--){
	  
	    int n;
	    cin >> n;
	    int arr[n];
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	    }
	    int x;
	    cin >> x;
	    
	    int res = closer(arr,n,x);
	    
	    cout << res << endl;
	}
	
	return 0;
}  // } Driver Code Ends
