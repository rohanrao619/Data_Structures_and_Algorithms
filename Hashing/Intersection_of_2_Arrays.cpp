#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int T;
	unordered_set<int> s;
	cin>>T;
	while(T--)
	{
	    int n,m,count=0,x,i;
	    cin>>n>>m;
	    
	    for(i=0;i<n;i++)
	    {
	        cin>>x;
	        s.insert(x);
	    }
	    
	    for(i=0;i<m;i++)
	    {
	        cin>>x;
	        if(s.count(x)==1)
	        {
	            count++;
	            s.erase(x);
	        }
	    }
	    
	    cout<<count<<endl;
	    s.clear();
	}
	return 0;
}
