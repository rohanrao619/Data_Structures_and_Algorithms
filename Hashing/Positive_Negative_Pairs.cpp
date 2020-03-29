#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int T;
	unordered_set<int> s;
	set<int> s1;
	cin>>T;
	while(T--)
	{
	    int n,x;
	    cin>>n;
	    for(int i=0;i<n;i++)
	    {
	        cin>>x;
	        if(s.count(-x)==1)
	        s1.insert(abs(x));
	        else
	        s.insert(x);
	    }
	    
	    if(s1.size()==0)
	    {
	        cout<<0<<endl;
	    }
	    else
	    for(auto i:s1)
	    {
	        cout<<i<<" "<<-i<<" ";
	        cout<<endl;
	    }
	    
	    s.clear();
	    s1.clear();
	}
	return 0;
 }	
