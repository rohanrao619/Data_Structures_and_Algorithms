// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
// Function to find element in sorted array
int leftIndex(int sizeOfArray, int arr[], int elementToSearch){
    
    // Your code here

    int low=0,high=sizeOfArray-1,mid;
    
    while(low<=high)
    {
        
        mid=low+((high-low)/2);
        
        if((arr[mid]==elementToSearch)&&(arr[mid-1]!=elementToSearch))
        return mid;
        
        if(arr[mid]<elementToSearch)
        low=mid+1;
        else
        high=mid-1;
        
    }
    
    return -1;
    
    
}




// { Driver Code Starts.

// Driver Code
int main() {
	
	// Testcase input
	int testcases;
	cin >> testcases;
    
    // Looping through all testcases
	while(testcases--){
	    int sizeOfArray;
	    cin >> sizeOfArray;
	    
	    int arr[sizeOfArray];
	    
	    // Array input
	    for(int index = 0; index < sizeOfArray; index++){
	        cin >> arr[index];
	    }
	    
	    int elemntToSearch;
	    cin >> elemntToSearch;
	    
	    cout << leftIndex(sizeOfArray, arr, elemntToSearch) << endl;
	}
	
	return 0;
}  // } Driver Code Ends
