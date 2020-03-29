#include<bits/stdc++.h>
using namespace std;

int comparator(pair<int,int> a,pair<int,int> b)
{
    if(a.second==b.second)
    return a.first<b.first;
    return a.second>b.second;
}

int main()
 {
	//code
	unordered_map<int,int> map;
	int T;
	cin>>T;
	while(T--)
	{
	    int n,m,x;
	    cin>>n;
	    int arr1[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr1[i];
	        map[arr1[i]]++;
	    }
	    
	    vector<pair<int,int>> vec;
	    
	    for(int i=0;i<n;i++)
	    {
	        vec.push_back({arr1[i],map[arr1[i]]});
	    }
	    
	    
	    sort(vec.begin(),vec.end(),comparator);
	    
	    for(int i=0;i<vec.size();i++)
	    {
	        cout<<vec[i].first<<" ";
	    }
	    
	    cout<<endl; 
	    map.clear();
	    vec.clear();
	    
	}
	return 0;
}
