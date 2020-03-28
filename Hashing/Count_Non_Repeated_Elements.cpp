// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int countNonRepeated(int arr[], int n);

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    
	    cout<<countNonRepeated(arr,n)<<endl;
	    
	}
	return 0;
}
// } Driver Code Ends
//Complete this function

int countNonRepeated(int arr[], int n)
{
    //Your code here
    int count=0;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    {
        m[arr[i]]++;
    }
    
    for(auto j:m)
    {
        if(j.second==1)
        count++;
    }
    
    return count;
}

