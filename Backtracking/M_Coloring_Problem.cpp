// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

bool isSafe(bool graph[101][101],int colorGraph[101],int i,int V)
{
    int color = colorGraph[i];
    
    for(int j=0;j<V;j++)
    {
        if(graph[i][j]==true and colorGraph[j]==color)
        return false;
    }
    
    return true;
}

bool isPossible(bool graph[101][101],int colorGraph[101],int M,int V)
{
    int flag = 0,i,j;
    
    for(i=0;i<V;i++)
    {
    for(j=0;j<i;j++)
    {
        if(graph[i][j]==true and (colorGraph[i]==-1 || colorGraph[j]==-1))
        {
            flag = 1;
            break;
        }
    }
    
    if(flag==1)
    break;
    }
    
    if(flag==0)
    return true;
    
    if(colorGraph[i]!=-1)
    i = j;
    
    for(int k=1;k<=M;k++)
    {
        colorGraph[i]=k;
        
        if(isSafe(graph,colorGraph,i,V))
        {
            if(isPossible(graph,colorGraph,M,V))
            return true;
        }
        
        colorGraph[i]=-1;
    }
    
    return false;
}

bool graphColoring(bool graph[101][101], int M,int V)
{
    // your code here
    int colorGraph[101];
    
    for(int i=0;i<V;i++)
    colorGraph[i] = -1;
    
    return isPossible(graph,colorGraph,M,V);
}

// { Driver Code Starts.
 
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,m,e;
    cin>>n>>m>>e;
    int i;
    bool graph[101][101];
    for(i=0;i<n;i++)
      {
        memset(graph[i],0,sizeof(graph[i]));
      }
    for(i=0;i<e;i++)
    {
      int a,b;
      cin>>a>>b;
      graph[a-1][b-1]=1;
      graph[b-1][a-1]=1;
    }
    cout<<graphColoring (graph, m,n)<<endl;
  }
    return 0;
}

  // } Driver Code Ends
