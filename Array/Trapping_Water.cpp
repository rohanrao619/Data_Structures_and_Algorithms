// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
   

// function to find the trapped water in between buildings
// arr: input array
// n: size of array

int min(int a,int b)
{
    if(a>b)
    return b;
    else
    return a;
}

int trappingWater(int arr[], int n){

    // Your code here
    int left[n],right[n],i,lmax=arr[0],rmax=arr[n-1],sum=0;
    
    for(i=0;i<n;i++)
    {
        if(arr[i]>lmax)
        {
            left[i]=arr[i];
            lmax = arr[i];
        }
        else
        left[i]=lmax;
    }
    
    for(i=n-1;i>0;i--)
    {
        if(arr[i]>rmax)
        {
            right[i]=arr[i];
            rmax = arr[i];
        }
        else
        right[i]=rmax;
    }
    
    for(i=1;i<n-1;i++)
    {
        sum+= min(left[i],right[i])-arr[i];
    }
    
    return sum;
}

// { Driver Code Starts.

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        
        cin >> n;
        
        int a[n];
        
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        
        cout << trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends
