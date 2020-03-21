// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to find majority element in the array
// a: input array
// size: size of input array
int majorityElement(int a[], int size)
{
    int i,count=1,majority=a[0];   
    // your code here
    for(i=1;i<size;i++)
    {
        if(a[i]==majority)
        count++;
        else
        count--;
        
        if(count==0)
        {
            count=1;
            majority=a[i];
        }
    }
    count=0;
    
    for(i=0;i<size;i++)
    {
        if(a[i]==majority)
        count++;
    }
    if(count>(size/2))
    return majority;
    else
    return -1;
    
}

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        cout << majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends
