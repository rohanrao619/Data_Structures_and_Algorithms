// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

// function to find the triplet which sum to x
bool find3Numbers(int A[], int arr_size, int x)
{
    //Your code here
    sort(A,A+arr_size);
    int i,l,r,sum;
    
    for(i=0;i<arr_size-2;i++)
    {
        l=i+1;
        r=arr_size-1;
        while(l<r)
        {
            sum =(A[i]+A[l]+A[r]);
            if(sum==x)
            {
                return 1;
            }
            else if(sum<x)
            l++;
            else
            r--;
        }
        
    }
    return 0;
}


// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,sum;
		cin>>N>>sum;
		int i,A[N];
		for(i=0;i<N;i++)
			cin>>A[i];
        cout <<  find3Numbers(A, N, sum) << endl;
    }
}
  // } Driver Code Ends
