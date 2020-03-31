// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to find the maximum difference of j-i
// arr[]: input array
// n: size of array
int maxIndexDiff(int arr[], int n) 
{ 
    // Your code here
    int rmax[n];
    rmax[n-1]=arr[n-1];
    
    for(int i=n-2;i>=0;i--)
    rmax[i]=max(rmax[i+1],arr[i]);
    
    int x=0,y=0,max=0;
    
    while(x<n && y<n)
    {
        if(arr[x]<=rmax[y])
        {   
            y++;
            if((y-x)>max)
            max=y-x;
        }
        else
        x++;
    }
    
    return max-1;
}

// { Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    cin>>T;
    while(T--){
        int num;
        cin>>num;
        int arr[num];
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        
        if(num ==1 ){
            cout<<0<<endl;
            continue;
        }
        cout<<maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
}   // } Driver Code Ends
