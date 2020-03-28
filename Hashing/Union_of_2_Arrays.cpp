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
	    int n,m,x,i;
	    cin>>n>>m;
	    
	    for(i=0;i<(m+n);i++)
	    {
	        cin>>x;
	        s.insert(x);
	    }
	    
	    cout<<s.size()<<endl;
	    s.clear();
	}
	return 0;
}
