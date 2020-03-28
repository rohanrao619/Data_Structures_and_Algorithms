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
	    int n,x,i;
	    cin>>n;
	    
	    for(i=0;i<n;i++)
	    {
	        cin>>x;
	        m[x]++;
	    }
	    
	    for(i=0;i<n;i++)
	    {
	        cin>>x;
	        m[x]--;
	        if(m[x]<1)
	        {
	            m.erase(x);
	        }
	    }
	    
	    cout<<m.empty()<<endl;
	    m.clear();
	}
	return 0;
}
