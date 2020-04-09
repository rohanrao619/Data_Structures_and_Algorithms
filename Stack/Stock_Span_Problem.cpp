// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to calculate span
// price[]: price array in input
// n: size of array
void calculateSpan(int price[], int n, int S[])
{
   // Your code here
   stack<int> span;
   span.push(0);
   
   S[0]=1;
   
   for(int i=1;i<n;i++)
   {
       if(price[i]<price[span.top()])
       S[i]=1;
       
       else
       {
           while(!span.empty() && price[i]>=price[span.top()])
           span.pop();
           
           S[i]= (span.empty()?(i+1):(i-span.top()));
       }
       
       span.push(i);
   }
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n],s[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		
		calculateSpan(a, n, s);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends
