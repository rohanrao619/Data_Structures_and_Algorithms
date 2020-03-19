// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
// Function to count frequencies of elements in the array
// arr: input array
// n: size of array
void printfrequency(int arr[], int n)
{ 

    int i;
	// Your code here
	for(i=0;i<n;i++)
	arr[i]-=1;
	for(i=0;i<n;i++)
	arr[arr[i]%n]+=n;
	for(i=0;i<n;i++)
	cout<<int(arr[i]/n)<<" ";
	
} 



// { Driver Code Starts.

int main() 
{ 
	long long t;
	cin >> t;
	
	while(t--){
	    
	    int n;
	    cin >> n; // taking input size of array
	    
	    int arr[n];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i]; // input elements of array
	    }
	    
	    printfrequency(arr,n); // print frequency of elements 
	    cout << endl;
	}
	
	return 0; 
}  // } Driver Code Ends
