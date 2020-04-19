// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
void kLargest(int arr[], int n, int k){
    // your code here
    priority_queue<int,vector<int>,greater<int>> PQ;
    int i=0;
    string res="";
    
    for(i;i<k;i++)
    PQ.push(arr[i]);
    
    for(i;i<n;i++)
    if(arr[i]>PQ.top())
    {
        PQ.pop();
        PQ.push(arr[i]);
    }
    
    for(i=0;i<k;i++)
    {
        res = to_string(PQ.top())+" "+res;
        PQ.pop();
    }
    
    cout<<res<<endl;
}

// { Driver Code Starts.
void kLargest(int arr[], int n, int k);

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        int arr[n];
        for(int i = 0; i < n;i++)
            cin>>arr[i];
        
        kLargest(arr, n, k);
        
    }
    return 0;
}  // } Driver Code Ends
