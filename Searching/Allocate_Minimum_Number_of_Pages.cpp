#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    long long n,m,a;
	    cin>>n;
	    
	    vector<long long> vec,temp;
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>a;
	        vec.push_back(a);
	        temp.push_back(a);
	    }
	    
	    cin>>m;
	    sort(temp.begin(),temp.end());
	    
	    if(m==n)
	    {
	        cout<<temp[n-1]<<endl; 
	        continue;
	    }
	    
	    if(m>n)
	    {
	        cout<<"-1"<<endl; 
	        continue;
	    }
	    
	    long long start=temp[n-1],end=0,result,minResult;
	    
	    for(int i=m-1;i<n;i++)
	    end += temp[i];
	   
	    while(start<=end)
	    {
	        result  = start + (end - start)/2;
	        
	        long long count = 0;
	        long long sum = 0;
	        
	        for(int i=0;i<n;i++)
	        {
	            if(vec[i]>result)
	            {
	                count = LLONG_MAX;
	                break;
	            }
	            
	            sum+=vec[i];
	            
	            if(sum>result)
	            {   
	                count++;
	                sum = vec[i];
	            }
	        }
	        
	        if(count<m)
	        {   
	            minResult = result;
	            end = result-1;
	        }
	        
	        else
	        start = result+1; 
	    }
	    cout<<minResult<<endl;
	}
	return 0;
}
