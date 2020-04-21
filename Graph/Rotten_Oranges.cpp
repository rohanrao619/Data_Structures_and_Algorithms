#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int T;
	cin>>T;
	
	vector<pair<int,int>> moves{{0,1},{0,-1},{1,0},{-1,0}};
	
	while(T--)
	{
	    int r,c;
	    cin>>r>>c;
	    int arr[r][c],count=0,tcount=0,seconds=-1;
	    bool vis[r][c];
	    
	    queue<pair<int,int>> Q;
	    
	    for(int i=0;i<r;i++)
	    for(int j=0;j<c;j++)
	    {
	        cin>>arr[i][j];
	        vis[i][j]=false;
	        
	        if(arr[i][j]==2)
	        {
	            Q.push({i,j});
	            vis[i][j]=true;
	            count++;
	        }
	        
	        if(arr[i][j]!=0)
	        tcount++;
	    }
	    
	    while(!Q.empty())
	    {
	        int s = Q.size();
	        while(s--)
	        {
	            int x = Q.front().first;
	            int y = Q.front().second;
	        
	            Q.pop();
	        
	            for(auto move:moves)
	            {
	                int i = x + move.first;
	                int j = y + move.second;
	            
	                if(i<r and j<c and i>=0 and j>=0)
	                if(arr[i][j]==1 and vis[i][j]==false)
	                {
	                    Q.push({i,j});
	                    count++;
	                    vis[i][j] = true;
	                }
	            } 
	        }
	        seconds++;
	    }
	    
	    if(count!=tcount)
	    seconds = -1;
	    
	    cout<<seconds<<endl;
	}
	return 0;
}
