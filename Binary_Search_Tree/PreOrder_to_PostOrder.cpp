#include<bits/stdc++.h>
using namespace std;

void printPostOrder(int pre[],unordered_map<int,int> in,int start,int end,int &curr,int n)
{
    if(start>end || curr>=n)
    return;
    
    int data = pre[curr];
    int pos = in[data];
    curr++;
    
    printPostOrder(pre,in,start,pos-1,curr,n);
    printPostOrder(pre,in,pos+1,end,curr,n);
    
    cout<<data<<" ";
    
}

int main()
 {
    
	int T;
	cin>>T;
	while(T--)
	{
	    int n,curr=0;
	    cin>>n;
	    
	    unordered_map<int,int> in;
	    
	    int pre[n],inOrder[n];
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>pre[i];
	        inOrder[i] = pre[i];
	    }
	    
	    sort(inOrder,inOrder+n);
	    
	    for(int i=0;i<n;i++)
	    {
	        in[inOrder[i]]=i;
	    }
	    
	    printPostOrder(pre,in,0,n-1,curr,n);
	    cout<<endl;
	    
	}
	
	return 0;
}
