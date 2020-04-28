// { Driver Code Starts
//Initial Template for C++


// C++ implementation of the approach 
#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++


// Return the maximum water that can be stored 
int maxWater(int height[], int n) 
{ 
    //Your code here
    int low = 0, high = n-1, result = 0;
    
    while(low<high)
    {
        result = max(result,(abs(high-low)-1)*min(height[low],height[high]));
        
        if(height[low]<=height[high])
        low++;
        else
        high--;
    }
    
    return result;
} 




// { Driver Code Starts.

// Driver code 
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int height[n];
        
        for(int i=0;i<n;i++)
        {
            cin>>height[i];
        }
        
        cout<<(maxWater(height, n))<<endl;
    }

	 
} 

  // } Driver Code Ends
