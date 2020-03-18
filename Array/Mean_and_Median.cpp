// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

int median(int A[],int N)
{
    
    sort(A,A+N);
    
    //your code here
    //If median is in fraction then convert it to integer and return
    
    if(N%2==1)
    return A[int(N/2)];
    else
    return int((A[(N/2)-1]+A[N/2])/2);
}

int mean(int A[],int N)
{
    int sum = 0;
    //your code here
    for(int i=0;i<N;i++)
    sum+=A[i];
    
    return int(sum/N);
}


// { Driver Code Starts.

int main()
{
    //testcase
    int T;
    cin>>T;
   
    //looping testcase
    while(T--)
    {
        //number of elements in array
        int N;
        cin>>N;
        int a[N];
        for(int i=0;i<N;i++){
            cin>>a[i];
        }
        cout<<mean(a,N)<<" "<<median(a,N)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
