#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int getMid(int s, int e) {  return s + (e -s)/2;  }

void updateSTree(ll *stree, int start, int end, int i, int diff, int curr)
{
    if (i < start || i > end)
    return;
    
    stree[curr] += diff;
    
    if (end != start)
    {
        int mid = getMid(start, end);
        
        updateSTree(stree, start, mid, i, diff, 2*curr + 1);
        updateSTree(stree, mid+1, end, i, diff, 2*curr + 2);
    }
}

ll getSum(ll *stree, int cs, int ce, int qs, int qe, int curr)
{
    if (qs <= cs && qe >= ce)
    return stree[curr];
    
    if (ce < qs || cs > qe)
    return 0;
    
    int mid = getMid(cs, ce);
    
    return getSum(stree, cs, mid, qs, qe, 2*curr+1) 
           + getSum(stree, mid+1, ce, qs, qe, 2*curr+2);
}

void buildSTree(int *arr, int cs, int ce, ll *stree, int curr)
{
    if (cs == ce)
    {
        stree[curr] = arr[cs];
        return ;
    }
    int mid = getMid(cs, ce);
    
    buildSTree(arr, cs, mid, stree, curr*2+1);
    buildSTree(arr, mid+1, ce, stree, curr*2+2);
    
    stree[curr] = stree[curr*2+1]+stree[curr*2+2];
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
		
		ll *stree = new ll[4*n];
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
		        cout<<getSum(stree, 0, n-1, L, R, 0)<<endl;
		        else
		        cout<<"-1"<<endl;
		    }
		    else
		    {
		        cin>>index>>val;
		        
		        if(index>=0 and index<n)
		        {
		            int difference = val - arr[index];
		            arr[index] = val;
		            
		            updateSTree(stree, 0, n-1, index, difference,0);
		        }
		    }
		}	
	}
	
	return 0;
}
