#include<bits/stdc++.h>
using namespace std;
#define N 11

void printSolution(int BOARD[N],int dim)
{
    cout<<"[";
    
    for(int i=0;i<dim;i++)
	cout<<BOARD[i]+1<<" ";
	
	cout<<"]";
}

bool isSafe(int BOARD[N],int x,int y,int dim)
{
    for(int i=0;i<y;i++)
    if(BOARD[i]==x)
    return false;
    
    for(int p=x-1,q=y-1;p>=0 and q>=0;p--,q--)
    {
        if(BOARD[q]==p)
        return false;
    }
    
    for(int p=x+1,q=y-1;p<dim and q>=0;p++,q--)
    {
        if(BOARD[q]==p)
        return false;
    }
    
    return true;
}

void solveNQueen(int BOARD[N],int pos,int dim)
{
    if(pos==dim)
    {
        printSolution(BOARD,dim);
        cout<<" ";
    }
    
    for(int i=0;i<dim;i++)
    {
        BOARD[pos]=i;
        
        if(isSafe(BOARD,i,pos,dim))
        solveNQueen(BOARD,pos+1,dim);
    }
}

int main()
 {
	//code
	
	int BOARD[N];
	
	int T;
	cin>>T;
	
	for(int i=0;i<N;i++)
	BOARD[i]=-1;
	
	while(T--)
	{
	    int dim;
	    cin>>dim;
	    
	    if(dim<4)
	    {
	        if(dim==1)
	        cout<<"[1 ]";
	        else
	        cout<<"-1";
	    }
	    else
	    solveNQueen(BOARD,0,dim);
	    
	    cout<<endl;
	}
	
	return 0;
}
