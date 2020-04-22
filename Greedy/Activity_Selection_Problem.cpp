// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

bool comparator(pair<int,int> A,pair<int,int> B)
{
    return A.first<B.first;
}

int activitySelection(int start[], int end[], int n){
    // Your code here
    
    pair<int,int> arr[n];
    
    for(int i=0;i<n;i++)
    arr[i] = {end[i],i};
    
    sort(arr,arr+n,comparator);
    
    int count = 1,end_time = arr[0].first;
    
    for(int i=1;i<n;i++)
    {
        if(start[arr[i].second]>=end_time)
        {
            count++;
            end_time = arr[i].first;
        }
    }
    
    return count;
}

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int start[n], end[n];
        
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        
        cout << activitySelection(start, end, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
