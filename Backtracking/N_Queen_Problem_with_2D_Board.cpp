#include<bits/stdc++.h>
using namespace std;
#define N 10

void printSolution(bool BOARD[N][N],int dim)
{
    cout<<"[";
    
    for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	if(BOARD[j][i]==true)
	cout<<j+1<<" ";
	
	cout<<"]";
}

bool isSafe(bool BOARD[N][N],int x,int y,int dim)
{
    for(int i=0;i<y;i++)
    if(BOARD[x][i]==true)
    return false;
    
    for(int p=x-1,q=y-1;p>=0 and q>=0;p--,q--)
    {
        if(BOARD[p][q]==true)
        return false;
    }
    
    for(int p=x+1,q=y-1;p<dim and q>=0;p++,q--)
    {
        if(BOARD[p][q]==true)
        return false;
    }
    
    return true;
}

void solveNQueen(bool BOARD[N][N],int pos,int dim)
{
    if(pos==dim)
    {
        printSolution(BOARD,dim);
        cout<<" ";
    }
    
    for(int i=0;i<dim;i++)
    {
        BOARD[i][pos]=true;
        
        if(isSafe(BOARD,i,pos,dim))
        solveNQueen(BOARD,pos+1,dim);
        
        BOARD[i][pos]=false;
    }
    
}

int main()
 {
	//code
	
	bool BOARD[N][N];
	
	int T;
	cin>>T;
	
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	BOARD[i][j]=false;
	
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
