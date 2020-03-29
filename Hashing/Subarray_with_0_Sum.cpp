// { Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;


bool subArrayExists(int arr[], int n);
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    	if (subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}// } Driver Code Ends
//Complete this function
bool subArrayExists(int arr[], int n)
{
    //Your code here
    for(int i=1;i<n;i++)
    {
        arr[i]+=arr[i-1];
        if(arr[i]==0)
        return 1;
    }
    unordered_set<int> s;
    
    for(int j=0;j<n;j++)
    {
        if(s.count(arr[j])==1)
        return 1;
        else
        s.insert(arr[j]);
    }
    
    return 0;
}



