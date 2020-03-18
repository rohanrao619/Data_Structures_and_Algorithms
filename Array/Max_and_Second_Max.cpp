// { Driver Code Starts
//Initial Template for C++

// CPP code to find largest and 
// second largest element in the array

#include <bits/stdc++.h>
using namespace std;

void largestAndSecondLargest(int, int[]);


 // } Driver Code Ends
     

/* Function to find largest and second largest element
*sizeOfArray : number of elements in the array
* arr = input array
*/
void largestAndSecondLargest(int sizeOfArray, int arr[]){
    int max = -1, max2= -1;
    
    /*********************************
     * Your code here
     * This function should print 
     * max and second max
     * *******************************/
     
     for(int i=0;i<sizeOfArray;i++)
     {
         if(arr[i]>max)
         {
             max2=max;
             max=arr[i];
         }
         
         else if(arr[i]>max2 && arr[i]!=max)
         max2= arr[i];
     }
     
     cout << max << " " << max2 << endl;
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
	    
	    largestAndSecondLargest(sizeOfArray, arr);
	}
	
	return 0;
}  // } Driver Code Ends
