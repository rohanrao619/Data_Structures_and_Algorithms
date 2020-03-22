// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
int maxStep(int a[], int n){
    
   //Your code here
   int max=0,curr=0;
   for(int i=1;i<n;i++)
   {
       if(a[i]>a[i-1])
       {   
           curr++;
           if(curr>max)
           max=curr;
       }
       else
       {
           curr=0;
       }
   }
   return max;
}

// { Driver Code Starts.


int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    
	    cout << maxStep(a, n) << endl;
	}
	return 0;
}  // } Driver Code Ends
