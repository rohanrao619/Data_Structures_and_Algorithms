#include<bits/stdc++.h>
using namespace std;
int max(int a,int b)
{
    if(a>b)
    return a;
    else
    return b;
}

int min(int a,int b)
{
    if(a<b)
    return a;
    else
    return b;
}

int main()
 {
	int T;
	cin>>T;
	while(T--)
	{
	    int n1,n2;
	    cin>>n1>>n2;
	    
	    int a[n1>n2?n2:n1];
	    int b[n1>n2?n1:n2];
	    
	    if(n1<=n2)
	    { 
	        for(int i=0;i<n1;i++)
	        cin>>a[i];
	        for(int j=0;j<n2;j++)
	        cin>>b[j];
	        
	    }
	    else
	    {
	        swap(n1,n2);
	        for(int i=0;i<n2;i++)
	        cin>>b[i];
	        for(int j=0;j<n1;j++)
	        cin>>a[j];
	    }
	   
	    int i1,i2,low=0,high=n1;
	    
	    while(low<=high)
	    {
	        i1=low+((high-low)/2);
	        i2=floor((n1+n2+1)/2)-i1;
	        
	        int max1 = (i1==0)?INT_MIN:a[i1-1];
	        int min1 = (i1==n1)?INT_MAX:a[i1];
	        
	        int max2 = (i2==0)?INT_MIN:b[i2-1];
	        int min2 = (i2==n2)?INT_MAX:b[i2];
	        
	        if(max1<=min2 && max2<=min1)
	        {
	            if((n1+n2)%2==0)
	            cout<<floor((max(max1,max2)+min(min1,min2))/2)<<endl;
	            else
	            cout<<max(max1,max2)<<endl;
	            break;
	        }
	        
	        if(max1>min2)
	        high=i1-1;
	        else
	        low=i1+1;
	        
	    }
	}
	
	return 0;
}
