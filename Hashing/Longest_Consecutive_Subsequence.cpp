// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int n);
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  cout<<findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}// } Driver Code Ends
int findLongestConseqSubseq(int arr[], int n)
{
  //Your code here
  unordered_set<int> s;
  for(int i=0;i<n;i++)
  s.insert(arr[i]);
  
  int max=1,curr,count;
  
  for(int i=0;i<n;i++)
  {
      if(s.count(arr[i]-1)==1)
      continue;
      
      count=1;
      curr=arr[i]+1;
      while(s.count(curr)!=0)
      {
          count++;
          curr++;
          if(count>max)
          max=count;
      }
  }
  
  return max;
  
}
