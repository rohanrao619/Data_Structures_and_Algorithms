// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

long long int countSubarrWithEqualZeroAndOne(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	cout<< countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	}
	return 0;
}
// } Driver Code Ends
long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
{
    //Your code here
    for(int i=0;i<n;i++)
    if(arr[i]==0)
    arr[i]=-1;
    
    long long int prefix=0,count=0;
    
    unordered_map<int,int> m;
    
    m[0]=1;
    
    for(int i=0;i<n;i++)
    {
        prefix+=arr[i];
        
        if(m.count(prefix)==1)
        {
            count+=m[prefix];
        }
        
        m[prefix]++;
        
    }
    
    return count;
}
