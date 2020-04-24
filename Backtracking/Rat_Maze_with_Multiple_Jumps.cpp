// { Driver Code Starts


#include <bits/stdc++.h>

using namespace std;

void print(int n, vector<int> sol[]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}

void solve(int n, vector<int> maze[]);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> maze[n];
        for (int i = 0; i < n; i++) {
            maze[i].assign(n, 0);
            for (int j = 0; j < n; j++) cin >> maze[i][j];
        }

        solve(n, maze);
    }
    return 0;
}
// } Driver Code Ends

bool isPossible(int n,int i,int j,vector<int> maze[],vector<int> result[])
{
    result[i][j]=1;
    
    if(i==(n-1) and j==(n-1))
    return true;
    
    if(maze[i][j]==0)
    {
       result[i][j]=0;
       return false;
    }
    
    for(int k=1;k<=maze[i][j];k++)
    {
        if((j+k)<n)
        {
            if(isPossible(n,i,j+k,maze,result))
            return true;
        }
        
        if((i+k)<n)
        {
            if(isPossible(n,i+k,j,maze,result))
            return true;
        }
    }
    
    result[i][j]=0;
    return false;
}

void solve(int n, vector<int> maze[]) {
    // write code here
    vector<int> result[n];
    
    for(int i=0;i<n;i++)
    {
        vector<int> temp(n,0);
        result[i] = temp;
    }
    
    if(maze[0][0]==0)
    {
        cout<<"-1"<<endl;
        return;
    }
    
    if(isPossible(n,0,0,maze,result))
    print(n,result);
    else
    cout<<"-1"<<endl;
    
}
