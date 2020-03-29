// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int subArraySum(int arr[], int n, int sum);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,sum=0;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    cin>>sum;
	    cout<<subArraySum(arr, n, sum)<<endl;
	}
	return 0;
}// } Driver Code Ends

int subArraySum(int arr[], int n, int sum)
{
    //Your code here
    int prefix=0,count=0;
    
    unordered_map<int,int> m;
    
    m[0]=1;
    
    for(int i=0;i<n;i++)
    {
        prefix+=arr[i];
        
        if(m.count(prefix-sum)==1)
        {
            count+=m[prefix-sum];
        }
        
        m[prefix]++;
        
    }
    
    return count;
}
