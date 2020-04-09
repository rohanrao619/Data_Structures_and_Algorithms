// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

stack<int>_push(int arr[],int n);

void _getMinAtPop(stack<int>s);

 // } Driver Code Ends
//User function Template for C++

/* inserts elements of the array into 
   stack and return the stack
*/

stack<int> minimum;

stack<int>_push(int arr[],int n)
{
   // your code here
   stack<int> stk;
   stk.push(arr[0]);
   
   minimum.push(arr[0]);
   
   for(int i=1;i<n;i++)
   {    
       if(arr[i]<=minimum.top())
       minimum.push(arr[i]);
       
       stk.push(arr[i]);
   }
   
   return stk;
}

/* print minimum element of the stack each time
   after popping
*/
void _getMinAtPop(stack<int>s)
{
    // your code here
    while(!s.empty())
    {
        cout<<minimum.top()<<" ";
        
        if(s.top()==minimum.top())
        minimum.pop();
        
        s.pop();
    }
}

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    stack<int>mys=_push(arr,n);
	    _getMinAtPop(mys);
	    cout<<endl;
	    
	    
	    
	}
	return 0;
}

  // } Driver Code Ends
