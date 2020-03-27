// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

long long arr[10000000];


 // } Driver Code Ends

// Please note that the input array is declared globally
// You may expand the driver code above

// Array is declared as: "long long arr[10000000];"
long long findNumberOfTriangles(long long n)
{
    //Your code here
    long long i,count=0,l,r;
    sort(arr,arr+n,greater<long long>());
    for(i=0;i<n-2;i++)
    {
        l=i+1;
        r=n-1;
        while(l<r)
        {
            if((arr[l]+arr[r])>arr[i])
            {
                count+=(r-l);
                l++;
            }
            else
            r--;
        }
    }
    
    return count;
}

// { Driver Code Starts.

int main()
{
    long long size,T;
    
    cin>>T;

    while(T--){
        
    cin>>size;

    for(int i=0;i<size;i++)
     cin>>arr[i];
     
    cout<<findNumberOfTriangles(size ) <<endl;
    }
    return 0;
}


  // } Driver Code Ends
