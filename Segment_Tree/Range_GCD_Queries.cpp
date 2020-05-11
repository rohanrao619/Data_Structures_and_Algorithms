#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int getMid(int s, int e) {  return s + (e -s)/2;}

ll GCD(ll a,ll b)
{
    if(a>b)
    swap(a,b);
    
    if(b==INT_MAX)
    return a;
    
    if(b%a==0)
    return a;
    
    return GCD(b%a,a);
}

void updateSTree(ll *stree, int cs, int ce, int i,int new_val, int curr)
{
    if (cs == ce)
    {
        stree[curr] = new_val;
        return ;
    }
    
    int mid = getMid(cs, ce);
    
    if(i<=mid)
    updateSTree(stree, cs, mid,i,new_val,curr*2+1);
    else
    updateSTree(stree, mid+1, ce,i,new_val,curr*2+2);
    
    stree[curr] = GCD(stree[curr*2+1],stree[curr*2+2]);
}

ll getGCD(ll *stree, int cs, int ce, int qs, int qe, int curr)
{
    if (qs <= cs && qe >= ce)
    return stree[curr];
    
    if (ce < qs || cs > qe)
    return INT_MAX;
    
    int mid = getMid(cs, ce);
    
    return GCD(getGCD(stree, cs, mid, qs, qe, 2*curr+1) 
           ,getGCD(stree, mid+1, ce, qs, qe, 2*curr+2));
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
    
    stree[curr] = GCD(stree[curr*2+1],stree[curr*2+2]);
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
		
		int L,R,index,val,type;
		
		while(q--)
		{
		    
		    cin.ignore(INT_MAX, '\n');
		    cin>>type;
		    
		    if(type == 0)
		    {
		        cin>>L>>R;
		        
		        if(L>=0 and R<n and L<=R)
		        cout<<getGCD(stree, 0, n-1, L, R, 0)<<endl;
		        else
		        cout<<"-1"<<endl;
		    }
		    else
		    {
		        cin>>index>>val;
		        
		        if(index>=0 and index<n)
		        {
		            int old_val = arr[index];
		            arr[index] = val;
		            
		            updateSTree(stree, 0, n-1, index,val,0);
		        }
		    }
		}	
	}
	
	return 0;
}
