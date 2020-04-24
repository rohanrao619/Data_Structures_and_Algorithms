// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  

bool SolveSudoku(int grid[N][N]);

void printGrid(int grid[N][N]);

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		
		if (SolveSudoku(grid) == true)  
            printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}// } Driver Code Ends
 
bool isSafe(int grid[N][N],int i,int j)
{
    int size = sqrt(N);
    int num = grid[i][j];
    
    int x = int(i/size)*size;
    int y = int(j/size)*size;
    
    for(int p=0;p<N;p++)
    {
        if(grid[p][j]==num and p!=i)
        return false;
        
        if(grid[i][p]==num and p!=j)
        return false;
    }
    
    for(int p=x;p<(x+size);p++)
    for(int q=y;q<(y+size);q++)
    {
        if(grid[p][q]==num and p!=i and q!=j)
        return false;
    }
    
    return true;
    
}

bool SolveSudoku(int grid[N][N]) 
{ 
    // Your code here
    int i,j,k,flag=0;
    
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        if(grid[i][j]==0)
        {
            flag = 1;
            break;
        }
        
        if(flag==1)
        break;
    }
    
    if(flag==0)
    return true;
    
    for(k=1;k<=N;k++)
    {
        grid[i][j] = k;
        
        if(isSafe(grid,i,j))
        {
            if(SolveSudoku(grid))
            return true;
        }
        
        grid[i][j] = 0;
    }
    
    return false;
}

void printGrid (int grid[N][N]) 
{
    // Your code here 
    for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
    cout<<grid[i][j]<<" ";
}

