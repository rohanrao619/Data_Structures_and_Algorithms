// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// This function rotate array by D elements
// arr: input elements
// n: size of the array
void rotateArr(int arr[], int d, int n){
    
   // Your code here
   reverse(arr,arr+d);
   reverse(arr+d,arr+n);
   reverse(arr,arr+n);
    
}



// { Driver Code Starts.

int main() {
	//code
	
	int t;
	cin >> t;
	
	while(t--){
	    int n, d;
	    cin >> n >> d;
	    
	    int arr[n];
	    
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    
	    rotateArr(arr, d,n);
	    
	    for(int i =0;i<n;i++){
	        cout << arr[i] << " ";
	    }
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
