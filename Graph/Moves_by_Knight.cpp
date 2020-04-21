#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int T;
	cin>>T;
	
	vector<pair<int,int>> moves{{-2,-1},{-1,-2},{1,-2},{2,-1},{1,2},{2,1},{-1,2},{-2,1}};
	
	while(T--)
	{
	    int n;
	    cin>>n;
	    
	    pair<int,int> s,d;
	    cin>>s.first>>s.second;
	    cin>>d.first>>d.second;
	    
	    s = {s.first-1,s.second-1};
	    d = {d.first-1,d.second-1};
	    
	    bool vis[n][n];
	    
	    for(int i=0;i<n;i++)
	    for(int j=0;j<n;j++)
	    vis[i][j]=false;
	    
	    queue<pair<int,int>> Q;
	    Q.push(s);
	    vis[s.first][s.second]=true;
	    int count=0,flag=0;
	    
	    while(!Q.empty() && flag==0)
	    {
	        int c=Q.size();
	        while(c--)
	        {
	            pair<int,int> curr = Q.front();
	            Q.pop();
	            
	            vis[curr.first][curr.second]=true;
	            
	            if(curr==d)
	            {
	                flag=1;
	                break;
	            }
	            else
	            for(auto move:moves)
	            {
	                int x = curr.first + move.first;
	                int y = curr.second + move.second;
	                
	                if(x<n and y<n and x>=0 and y>=0 and vis[x][y]==false)
	                Q.push({x,y});
	            }
	        }
	        count++;
	    }
	    cout<<count-1<<endl;
	}
	return 0;
}
