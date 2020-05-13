#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int psum,ssum,tsum,msum;
    
    Node()
    {
        psum = ssum = tsum = msum = INT_MIN;
    }
};

void buildSTree(int arr[],Node stree[],int s,int e,int c)
{
    if(s==e)
    {
        stree[c].psum = stree[c].msum = stree[c].tsum = stree[c].ssum = arr[s];
        return;
    }
    
    int mid = s + (e-s)/2;
    
    buildSTree(arr,stree,s,mid,2*c+1);
    buildSTree(arr,stree,mid+1,e,2*c+2);
    
    Node left = stree[2*c+1];
    Node right = stree[2*c+2];
    
    stree[c].tsum = left.tsum+right.tsum;
    stree[c].psum = max(left.tsum+right.psum,left.psum);
    stree[c].ssum = max(right.ssum,left.ssum+right.tsum);
    stree[c].msum = max({stree[c].psum,stree[c].ssum,left.msum,right.msum,left.ssum + right.psum});
}

void updateSTree(Node stree[],int s,int e,int c,int i,int val)
{
    if(i<s or i>e)
    return;
    
    if(s==e)
    {
        stree[c].psum = stree[c].msum = stree[c].tsum = stree[c].ssum = val;
        return;
    }
    
    int mid = s + (e-s)/2;
    
    if(i<=mid)
    updateSTree(stree,s,mid,2*c+1,i,val);
    else
    updateSTree(stree,mid+1,e,2*c+2,i,val);
    
    Node left = stree[2*c+1];
    Node right = stree[2*c+2];
    
    stree[c].tsum = left.tsum+right.tsum;
    stree[c].psum = max(left.tsum+right.psum,left.psum);
    stree[c].ssum = max(right.ssum,left.ssum+right.tsum);
    stree[c].msum = max({stree[c].psum,stree[c].ssum,left.msum,right.msum,left.ssum + right.psum});
}

Node getMaxSum(Node stree[],int s,int e,int qs,int qe,int c)
{
    Node answer;
    
    if(s>=qs and e<=qe)
    return stree[c];
    
    if(s>qe or e<qs)
    return answer;
    
    int mid = s + (e-s)/2;
    
    if(qe<=mid)
    return getMaxSum(stree,s,mid,qs,qe,2*c+1);
    
    if(qs>mid)
    return getMaxSum(stree,mid+1,e,qs,qe,2*c+2);
    
    Node left = getMaxSum(stree,s,mid,qs,qe,2*c+1);
    Node right = getMaxSum(stree,mid+1,e,qs,qe,2*c+2);
    
    answer.tsum = left.tsum+right.tsum;
    answer.psum = max(left.tsum+right.psum,left.psum);
    answer.ssum = max(right.ssum,left.ssum+right.tsum);
    answer.msum = max({answer.psum,answer.ssum,left.msum,right.msum,left.ssum + right.psum});
    
    return answer;
}

int main()
 {
	//code
	int T;
	cin>>T;
	
	while(T--)
	{
	    int n,q,type,a,b;
	    cin>>n>>q;
	    
	    int arr[n];
	    Node *stree = new Node[4*n];
	    
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    
	    buildSTree(arr,stree,0,n-1,0);
	    
	    while(q--)
	    {
	        cin>>type>>a>>b;
	        
	        if(type==1)
	        {
	            Node ans = getMaxSum(stree,0,n-1,a-1,b-1,0);
	            cout<<ans.msum<<endl;
	        }
	        else
	        {
	            updateSTree(stree,0,n-1,0,a-1,b);
	        }
	    }
	}
	return 0;
}
