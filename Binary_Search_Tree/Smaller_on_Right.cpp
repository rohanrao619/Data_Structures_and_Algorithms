#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int T;
	cin>>T;
	
	while(T--)
	{
	    int n;
	    cin>>n;
	    
	    int arr[n],i,maximum=INT_MIN;
	    
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    
	    set<int> s;
	    
	    for(i=n-1;i>=0;i--)
	    {
	        s.insert(arr[i]);
	        
	        int distance=0;
	        
	        auto pos = s.find(arr[i]);
	        
	        for(auto j=s.begin();j!=pos;j++)
	        {   
	            distance++;
	        }
	        
	        maximum = max(maximum,distance);
	    }
	    
	    cout<<maximum<<endl;
	    
	}
	
	return 0;
}
