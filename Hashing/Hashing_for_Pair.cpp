// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

int sumExists(int arr[], int sizeOfArray, int sum);

 // } Driver Code Ends
//User function Template for C++


//You need to complete this function, Geeks
int sumExists(int arr[], int sizeOfArray, int sum)
{
   //Your code here.
   unordered_set<int> s;
   for(int i=0;i<sizeOfArray;i++)
   {
       if(s.count(sum-arr[i])==1)
       return 1;
       else
       s.insert(arr[i]);
   }
   
   return 0;
}


// { Driver Code Starts.

int main() {
    
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        int sizeOfArray;
        cin>>sizeOfArray;
        
        int arr[sizeOfArray];
        
        for(int i=0;i<sizeOfArray;i++)
        cin>>arr[i];
        int sum;
        cin>>sum;
        
        cout<<sumExists(arr,sizeOfArray,sum)<<endl;
        
        
    }
    
    
    
	return 0;
}
  // } Driver Code Ends
