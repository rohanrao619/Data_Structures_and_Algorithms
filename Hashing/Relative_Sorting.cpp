#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    unordered_map<int,int> map;
	    int n,m,x;
	    cin>>n>>m;
	    int arr1[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr1[i];
	        map[arr1[i]]++;
	    }
	    for(int i=0;i<m;i++)
	    {
	        cin>>x;
	        if(map.count(x)==1)
	        {
	            while(map[x]!=0)
	            {
	                cout<<x<<" ";
	                map[x]--;
	            }
	        }
	    }
	    
	    sort(arr1,arr1+n);
	    for(int i=0;i<n;i++)
	    {
	        while(map[arr1[i]]!=0)
	        {
	            cout<<arr1[i]<<" ";
	            map[arr1[i]]--;
	        }
	    }
	    
	    cout<<endl;   
	    
	}
	return 0;
}
