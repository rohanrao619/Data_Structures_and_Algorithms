// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to find circular subarray with maximum sum
// arr: input array
// num: size of array
int maxSubarraySum(int arr[], int n){
    
    // Your code here
    int sum=arr[0],max=arr[0];
    
    for(int i=1;i<n;i++)
    {
        if((sum+arr[i])>arr[i])
        {
            sum+=arr[i];
        }
        else
        {
            sum=arr[i];
        }
        
        if(sum>max)
        max=sum;
            
    }
    return max;
}

int circularSubarraySum(int arr[], int num){
    
    // your code here
    int maxSum = maxSubarraySum(arr,num),sum=0;
    for(int i=0;i<num;i++)
    {   
        sum+=arr[i];
        arr[i]*=-1;
    }
    
    int circularMaxSum = sum + maxSubarraySum(arr,num);
    
    if(maxSum<0)
    return maxSum;
    return (maxSum>circularMaxSum)?maxSum:circularMaxSum;
    
}

// { Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num;
	    cin>>num;
	    int arr[num];
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	    
	    
	    cout << circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
