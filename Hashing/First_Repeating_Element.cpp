#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int T;
	unordered_map<int,int> m;
	cin>>T;
	while(T--)
	{
	    int n,i,res=-1;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	        m[arr[i]]++;
	    }
	    for(int i=0;i<n;i++)
	    {
	        if(m[arr[i]]>1)
	        {
	            res=i+1;
	            break;
	        }
	    }
	    
	    cout<<res<<endl;
	    m.clear();
	}
	return 0;
}
