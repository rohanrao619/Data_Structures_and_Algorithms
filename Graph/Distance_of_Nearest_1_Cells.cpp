// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> arr, int row, int col) {

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
    }
    cout << endl;
}


 // } Driver Code Ends
/*  Function to find the distance of nearest cell having 1
*   arr: vector of vectors to represent graph
*   row, col: rows and cols in given matrix
*/
vector<pair<int,int>> moves{{0,1},{0,-1},{1,0},{-1,0}};

void nearest(vector<vector<int>> arr, int row, int col) {

    // Your code here

    /************
     * After completing the logic
     * Just call the print function
     * provided in the locked part
     * **********/
     bool vis[row][col];
     int curr_distance = 0;
     
     queue<pair<int,int>> Q;
     vector<vector<int>> res;
     
     for(int i=0;i<row;i++)
     {
        vector<int> temp(col,0);
        res.push_back(temp);
        
        for(int j=0;j<col;j++)
        {
            vis[i][j]=false;
            if(arr[i][j]==1)
            {
                Q.push({i,j});
                vis[i][j]=true;
            }
        }
     }
     
     while(!Q.empty())
	    {
	        int count = Q.size();
	        while(count--)
	        {
	            int x = Q.front().first;
	            int y = Q.front().second;
	            
	            res[x][y] = curr_distance;
	            
	            Q.pop();
	        
	            for(auto move:moves)
	            {
	                int i = x + move.first;
	                int j = y + move.second;
	            
	                if(i<row and j<col and i>=0 and j>=0)
	                if(vis[i][j]==false)
	                {
	                    Q.push({i,j});
	                    vis[i][j] = true;
	                }
	            } 
	        }
	        curr_distance++;
	    }

     print(res,row,col);
}

// { Driver Code Starts.

int main() {

    int tc;
    cin >> tc;
    while (tc--) {
        int row, col;
        cin >> row >> col;

        // Input matrix is represented using vectors of vectors
        vector<vector<int>> graph(row);

        for (int i = 0; i < row; i++) {
            vector<int> temp(col);
            graph[i] = temp;
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> graph[i][j];
            }
        }

        nearest(graph, row, col);
    }

    return 0;
}  // } Driver Code Ends
