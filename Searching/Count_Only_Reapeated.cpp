#include<iostream>
using namespace std;
int main()
 {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    long long n,i;
	    cin>>n;
	    long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    
	    int count=n-(arr[n-1]-arr[0]);
	    
	    long long low=1,high=n-2,mid,ele;
	    
	    while(true)
	    {
	        mid = low+(high-low)/2;
	        if(arr[mid]==arr[mid-1] || arr[mid]==arr[mid+1])
	        {
	            ele=arr[mid];
	            break;
	        }
	        else if((arr[mid]-arr[low])==(mid-low))
	        low=mid+1;
	        else
	        high=mid-1;
	        
	    }
	    
	    cout<<ele<<" "<<count<<endl;   
	}
	return 0;
}
