#include<iostream>
using namespace std;

struct Node
{
    int l,r,result;
    
    Node()
    {
        l = r = result = 0;
    }
};

void buildSTree(string S,Node stree[],int curr,int start, int end)
{
    if(start==end)
    {
        if(S[start]=='(')
        stree[curr].l++;
        else
        stree[curr].r++;
        
        return;
    }
    
    int mid = start + (end-start)/2;
    
    buildSTree(S,stree,2*curr+1,start,mid);
    buildSTree(S,stree,2*curr+2,mid+1,end);
    
    int pairs = min(stree[2*curr+1].l,stree[2*curr+2].r);
    
    stree[curr].l = stree[2*curr+1].l + stree[2*curr+2].l - pairs;
    stree[curr].r = stree[2*curr+1].r + stree[2*curr+2].r - pairs;
    stree[curr].result = stree[2*curr+1].result + stree[2*curr+2].result + 2*pairs;
}

Node getPairs(Node stree[], int cs, int ce, int qs, int qe, int curr)
{
    if (qs <= cs && qe >= ce)
    return stree[curr];
    
    Node res;
    
    if (ce < qs || cs > qe)
    return res;
    
    int mid = cs + (ce-cs)/2;
    
    Node left = getPairs(stree, cs, mid, qs, qe, 2*curr+1);
    Node right = getPairs(stree, mid+1, ce, qs, qe, 2*curr+2);
    
    int pairs = min(left.l,right.r);
    res.result = left.result+right.result+2*pairs;
    res.l = left.l+right.l-pairs;
    res.r = right.r+left.r-pairs;
    
    return res;
}

int main()
 {
	//code
	int T;
	cin>>T;
	
	while(T--)
	{
	    string S;
	    cin>>S;
	    
	    int q,l,r;
	    cin>>q;
	    
	    Node *stree = new Node[4*S.length()];
	    
	    buildSTree(S,stree,0,0,S.length()-1);
	    
	    while(q--)
	    {
	        cin>>l>>r;
	        cout<<getPairs(stree,0,S.length()-1,l,r,0).result<<endl;
	    }
	}
	return 0;
}
