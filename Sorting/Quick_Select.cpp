#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    int n,x,i,j;
	    cin>>n;
	    int arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    cin>>x;
	    
	    int low=0,high=n-1,key;
	    
	    while(low<=high)
	    {
	        j=low-1;
	        for(i=low;i<high;i++)
	        {
	            if(arr[i]<=arr[high])
	            swap(arr[++j],arr[i]);
	        }
	        
	        swap(arr[++j],arr[high]);
	        
	        if(j==(x-1))
	        {
	            key=arr[j];
	            break;
	        }
	        else if(j>(x-1))
	        high=j-1;
	        else
	        low=j+1;
	    }
	    
	    cout<<key<<endl;
	}
	return 0;
}
