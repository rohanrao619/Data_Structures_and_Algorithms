// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findIslands(vector<int> A[], int N, int M);

int main() {

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A[N];
        for (int i = 0; i < N; i++) {
            vector<int> temp(M);
            A[i] = temp;
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        cout << findIslands(A, N, M) << endl;
    }
    return 0;
}// } Driver Code Ends
/*you are required to complete this method*/

/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/
void DFS(int x,int y,vector<int> A[],bool **vis,int N,int M)
{
    vis[x][y] = true;
    
    for(int i=-1;i<=1;i++)
    for(int j=-1;j<=1;j++)
    {
        if((x+i)<N && (x+i)>=0 && (y+j)<M && (y+j)>=0)
        if(vis[x+i][y+j]==false && A[x+i][y+j]==1)
        DFS(x+i,y+j,A,vis,N,M);
    }
}

int findIslands(vector<int> A[], int N, int M) {

    // Your code here
    bool **vis;
    
    vis = new bool*[N];
    
    for(int i=0;i<N;i++)
    vis[i] = new bool[M];
    
    for(int i=0;i<N;i++)
    for(int j=0;j<M;j++)
    vis[i][j]=false;
    
    int count = 0;
    
    for(int i=0;i<N;i++)
    for(int j=0;j<M;j++)
    {
        if(vis[i][j]==false && A[i][j]==1)
        {
            DFS(i,j,A,vis,N,M);
            count++;
        }
    }
    
    return count;
}

