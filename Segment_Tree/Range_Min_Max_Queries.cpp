#include<bits/stdc++.h>
using namespace std;

int getMid(int s, int e) {  return s + (e -s)/2;  }

void updateSTree(pair<int,int> *stree, int start, int end, int i, int val, int curr)
{
    if (i < start || i > end)
    return;
    
    if(end==start)
    {
        stree[curr] = {val,val};
        return;
    }
    
    if (end != start)
    {
        int mid = getMid(start, end);
        
        updateSTree(stree, start, mid, i, val, 2*curr + 1);
        updateSTree(stree, mid+1, end, i, val, 2*curr + 2);
        stree[curr] = {min(stree[2*curr+1].first,stree[2*curr+2].first),
                       max(stree[2*curr+1].second,stree[2*curr+2].second)};
    }
}

pair<int,int> getMinMax(pair<int,int> *stree, int cs, int ce, int qs, int qe, int curr)
{
    if (qs <= cs && qe >= ce)
    return stree[curr];
    
    if (ce < qs || cs > qe)
    return {INT_MAX,INT_MIN};
    
    int mid = getMid(cs, ce);
    
    pair<int,int> left = getMinMax(stree, cs, mid, qs, qe, 2*curr+1);
    pair<int,int> right = getMinMax(stree, mid+1, ce, qs, qe, 2*curr+2);
    
    return {min(left.first,right.first),max(left.second,right.second)};
}

void buildSTree(int *arr, int cs, int ce, pair<int,int> *stree, int curr)
{
    if (cs == ce)
    {
        stree[curr] = {arr[cs],arr[cs]};
        return ;
    }
    
    int mid = getMid(cs, ce);
    
    buildSTree(arr, cs, mid, stree, curr*2+1);
    buildSTree(arr, mid+1, ce, stree, curr*2+2);
    
    stree[curr] = {min(stree[curr*2+1].first,stree[curr*2+2].first),
                   max(stree[curr*2+1].second,stree[curr*2+2].second)};
}

int main(){
	
	int T;
	cin>>T;
	
	while(T--)
	{
		int n, q;
		cin>>n>>q;
		
		int arr[n];
		
		for(int i=0;i<n;i++)
			cin>>arr[i];
		
		pair<int,int> *stree = new pair<int,int>[4*n];
		buildSTree(arr,0,n-1,stree,0);
		
		int L,R,index,val;
		char type;
		
		while(q--)
		{
		    
		    cin.ignore(INT_MAX, '\n');
		    cin>>type;
		    
		    if(type == 'G')
		    {
		        cin>>L>>R;
		        
		        if(L>=0 and R<n and L<=R)
		        {
		            pair<int,int> result = getMinMax(stree, 0, n-1, L, R, 0);
		            cout<<result.first<<" "<<result.second<<endl;
		        }
		        else
		        cout<<"-1"<<endl;
		    }
		    else
		    {
		        cin>>index>>val;
		        
		        if(index>=0 and index<n)
		        {
		            arr[index] = val;
		            updateSTree(stree, 0, n-1, index, val,0);
		        }
		    }
		}	
	}
	
	return 0;
}
