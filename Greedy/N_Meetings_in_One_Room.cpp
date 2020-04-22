// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
 
bool comparator(pair<int,int> A,pair<int,int> B)
{
    return A.first<B.first;
}

void maxMeetings(int start[], int end[], int n){
    // Your code here
    
    pair<int,int> arr[n];
    
    for(int i=0;i<n;i++)
    arr[i] = {end[i],i};
    
    sort(arr,arr+n,comparator);
    
    int end_time = arr[0].first;
    cout<<arr[0].second+1<<" ";
    
    for(int i=1;i<n;i++)
    {
        if(start[arr[i].second]>=end_time)
        {
            cout<<arr[i].second+1<<" ";
            end_time = arr[i].first;
        }
    }
    
}

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int start[n],end[n];
	    for(int i=0;i<n;i++)
	        cin>>start[i];
	    
	    for(int i=0;i<n;i++)
	        cin>>end[i];
	    
	    maxMeetings(start, end, n);
	    cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends
